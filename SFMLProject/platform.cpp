#include "platform.hpp"

Platform::Platform() :
    PlatformRectangle(0, 0, 72, 47)
{
    PlatformTexture.loadFromFile(Pprogram.TEXTURE_PATH + "Stone.png");
    PlatformSprite.setTexture(PlatformTexture);
}