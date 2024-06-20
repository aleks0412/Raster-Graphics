#include "ClockwiseRotationTransform.h"

void ClockwiseRotationTransform::transformImage(Image& image) const
{
    transposeImage(image);
    mirrorImage(image);
}