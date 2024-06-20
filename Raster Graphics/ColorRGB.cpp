#include "ColorRGB.h"
#include "utils.hpp"

ColorRGB::ColorRGB(int red, int green, int blue) : red(red), green(green), blue(blue)
{
}

int ColorRGB::getRed() const
{
    return this->red;
}

int ColorRGB::getGreen() const
{
    return this->green;
}

int ColorRGB::getBlue() const
{
    return this->blue;
}

int ColorRGB::getValue() const
{
    return utils::max(utils::max(this->red, this->green), this->blue);
}

void ColorRGB::setRed(int red)
{
    this->red = red;
}

void ColorRGB::setGreen(int green)
{
    this->green = green;
}

void ColorRGB::setBlue(int blue)
{
    this->blue = blue;
}

void ColorRGB::desaturate()
{
    this->red = this->green = this->blue = getValue();
}