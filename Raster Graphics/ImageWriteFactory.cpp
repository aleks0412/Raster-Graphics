#include "ImageWriteFactory.h"
#include "PPMImageWriter.h"
#include "PGMImageWriter.h"
#include "PBMImageWriter.h"


SubclassPtr<IImageWriter> ImageWriterFactory::CreateImageWriter(const Image& image)
{
    switch(image.getImageType())
	{
	case ImageType::PPM_ASCII:
	case ImageType::PPM_BINARY:
		return SubclassPtr<IImageWriter>(new PPMImageWriter());
	case ImageType::PGM_ASCII:
	case ImageType::PGM_BINARY:
		return SubclassPtr<IImageWriter>(new PGMImageWriter());
	case ImageType::PBM_ASCII:
	case ImageType::PBM_BINARY:
		return SubclassPtr<IImageWriter>(new PBMImageWriter());
	default:
		throw std::invalid_argument("Unknown image type");
	}
}
