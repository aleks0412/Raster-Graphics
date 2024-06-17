#pragma once
#include "Image.h"

class IImageReader
{
public:
    virtual Image readImage(const char* fileName) const = 0;
};