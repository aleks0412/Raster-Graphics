#include "BlackAndWhiteTransform.h"

void BlackAndWhiteTransform::transformImage(Image& image) const
{
    int imageWidth = image.getWidth();
    int imageHeight = image.getHeight();
    for (int y = 0; y < imageHeight; y++)
    {
        for (int x = 0; x < imageWidth; x++)
        {
            ColorRGB currentColor = image.getPixel(x, y);
            if(currentColor.getValue() > ColorRGB::MAX_RGB_VALUE / 2)
            {
                currentColor.setRed(ColorRGB::MAX_RGB_VALUE);
                currentColor.setGreen(ColorRGB::MAX_RGB_VALUE);
                currentColor.setBlue(ColorRGB::MAX_RGB_VALUE);
            }
            else
            {
                currentColor.setRed(0);
                currentColor.setGreen(0);
                currentColor.setBlue(0);
            }
            image.setPixel(x, y, currentColor);
        }
    }
}

ITransform* BlackAndWhiteTransform::clone() const
{
    return new BlackAndWhiteTransform();
}