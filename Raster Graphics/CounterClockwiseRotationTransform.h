#pragma once
#include "RotationTransform.h"

class CounterClockwiseRotationTransform : public RotationTransform
{
public:
    void transformImage(Image& image) const override;
    ITransform* clone() const override;
};