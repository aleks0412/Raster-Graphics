#pragma once
#include "IImageWriter.h"

class PGMImageWriter : public IImageWriter
{
public:
	void writeImage(const char* fileName, const Image& image) const override;
};