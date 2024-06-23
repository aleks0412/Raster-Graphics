#pragma once
#include "IImageWriter.h"
#include "SubclassPtr.hpp"
#include "Image.h"

class ImageWriterFactory
{
public:
	static SubclassPtr<IImageWriter> CreateImageWriter(const Image& image);
};