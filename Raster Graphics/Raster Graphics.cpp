#include <iostream>
#include "PPMImageReader.h"
#include "PPMImageWriter.h"
#include "NegativeTransform.h"
#include "SubclassPtr.hpp"

int main()
{
    PPMImageReader reader;
    Image image = reader.readImage("test.ppm");
    std::cout << image.getWidth() << " " << image.getHeight() << std::endl;
	int imageWidth = image.getWidth();
	int imageHeight = image.getHeight();
	PPMImageWriter writer;
	SubclassPtr<NegativeTransform> negativeTransform(new NegativeTransform());
	negativeTransform->transformImage(image);
	writer.writeImage("testNegative.ppm", image);

    return 0;
}