#include "backimage.hpp"


BackImage::BackImage() :
    BackImageRectangle(0, 0, 800, 449)
{
    BackImageSprite.setTextureRect(BackImageRectangle);
    BackImageTexture.loadFromFile(Bprogram.TEXTURE_PATH + "BackImage.png");
    BackImageSprite.setTexture(BackImageTexture);
}