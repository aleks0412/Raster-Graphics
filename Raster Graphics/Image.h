#pragma once
#include "ColorRGB.h"
#include "Vector.hpp"

class Image
{
public:
	Image() = default;
	Image(int width, int height);
	ColorRGB getPixel(int x, int y) const;
	void setPixel(int x, int y, ColorRGB color);
	int getWidth() const;
	int getHeight() const;
private:
	Vector<ColorRGB> pixels;
	int width = 0;
	int height = 0;
};