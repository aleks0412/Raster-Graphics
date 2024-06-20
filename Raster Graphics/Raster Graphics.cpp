#include <iostream>
#include "PPMImageReader.h"
#include "PPMImageWriter.h"
#include "RotationTransform.h"
#include "ClockwiseRotationTransform.h"
#include "CounterClockwiseRotationTransform.h"

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
	RotationTransform* clockwiseRotationTransform = new ClockwiseRotationTransform();
	clockwiseRotationTransform->transformImage(image);
	writer.writeImage("testClockwiseRotation.ppm", image);
	RotationTransform* counterClockwiseRotationTransform = new CounterClockwiseRotationTransform();
	counterClockwiseRotationTransform->transformImage(image);
	counterClockwiseRotationTransform->transformImage(image);
	writer.writeImage("testCounterClockwiseRotation.ppm", image);

    return 0;
}