#include "DesaturateTransform.h"

void DesaturateTransform::transformImage(Image& image) const
{
    int imageWidth = image.getWidth();
    int imageHeight = image.getHeight();
    for (int y = 0; y < imageHeight; y++)
    {
        for (int x = 0; x < imageWidth; x++)
        {
            ColorRGB currentColor = image.getPixel(x, y);
            currentColor.desaturate();
            image.setPixel(x, y, currentColor);
        }
    }
}