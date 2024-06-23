#pragma once
#include "Image.h"
#include "String.h"

class IImageReader
{
public:
    virtual Image readImage(const String& fileName) const = 0;
};