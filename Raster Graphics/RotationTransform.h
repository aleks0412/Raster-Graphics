#pragma once
#include "ITransform.h"

class RotationTransform : public ITransform
{
protected:
    void transposeImage(Image& image) const;
    void mirrorImage(Image& image) const;
};