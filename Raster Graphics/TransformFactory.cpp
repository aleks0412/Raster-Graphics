#include "TransformFactory.h"
#include "DesaturateTransform.h"
#include "BlackAndWhiteTransform.h"
#include "NegativeTransform.h"
#include "ClockwiseRotationTransform.h"
#include "CounterClockwiseRotationTransform.h"

const String TransformFactory::DESATURATE_TRANSFORM_NAME = "grayscale";
const String TransformFactory::BLACK_AND_WHITE_TRANSFORM_NAME = "monochrome";
const String TransformFactory::NEGATIVE_TRANSFORM_NAME = "negative";
const String TransformFactory::ROTATION_TRANSFORM_NAME = "rotate";
const String TransformFactory::CLOCKWISE_ROTATION_TRANSFORM_NAME = "right";
const String TransformFactory::COUNTERCLOCKWISE_ROTATION_TRANSFORM_NAME = "left";

SubclassPtr<ITransform> TransformFactory::createTransform(const String& name)
{
    if(name == DESATURATE_TRANSFORM_NAME)
    {
        return SubclassPtr<ITransform>(new DesaturateTransform());
    }
    else if(name == BLACK_AND_WHITE_TRANSFORM_NAME)
    {
        return SubclassPtr<ITransform>(new BlackAndWhiteTransform());
    }
    else if(name == NEGATIVE_TRANSFORM_NAME)
    {
        return SubclassPtr<ITransform>(new NegativeTransform());
    }
    else if(name == ROTATION_TRANSFORM_NAME)
    {
        String direction;
        std::cin >> direction;
        if(direction == CLOCKWISE_ROTATION_TRANSFORM_NAME)
        {
            return SubclassPtr<ITransform>(new ClockwiseRotationTransform());
        }
        else if(direction == COUNTERCLOCKWISE_ROTATION_TRANSFORM_NAME)
        {
            return SubclassPtr<ITransform>(new CounterClockwiseRotationTransform());
        }
        else
        {
            throw std::invalid_argument("Unknown rotation direction");
        }
    }
    else
    {
        throw std::invalid_argument("Unknown transform name");
    }
}

bool TransformFactory::isTransformName(const String& name)
{
    return name == DESATURATE_TRANSFORM_NAME
        || name == BLACK_AND_WHITE_TRANSFORM_NAME
        || name == NEGATIVE_TRANSFORM_NAME
        || name == ROTATION_TRANSFORM_NAME
        || name == CLOCKWISE_ROTATION_TRANSFORM_NAME
        || name == COUNTERCLOCKWISE_ROTATION_TRANSFORM_NAME;
}