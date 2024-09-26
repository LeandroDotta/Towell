#include "Renderer.h"
#include "gl/glew.h"
#include <filesystem>
#include <Log.h>
#include "window/SDLWindow.h"

using namespace Towell;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	delete spriteVertices;
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
	glGetError();

	if (!LoadShaders())
	{
		TW_ERROR("Failed to load shaders.");
		return false;
	}

	CreateSpriteVerts();

	return true;
}

void Renderer::RenderFrame()
{
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Enable alpha blending on the color buffer
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	spriteShader->SetActive();
	spriteVertices->SetActive();

	for (auto sprite : this->sprites)
	{
		sprite->Draw(spriteShader);
	}

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

bool Renderer::LoadShaders()
{
	spriteShader = new Shader();

	if (!spriteShader->Load("../Shaders/Sprite.vert", "../Shaders/Sprite.frag"))
	{
		return false;
	}

	spriteShader->SetActive();

	Matrix4 viewProjection = Matrix4::CreateViewProjection(
		static_cast<float>(window->GetWidth()), 
		static_cast<float>(window->GetHeight())
	);
	spriteShader->SetMatrixUniform("uViewProj", viewProjection);

	return true;
}

void Renderer::CreateSpriteVerts()
{
	float vertices[] = {
		-0.5f,  0.5f, 0.f, 0.f, 0.f, // top left
		 0.5f,  0.5f, 0.f, 1.f, 0.f, // top right
		 0.5f, -0.5f, 0.f, 1.f, 1.f, // bottom right
		-0.5f, -0.5f, 0.f, 0.f, 1.f  // bottom left
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	spriteVertices = new VertexArray(vertices, 4, indices, 6);
}
