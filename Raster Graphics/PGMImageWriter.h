#pragma once
#include "IImageWriter.h"

class PGMImageWriter : public IImageWriter
{
public:
	void writeImage(const String& fileName, const Image& image) const override;

private:
	static constexpr int MAX_GRAY_VALUE = 15;
};