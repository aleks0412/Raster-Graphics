#include "Image.h"

Image::Image(int width, int height, ImageType imageType, const String& fileName) : width(width), height(height), imageType(imageType), fileName(fileName), pixels(width * height)
{
}

ColorRGB Image::getPixel(int x, int y) const
{
    return this->pixels[y * this->width + x];
}

void Image::setPixel(int x, int y, ColorRGB color)
{
    this->pixels[y * this->width + x] = color;
}

int Image::getWidth() const
{
    return this->width;
}

int Image::getHeight() const
{
    return this->height;
}

void Image::setWidth(int width)
{
    this->width = width;
}

void Image::setHeight(int height)
{
    this->height = height;
}