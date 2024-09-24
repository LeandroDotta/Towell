#ifndef TOWELL_TEXTURE_H
#define TOWELL_TEXTURE_H

#include <string>

namespace Towell
{
	class Texture
	{
	public:
		Texture();
		~Texture();

		bool Load(const std::string& fileName);
		void Unload();

		void SetActive();

		int GetWidth() const { return width; }
		int GetHeight() const { return height; }
	private:
		unsigned int textureID;

		int width;
		int height;
	};
}

#endif // TOWELL_TEXTURE_H

