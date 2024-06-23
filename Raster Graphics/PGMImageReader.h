#pragma once
#include "IImageReader.h"
class PGMImageReader : public IImageReader
{
public:
	Image readImage(const String& fileName) const override;
};