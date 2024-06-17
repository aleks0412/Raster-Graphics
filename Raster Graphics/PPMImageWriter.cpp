#include "PPMImageWriter.h"
#include <fstream>

void PPMImageWriter::writeImage(const char* fileName, const Image& image) const
{
	std::ofstream imageFile(fileName);
	imageFile << "P3" << "\n";
	imageFile << image.getWidth() << " " << image.getHeight() << "\n";
	for (int y = 0; y < image.getHeight(); y++)
	{
		for (int x = 0; x < image.getWidth(); x++)
		{
			imageFile << image.getPixel(x, y).red << "\n" << image.getPixel(x, y).green << "\n" << image.getPixel(x, y).blue << "\n";
		}
	}
}
