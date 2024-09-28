#include "Assets.h"
#include <unordered_map>
#include <Log.h>

using namespace Towell;

static std::string assetsRootDirectory;
static std::unordered_map<std::string, class Texture*> textures;

bool Assets::Init(std::string assetsDirectory)
{
    assetsRootDirectory = assetsDirectory;
    TW_INFO("Starting Asset Library. Assets folder: %s", assetsDirectory);
    return true;
}

void Assets::Shutdown()
{
    for (auto iterator = textures.begin(); iterator != textures.end();)
    {
        iterator->second->Unload();
        iterator = textures.erase(iterator);
    }
}

Texture* Assets::GetTexture(std::string textureFileName)
{
    Texture* tex = nullptr;

    auto iterator = textures.find(textureFileName);

    if (iterator != textures.end())
    {
        tex = iterator->second;
    }
    else
    {
        tex = new Texture();
        std::string fileName = assetsRootDirectory + "/" + textureFileName;
        if (tex->Load(fileName))
        {
            textures.emplace(textureFileName, tex);
        }
        else
        {
            delete tex;
            tex = nullptr;
        }
    }

    return tex;
}
