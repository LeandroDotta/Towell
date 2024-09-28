#ifndef TOWELL_ASSET_MANAGER_H
#define TOWELL_ASSET_MANAGER_H

#include <rendering/Texture.h>

namespace Towell::Assets
{
	bool Init(std::string assetsRootDirectory);
	void Shutdown();

	class Texture* GetTexture(std::string textureFileName);
}

#endif // TOWELL_ASSET_MANAGER_H

