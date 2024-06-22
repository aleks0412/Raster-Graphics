#include "CounterClockwiseRotationTransform.h"

void CounterClockwiseRotationTransform::transformImage(Image& image) const
{
    mirrorImage(image);
    transposeImage(image);
}

ITransform* CounterClockwiseRotationTransform::clone() const
{
    return new CounterClockwiseRotationTransform();
}