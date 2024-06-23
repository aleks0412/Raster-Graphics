#pragma once
#include "ColorRGB.h"
#include "ImageType.h"
#include "String.h"
#include "Vector.hpp"

class Image
{
public:
	Image() = default;
	Image(int width, int height, ImageType imageType, const String& fileName);

	ColorRGB getPixel(int x, int y) const;
	void setPixel(int x, int y, ColorRGB color);

	int getWidth() const;
	int getHeight() const;

	ImageType getImageType() const;
	String getFileName() const;
	void setWidth(int width);
	void setHeight(int height);
	void setImageType(ImageType imageType);
	void setFileName(const String& fileName);

private:
	Vector<ColorRGB> pixels;
	int width = 0;
	int height = 0;
	ImageType imageType = ImageType::PPM_ASCII;
	String fileName;
};