#include "ImageReaderFactory.h"
#include "PPMImageReader.h"
#include "PGMImageReader.h"
#include "PBMImageReader.h"

const String ImageReaderFactory::PPM_EXTENSION = ".ppm";
const String ImageReaderFactory::PGM_EXTENSION = ".pgm";
const String ImageReaderFactory::PBM_EXTENSION = ".pbm";

SubclassPtr<IImageReader> ImageReaderFactory::CreateImageReader(const String& filePath)
{
	String extension = filePath.subStr(filePath.getSize() - MAX_EXTENSION_LENGTH, MAX_EXTENSION_LENGTH);
	if (extension == PPM_EXTENSION)
	{
		return SubclassPtr<IImageReader>(new PPMImageReader());
	}
	else if (extension == PGM_EXTENSION)
	{
		return SubclassPtr<IImageReader>(new PGMImageReader());
	}
	else if (extension == PBM_EXTENSION)
	{
		return SubclassPtr<IImageReader>(new PBMImageReader());
	}
	else
	{
		throw std::invalid_argument("Unknown image type");
	}
}
