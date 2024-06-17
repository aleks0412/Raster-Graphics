#include "PPMImageReader.h"
#include <fstream>

Image PPMImageReader::readImage(const char* fileName) const
{
    std::ifstream imageFile(fileName);
    char fileType[3];
    imageFile >> fileType;
    std::cout << "File type: " << fileType << std::endl;
    int imageWidth, imageHeight;
    imageFile >> imageWidth >> imageHeight;
    Image result(imageWidth, imageHeight);
    if(strcmp(fileType, "P3") == 0)
    {
        for(int y = 0; y < imageHeight; y++)
        {
            for(int x = 0; x < imageWidth; x++)
            {
                int red, green, blue;
                imageFile >> red >> green >> blue;
                result.setPixel(x, y, ColorRGB(red, green, blue));
            }
        }
    }
    return result;
}
