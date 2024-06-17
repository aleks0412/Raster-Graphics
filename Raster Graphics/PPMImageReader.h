#pragma once
#include "IImageReader.h"

class PPMImageReader : public IImageReader
{
public:
    Image readImage(const char* fileName) const override;
};