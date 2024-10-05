#ifndef TOWELL_SHADER_H
#define TOWELL_SHADER_H

#include <string>
#include <GL/glew.h>
#include <math/Matrix4.h>
#include "Color.h"

namespace Towell
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		bool Load(const std::string& vertexShaderName, const std::string& fragmentShaderName);
		void Unload();

		void SetActive();

		void SetMatrixUniform(const char* name, const Matrix4& matrix);
		void SetColorUniform(const char* name, const Color& color);
		void SetVector4Uniform(const char* name, float* vector);

	private:
		GLuint vertexShader;
		GLuint fragShader;
		GLuint shaderProgram;
		
		bool CompileShader(const std::string& fileName, GLenum shaderType, GLuint& outShader);
		bool IsCompiled(GLuint shader);
		bool IsValidProgram();		
	};
}

#endif // TOWELL_SHADER_H



