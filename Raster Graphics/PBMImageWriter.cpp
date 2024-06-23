#include "PBMImageWriter.h"
#include "ImageTypeFactory.h"
#include <fstream>

void PBMImageWriter::writeImage(const String& fileName, const Image& image) const
{
	std::ofstream imageFile(fileName.c_str());
	switch (image.getImageType())
	{
	case ImageType::PBM_ASCII:
		imageFile << ImageTypeFactory::PBM_ASCII << "\n";
		break;
	case ImageType::PBM_BINARY:
		imageFile << ImageTypeFactory::PBM_BINARY << "\n";
		break;
	}
	imageFile << image.getWidth() << " " << image.getHeight() << "\n";
	switch (image.getImageType())
	{
	case ImageType::PBM_ASCII:
		for (int y = 0; y < image.getHeight(); y++)
		{
			for (int x = 0; x < image.getWidth(); x++)
			{
				int bw = image.getPixel(x, y).getValue() > ColorRGB::MAX_RGB_VALUE / 2 ? 1 : 0;
				imageFile << bw << "\n";
			}
		}
		break;
	case ImageType::PBM_BINARY:
		for (int y = 0; y < image.getHeight(); y++)
		{
			unsigned char byte = 0;
			for (int x = 0; x < image.getWidth(); x++)
			{
				if (x % 8 == 0 && x != 0)
				{
					imageFile.write(reinterpret_cast<char*>(&byte), 1);
					byte = 0;
				}
				int bw = image.getPixel(x, y).getValue() > ColorRGB::MAX_RGB_VALUE / 2 ? 1 : 0;
				byte = (byte << 1) | (bw ? 1 : 0);
			}
			if (image.getWidth() % 8 != 0)
			{
				byte <<= (8 - (image.getWidth() % 8));
				imageFile.write(reinterpret_cast<char*>(&byte), 1);
			}
		}
		break;
	}
}