#pragma once
#include "IImageReader.h"

class PPMImageReader : public IImageReader
{
public:
    Image readImage(const String& fileName) const override;
};