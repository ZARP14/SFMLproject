#include "platform.hpp"

Platform::Platform() :
    PlatformRectangle(0, 0, 72, 47)
{
    SpriteTexture.loadFromFile(Pprogram.TEXTURE_PATH + "Stone.png");
    Sprite.setTexture(SpriteTexture);
}