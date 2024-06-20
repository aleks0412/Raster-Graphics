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
            if(currentColor.getValue() > 255 / 2)
            {
                currentColor.setRed(255);
                currentColor.setGreen(255);
                currentColor.setBlue(255);
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