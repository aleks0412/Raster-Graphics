#pragma once
#include "IImageReader.h"
#include "SubclassPtr.hpp"
#include "String.h"

class ImageReaderFactory
{
public:
	static SubclassPtr<IImageReader> CreateImageReader(const String& filePath);

private:
	static constexpr int MAX_EXTENSION_LENGTH = 4;
	static const String PPM_EXTENSION;
	static const String PGM_EXTENSION;
	static const String PBM_EXTENSION;
};