#pragma once
#include "IImageReader.h"

class PBMImageReader : public IImageReader
{
public:
	Image readImage(const String& fileName) const override;
};