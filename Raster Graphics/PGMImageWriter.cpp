#include "PGMImageWriter.h"
#include "ImageTypeFactory.h"
#include <fstream>

void PGMImageWriter::writeImage(const String& fileName, const Image& image) const
{
	std::ofstream imageFile(fileName.c_str());
	switch (image.getImageType())
	{
	case ImageType::PGM_ASCII:
		imageFile << ImageTypeFactory::PGM_ASCII << "\n";
		break;
	case ImageType::PGM_BINARY:
		imageFile << ImageTypeFactory::PGM_BINARY << "\n";
		break;
	}
	imageFile << image.getWidth() << " " << image.getHeight() << "\n";
	imageFile << ColorRGB::MAX_RGB_VALUE << "\n";
	switch (image.getImageType())
	{
	case ImageType::PGM_ASCII:
		for (int y = 0; y < image.getHeight(); y++)
		{
			for (int x = 0; x < image.getWidth(); x++)
			{
				int gray = image.getPixel(x, y).getValue();
				gray *= MAX_GRAY_VALUE / ColorRGB::MAX_RGB_VALUE;
				imageFile << gray << "\n";
			}
		}
		break;
	case ImageType::PGM_BINARY:
		for (int y = 0; y < image.getHeight(); y++)
		{
			for (int x = 0; x < image.getWidth(); x++)
			{
				int gray = image.getPixel(x, y).getValue();
				gray *= MAX_GRAY_VALUE / ColorRGB::MAX_RGB_VALUE;
				imageFile.write(reinterpret_cast<char*>(&gray), 1);
			}
		}
		break;
	}
}