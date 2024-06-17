#include "Image.h"

Image::Image(int width, int height) : width(width), height(height), pixels(width * height)
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