#include "Shader.h"
#include <fstream>
#include <sstream>
#include <Log.h>

using namespace Towell;

Shader::Shader()
{
}

Shader::~Shader()
{
}

bool Shader::Load(const std::string& vertexShaderName, const std::string& fragmentShaderName)
{
	if (!CompileShader(vertexShaderName, GL_VERTEX_SHADER, vertexShader) || !CompileShader(fragmentShaderName, GL_FRAGMENT_SHADER, fragShader))
	{
		return false;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	if (!IsValidProgram())
	{
		return false;
	}

	return true;
}

void Shader::Unload()
{
	glDeleteProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);
}

void Shader::SetActive()
{
	glUseProgram(shaderProgram);
}

void Shader::SetMatrixUniform(const char* name, const Matrix4& matrix)
{
	// Find the uniform by this name
	GLuint loc = glGetUniformLocation(shaderProgram, name);

	// Send the matrix data to the uniform
	glUniformMatrix4fv(loc, 1, GL_TRUE, matrix.GetAsFloatPtr());
}

void Shader::SetColorUniform(const char* name, const Color& color)
{
	SetVector4Uniform(name, color.ToFloatArray());
}

void Shader::SetVector4Uniform(const char* name, float* vector)
{
	GLuint loc = glGetUniformLocation(shaderProgram, name);

	glUniform4fv(loc, 1, vector);
}

bool Shader::CompileShader(const std::string& fileName, GLenum shaderType, GLuint& outShader)
{
	std::ifstream shaderFile(fileName);

	if (shaderFile.is_open())
	{
		// Read all the text into a string
		std::stringstream sstream;
		sstream << shaderFile.rdbuf();
		std::string contents = sstream.str();
		const char* contentsChar = contents.c_str();

		// Create a shader of the specified type
		outShader = glCreateShader(shaderType);

		// Set the source characters and try to compile
		glShaderSource(outShader, 1, &(contentsChar), nullptr);
		glCompileShader(outShader);

		if (!IsCompiled(outShader))
		{
			TW_ERROR("Failed to compile shader %s", fileName.c_str());
			return false;
		}
	}
	else
	{
		TW_ERROR("Shader file not found: %s", fileName.c_str());
		return false;
	}

	return true;
}

bool Shader::IsCompiled(GLuint shader)
{
	GLint status;

	// Query the compile status
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetShaderInfoLog(shader, 511, nullptr, buffer);
		TW_ERROR("GLSL Compile Failed:\n%s", buffer);
		return false;
	}

	return true;
}

bool Shader::IsValidProgram()
{
	GLint status;

	// Query the compile status
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);

	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetProgramInfoLog(shaderProgram, 511, nullptr, buffer);
		TW_ERROR("GLSL Link Status:\n%s", buffer);
		return false;
	}

	return true;
}
