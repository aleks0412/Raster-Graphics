#pragma once
#include "IImageWriter.h"

class PPMImageWriter : public IImageWriter
{
public:
	void writeImage(const char* fileName, const Image& image) const override;
};