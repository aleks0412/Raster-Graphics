#include "NegativeTransform.h"

void NegativeTransform::transformImage(Image& image) const
{
    for (int y = 0; y < image.getHeight(); y++)
    {
        for (int x = 0; x < image.getWidth(); x++)
        {
            ColorRGB currentColor = image.getPixel(x, y);
            currentColor.invert();
            image.setPixel(x, y, currentColor);
        }
    }
}

ITransform* NegativeTransform::clone() const
{
    return new NegativeTransform();
}