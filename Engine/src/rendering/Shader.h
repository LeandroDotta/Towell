#ifndef TOWELL_SHADER_H
#define TOWELL_SHADER_H

#include <string>
#include <GL/glew.h>
#include <math/Matrix4.h>

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



