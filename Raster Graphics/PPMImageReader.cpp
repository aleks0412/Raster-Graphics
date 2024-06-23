#include "PPMImageReader.h"
#include "ImageTypeFactory.h"
#include "String.h"
#include <fstream>

Image PPMImageReader::readImage(const String& fileName) const
{
    std::ifstream imageFile(fileName.c_str());
    char fileType[3];
    imageFile >> fileType;
    std::cout << "File type: " << fileType << std::endl;
    ImageType imageType = ImageTypeFactory::getImageType(fileType);
    int imageWidth, imageHeight;
    imageFile >> imageWidth >> imageHeight;
    Image result(imageWidth, imageHeight);
    int maxColorValue;
	imageFile >> maxColorValue;
    switch(imageType)
    {
    case ImageType::PPM_ASCII:
        for(int y = 0; y < imageHeight; y++)
        {
            for(int x = 0; x < imageWidth; x++)
            {
                int red, green, blue;
                imageFile >> red >> green >> blue;
                result.setPixel(x, y, ColorRGB(red, green, blue));
            }
        }
        break;
    case ImageType::PPM_BINARY:
        for(int y = 0; y < imageHeight; y++)
        {
            for(int x = 0; x < imageWidth; x++)
            {
                unsigned char red, green, blue;
                imageFile.read(reinterpret_cast<char*>(&red), 1);
                imageFile.read(reinterpret_cast<char*>(&green), 1);
                imageFile.read(reinterpret_cast<char*>(&blue), 1);
                result.setPixel(x, y, ColorRGB(static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue)));
            }
        }
        break;
    }
    return result;
}
