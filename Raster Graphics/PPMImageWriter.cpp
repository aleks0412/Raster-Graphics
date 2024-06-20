#include "PPMImageWriter.h"
#include <fstream>

void PPMImageWriter::writeImage(const char* fileName, const Image& image) const
{
	std::ofstream imageFile(fileName);
	imageFile << "P3" << "\n";
	imageFile << image.getWidth() << " " << image.getHeight() << "\n";
	imageFile << "255" << "\n";
	for (int y = 0; y < image.getHeight(); y++)
	{
		for (int x = 0; x < image.getWidth(); x++)
		{
			imageFile << image.getPixel(x, y).getRed() << "\n" << image.getPixel(x, y).getGreen() << "\n" << image.getPixel(x, y).getBlue() << "\n";
		}
	}
}
