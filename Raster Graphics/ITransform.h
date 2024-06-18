#pragma once
#include "Image.h"

class ITransform
{
    virtual void transformImage(Image& image) const = 0;
};