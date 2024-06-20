#pragma once

class ColorRGB
{
public:
	ColorRGB() = default;
	ColorRGB(int red, int green, int blue);

	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	int getValue() const;

	void setRed(int red);
	void setGreen(int green);
	void setBlue(int blue);

	void desaturate();

private:
	int red = 0;
	int green = 0;
	int blue = 0;
};