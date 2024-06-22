#pragma once
#include "Image.h"

class ITransform
{
public:
    virtual void transformImage(Image& image) const = 0;
    virtual ITransform* clone() const = 0;
};