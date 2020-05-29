#include "bitmap-array.h"
#include <cstring>

BitmapWithArray::BitmapWithArray(const unsigned int& w, const unsigned int& h)
	: pixels(NULL), Bitmap(w, h)
{
	setSize(w, h);
}

BitmapWithArray::~BitmapWithArray()
{
	if (pixels)
		delete[] pixels;
}

void BitmapWithArray::setSize(const unsigned int& w, const unsigned int& h)
{
	if (pixels)
		delete[] pixels;

	Bitmap::setSize(w, h);

	pixels = new Pixel[w * h];
}

const Pixel& BitmapWithArray::at(const unsigned int& x, const unsigned int& y) const
{
	if (x < 0 || x >= getWidth() || y < 0 || y >= getHeight())
		throw "BitmapWithArray::at - Index out of range";

	return pixels[y * getWidth() + x];
}

Pixel& BitmapWithArray::at(const unsigned int& x, const unsigned int& y)
{
	if (x < 0 || x >= getWidth() || y < 0 || y >= getHeight())
		throw "BitmapWithArray::at - Index out of range";

	return pixels[y * getWidth() + x];
}