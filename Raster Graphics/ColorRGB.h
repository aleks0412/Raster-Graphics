#pragma once

struct ColorRGB
{
	ColorRGB() = default;
	ColorRGB(int red, int green, int blue);
	int red = 0;
	int green = 0;
	int blue = 0;
};    