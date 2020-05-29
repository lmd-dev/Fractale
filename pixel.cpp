#include "pixel.h"


Pixel::Pixel(const unsigned char& r, const unsigned char& g, const unsigned char& b)
	: red(r), green(g), blue(b)
{

}

Pixel::Pixel(const unsigned int& color)
{
	this->operator=(color);
}

Pixel& Pixel::operator=(const unsigned int& color)
{
	red = (color & 0x00FF0000) >> 16;
	green = (color & 0x0000FF00) >> 8;
	blue = color & 0x000000FF;

	return *this;
}

void Pixel::save(std::ostream& stream) const
{
	stream.write((char*)&blue, sizeof(blue));
	stream.write((char*)&green, sizeof(green));
	stream.write((char*)&red, sizeof(red));
}

