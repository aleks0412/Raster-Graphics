#include "PPMImageWriter.h"
#include "ImageTypeFactory.h"
#include <fstream>

void PPMImageWriter::writeImage(const String& fileName, const Image& image) const
{
	std::ofstream imageFile(fileName.c_str());
	switch (image.getImageType())
	{
	case ImageType::PPM_ASCII:
		imageFile << ImageTypeFactory::PPM_ASCII << "\n";
		break;
	case ImageType::PPM_BINARY:
		imageFile << ImageTypeFactory::PPM_BINARY << "\n";
		break;
	}
	imageFile << image.getWidth() << " " << image.getHeight() << "\n";
	imageFile << ColorRGB::MAX_RGB_VALUE << "\n";
	switch (image.getImageType())
	{
	case ImageType::PPM_ASCII:
		for (int y = 0; y < image.getHeight(); y++)
		{
			for (int x = 0; x < image.getWidth(); x++)
			{
				imageFile << image.getPixel(x, y).getRed() << "\n" << image.getPixel(x, y).getGreen() << "\n" << image.getPixel(x, y).getBlue() << "\n";
			}
		}
		break;
	case ImageType::PPM_BINARY:
		for (int y = 0; y < image.getHeight(); y++)
		{
			for (int x = 0; x < image.getWidth(); x++)
			{
				int red = image.getPixel(x, y).getRed();
				int green = image.getPixel(x, y).getGreen();
				int blue = image.getPixel(x, y).getBlue();
				imageFile.write(reinterpret_cast<char*>(&red), 1);
				imageFile.write(reinterpret_cast<char*>(&green), 1);
				imageFile.write(reinterpret_cast<char*>(&blue), 1);
			}
		}
		break;
	}
}
