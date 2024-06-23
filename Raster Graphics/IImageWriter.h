#pragma once
#include "Image.h"
#include "String.h"

class IImageWriter
{
public:
    virtual void writeImage(const String& fileName, const Image& image) const = 0;
};