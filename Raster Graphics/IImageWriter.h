#pragma once
#include "Image.h"

class IImageWriter
{
public:
    virtual void writeImage(const char* fileName, const Image& image) const = 0;
};