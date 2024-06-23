#pragma once
#include "ITransform.h"
#include "SubclassPtr.hpp"
#include "String.h"

class TransformFactory
{
public:
    static SubclassPtr<ITransform> createTransform(const String& name);
    static bool isTransformName(const String& name);

    static const String DESATURATE_TRANSFORM_NAME;
    static const String BLACK_AND_WHITE_TRANSFORM_NAME;
    static const String NEGATIVE_TRANSFORM_NAME;
    static const String ROTATION_TRANSFORM_NAME;
    static const String CLOCKWISE_ROTATION_TRANSFORM_NAME;
    static const String COUNTERCLOCKWISE_ROTATION_TRANSFORM_NAME;
};