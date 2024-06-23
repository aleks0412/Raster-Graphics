#include "PBMImageReader.h"
#include "ImageTypeFactory.h"
#include "String.h"
#include <fstream>

Image PBMImageReader::readImage(const String& fileName) const
{
    std::ifstream imageFile(fileName.c_str());
    String fileType;
    imageFile >> fileType;
    ImageType imageType = ImageTypeFactory::getImageType(fileType);
    int imageWidth, imageHeight;
    imageFile >> imageWidth >> imageHeight;
    Image result(imageWidth, imageHeight, imageType, fileName);
    switch (imageType)
    {
    case ImageType::PBM_ASCII:
        for (int y = 0; y < imageHeight; y++) {
            for (int x = 0; x < imageWidth; x++) {
                int bit;
                imageFile >> bit;
                int color = bit == 1 ? 0 : 255;
                result.setPixel(x, y, ColorRGB(color, color, color));
            }
        }
        break;
    case ImageType::PBM_BINARY:
        for (int y = 0; y < imageHeight; y++) 
        {
            for (int x = 0; x < imageWidth; x += 8) 
            {
                unsigned char bit;
                imageFile.read(reinterpret_cast<char*>(&bit), 1);
                int color = bit == 1 ? 0 : 255;
                result.setPixel(x, y, ColorRGB(color, color, color));
            }
        }
        break;
    }
    return result;
}
