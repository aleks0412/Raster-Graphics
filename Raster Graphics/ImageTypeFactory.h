#pragma once
#include "ImageType.h"
#include "String.h"

class ImageTypeFactory
{
public:
    static ImageType getImageType(const String& imageTypeStr);

    static const String PPM_ASCII;
    static const String PPM_BINARY;
    static const String PGM_ASCII;
    static const String PGM_BINARY;
    static const String PBM_ASCII;
    static const String PBM_BINARY;
};