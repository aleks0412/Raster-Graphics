#pragma once
#include "RotationTransform.h"

class ClockwiseRotationTransform : public RotationTransform
{
public:
    void transformImage(Image& image) const override;
};