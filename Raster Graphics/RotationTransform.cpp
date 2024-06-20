#include "RotationTransform.h"
#include "Vector.hpp"

void RotationTransform::transposeImage(Image& image) const
{
	int newHeight = image.getWidth();
	int newWidth = image.getHeight();
    Vector<ColorRGB> transposedPixels(newWidth * newHeight);
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            transposedPixels[x * newHeight + y] = image.getPixel(y, x);
        }
    }
    image.setWidth(newWidth);
    image.setHeight(newHeight);
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            image.setPixel(x, y, transposedPixels[x * newHeight + y]);
        }
    }
}

void RotationTransform::mirrorImage(Image& image) const
{
    int imageHeight = image.getHeight();
    int imageWidth = image.getWidth();
    for (int y = 0; y < imageHeight; y++)
    {   
        for (int x = 0; x < imageWidth / 2; x++)
        {
            ColorRGB temp = image.getPixel(x, y);
            image.setPixel(x, y, image.getPixel(image.getWidth() - 1 - x, y));
            image.setPixel(image.getWidth() - 1 - x, y, temp);
        }
    }
}