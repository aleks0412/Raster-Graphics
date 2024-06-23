#include "ImageTypeFactory.h"

const String ImageTypeFactory::PPM_ASCII = "P3";
const String ImageTypeFactory::PPM_BINARY = "P6";
const String ImageTypeFactory::PGM_ASCII = "P2";
const String ImageTypeFactory::PGM_BINARY = "P5";
const String ImageTypeFactory::PBM_ASCII = "P1";
const String ImageTypeFactory::PBM_BINARY = "P4";

ImageType ImageTypeFactory::getImageType(const String& imageTypeStr)
{
    if(imageTypeStr == PPM_ASCII)
    {
        return ImageType::PPM_ASCII;
    }
    else if(imageTypeStr == PPM_BINARY)
    {
        return ImageType::PPM_BINARY;
    }
    else if(imageTypeStr == PGM_ASCII)
    {
        return ImageType::PGM_ASCII;
    }
    else if(imageTypeStr == PGM_BINARY)
    {
        return ImageType::PGM_BINARY;
    }
    else if(imageTypeStr == PBM_ASCII)
    {
        return ImageType::PBM_ASCII;
    }
    else if(imageTypeStr == PBM_BINARY)
    {
        return ImageType::PBM_BINARY;
    }
    else
    {
        throw std::invalid_argument("Unknown image type");
    }
}