#include <iostream>
#include "PPMImageReader.h"
#include "PPMImageWriter.h"
#include "BlackAndWhiteTransform.h"

int main()
{
    PPMImageReader reader;
    Image image = reader.readImage("test.ppm");
    std::cout << image.getWidth() << " " << image.getHeight() << std::endl;
	int imageWidth = image.getWidth();
	int imageHeight = image.getHeight();
	//for (int y = 0; y < imageHeight; y++)
	//{
		//for (int x = 0; x < imageWidth; x++)
		//{
			//ColorRGB currentColor = image.getPixel(x, y);
			//currentColor.desaturate();
			//image.setPixel(x, y, currentColor);
		//}
	//}
	PPMImageWriter writer;
	BlackAndWhiteTransform blackAndWhiteTransform;
	blackAndWhiteTransform.transformImage(image);
	writer.writeImage("testPosterized.ppm", image);

    return 0;
}