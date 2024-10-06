#include "Renderer.h"

#include <filesystem>
#include "gl/glew.h"
#include <Log.h>
#include "QuadMesh.h"
#include "TriangleMesh.h"
#include "window/SDLWindow.h"
#include "scene/Transform.h"

using namespace Towell;

static void glCheckError(const char* file, int line)
{
	GLenum code;
	while ((code = glGetError()) != GL_NO_ERROR)
	{
		std::string error;

		switch (code)
		{
		case GL_INVALID_ENUM:
			error = "Invalid Enum";
			break;
		case GL_INVALID_VALUE:
			error = "Invalid Value";
			break;
		case GL_INVALID_OPERATION:
			error = "Invalid Operation";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			error = "Invalid Framebuffer Operation";
			break;
		case GL_OUT_OF_MEMORY:
			error = "Out of Memory";
			break;
		case GL_STACK_UNDERFLOW:
			error = "Stack Underflow";
			break;
		case GL_STACK_OVERFLOW:
			error = "Stack Overflow";
			break;
		}

		TW_ERROR("OpenGL Error: %s (%d) | %s:%d", error.c_str(), code, file, line);
	}
}

#define GL_CHECK_ERROR() glCheckError(__FILE__, __LINE__);

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	delete meshQuad;
	delete meshTriangle;
	spriteShader->Unload();
	delete spriteShader;
	SDL_GL_DeleteContext(context);
	delete window;
	SDL_Quit();
}

bool Renderer::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		TW_ERROR("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// Setup OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	// Create the window
	window = new SDLWindow("Towell Engine", 1024, 786);
	context = window->CreateOpenGLContext();
	
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	int glewStatus = glewInit();
	if (glewStatus != GLEW_OK)
	{
		TW_ERROR("Failed to initialize GLEW with status %d.", glewStatus);
		return false;
	}

	// On some platforms, GLEW will emit a benign error code, so clear it
	GL_CHECK_ERROR();

	if (!LoadShaders())
	{
		TW_ERROR("Failed to load shaders.");
		return false;
	}

	meshTriangle = new TriangleMesh();
	meshQuad = new QuadMesh();
	
	return true;
}

void Renderer::RenderFrame()
{
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Enable alpha blending on the color buffer
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	DrawSprites();
	DrawShapes();

	window->Update();
}

void Renderer::AddSprite(SpriteRenderer* sprite)
{
	int drawOrder = sprite->GetDrawOrder();
	auto iterator = sprites.begin();
	for (; iterator != sprites.end(); ++iterator)
	{
		if (drawOrder < (*iterator)->GetDrawOrder())
		{
			break;
		}
	}

	sprites.insert(iterator, sprite);
}

void Renderer::RemoveSprite(SpriteRenderer* sprite)
{
	auto iterator = std::find(sprites.begin(), sprites.end(), sprite);
	sprites.erase(iterator);
}

void Renderer::AddShape(ShapeRenderer* shape)
{
	int drawOrder = shape->GetDrawOrder();

	auto iterator = shapes.begin();
	for (; iterator != shapes.end(); ++iterator)
	{
		if (drawOrder < (*iterator)->GetDrawOrder())
		{
			break;
		}
	}

	shapes.insert(iterator, shape);
}

void Renderer::RemoveShape(ShapeRenderer* shape)
{
	auto iterator = std::find(shapes.begin(), shapes.end(), shape);
	shapes.erase(iterator);
}

bool Renderer::LoadShaders()
{
	spriteShader = new Shader();

	if (!spriteShader->Load(SHADERS_PATH "/Sprite.vert", SHADERS_PATH "/Sprite.frag"))
	{
		return false;
	}

	spriteShader->SetActive();

	Matrix4 viewProjection = Matrix4::CreateViewProjection(
		static_cast<float>(window->GetWidth()), 
		static_cast<float>(window->GetHeight())
	);
	spriteShader->SetMatrixUniform("uViewProj", viewProjection);

	shapeShader = new Shader();

	if (!shapeShader->Load(SHADERS_PATH "/Shape.vert", SHADERS_PATH "/Shape.frag"))
	{
		return false;
	}

	shapeShader->SetActive();
	shapeShader->SetMatrixUniform("uViewProj", viewProjection);

	return true;
}

void Renderer::DrawSprites()
{
	meshQuad->SetActive();
	spriteShader->SetActive();

	for (auto sprite : this->sprites)
	{
		sprite->Draw(spriteShader, meshQuad);
	}
}

void Renderer::DrawShapes()
{
	shapeShader->SetActive();
	
	Mesh* currentMesh = nullptr;
	
	for (auto shape : shapes)
	{
		switch (shape->GetType())
		{
		case ShapeRenderer::Shape::Triangle:
			currentMesh = meshTriangle;
			break;
		case ShapeRenderer::Shape::Quad:
			currentMesh = meshQuad;
			break;
		}

		currentMesh->SetActive();
		shape->Draw(shapeShader, currentMesh);
	}
}
