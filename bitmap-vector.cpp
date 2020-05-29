#include "bitmap-vector.h"
#include <cstring>

BitmapWithVector::BitmapWithVector(const unsigned int& w, const unsigned int& h)
	: Bitmap(w, h)
{
	setSize(w, h);
}

void BitmapWithVector::setSize(const unsigned int& w, const unsigned int& h)
{
	Bitmap::setSize(w, h);

	pixels.resize(w * h);
}

const Pixel& BitmapWithVector::at(const unsigned int& x, const unsigned int& y) const
{
	if (x < 0 || x >= getWidth() || y < 0 || y >= getHeight())
		throw "BitmapWithVector::at - Index out of range";

	return pixels[y * getWidth() + x];
}

Pixel& BitmapWithVector::at(const unsigned int& x, const unsigned int& y)
{
	if (x < 0 || x >= getWidth() || y < 0 || y >= getHeight())
		throw "BitmapWithVector::at - Index out of range";

	return pixels[y * getWidth() + x];
}