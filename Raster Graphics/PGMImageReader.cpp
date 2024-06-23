#include "PGMImageReader.h"
#include "ImageTypeFactory.h"
#include "String.h"
#include <fstream>

Image PGMImageReader::readImage(const String& fileName) const
{
    std::ifstream imageFile(fileName.c_str());
    String fileType;
    imageFile >> fileType;
    ImageType imageType = ImageTypeFactory::getImageType(fileType);
    int imageWidth, imageHeight;
    imageFile >> imageWidth >> imageHeight;
    Image result(imageWidth, imageHeight, imageType, fileName);
	int maxGrayValue;
	imageFile >> maxGrayValue;
    switch (imageType)
    {
    case ImageType::PGM_ASCII:
        for (int y = 0; y < imageHeight; y++) {
            for (int x = 0; x < imageWidth; x++) {
                int gray;
                imageFile >> gray;
                gray *= ColorRGB::MAX_RGB_VALUE / maxGrayValue;
                result.setPixel(x, y, ColorRGB(gray, gray, gray));
            }
        }
        break;
    case ImageType::PGM_BINARY:
        for (int y = 0; y < imageHeight; y++) {
            for (int x = 0; x < imageWidth; x++) {
                unsigned char gray;
                imageFile.read(reinterpret_cast<char*>(&gray), 1);
                gray *= ColorRGB::MAX_RGB_VALUE / maxGrayValue;
                result.setPixel(x, y, ColorRGB(static_cast<int>(gray), static_cast<int>(gray), static_cast<int>(gray)));
            }
        }
        break;
    }
    return result;
}
