#include "bitmap.h"
#include <cstring>

Bitmap::Bitmap(const unsigned int& w, const unsigned int& h)
{
	setSize(w, h);
}

void Bitmap::setSize(const unsigned int& w, const unsigned int& h)
{
	width = w;
	height = h;
}

const unsigned int& Bitmap::getWidth() const
{
	return width;
}

const unsigned int& Bitmap::getHeight() const
{
	return height;
}

void Bitmap::save(std::ostream& stream) const
{
	saveFileHeader(stream);
	saveBitmapHeader(stream);
	savePalette(stream);
	savePixels(stream);

}

void Bitmap::saveFileHeader(std::ostream& stream) const
{
	unsigned int size = getFileSize();
	unsigned int reserved = 0;
	unsigned int pixelsAddress = getHeaderFileSize() + getHeaderBitmapSize() + getPaletteSize();

	stream.write("BM", 2);
	stream.write((char*)&size, sizeof(size));
	stream.write((char*)&reserved, sizeof(reserved));
	stream.write((char*)&pixelsAddress, sizeof(pixelsAddress));
}

void Bitmap::saveBitmapHeader(std::ostream& stream) const
{
	unsigned int size = getHeaderBitmapSize();
	unsigned short numberPlans = 1;
	unsigned short colorDeepth = 24;
	unsigned int compressionMethod = 0;
	unsigned int imageSize = getPixelsSize();
	unsigned int pixelsResolution = 72;
	unsigned int paletteColors = 0;
	unsigned int paletteImportantColors = 0;
	unsigned int pixelsAddress = getHeaderFileSize() + getHeaderBitmapSize() + getPaletteSize();

	stream.write((char*)&size, sizeof(size));
	stream.write((char*)&width, sizeof(width));
	stream.write((char*)&height, sizeof(height));
	stream.write((char*)&numberPlans, sizeof(numberPlans));
	stream.write((char*)&colorDeepth, sizeof(colorDeepth));
	stream.write((char*)&compressionMethod, sizeof(compressionMethod));
	stream.write((char*)&imageSize, sizeof(imageSize));
	stream.write((char*)&pixelsResolution, sizeof(pixelsResolution));
	stream.write((char*)&pixelsResolution, sizeof(pixelsResolution));
	stream.write((char*)&paletteColors, sizeof(paletteColors));
	stream.write((char*)&paletteImportantColors, sizeof(paletteImportantColors));
}

void Bitmap::savePalette(std::ostream& stream) const
{

}

void Bitmap::savePixels(std::ostream& stream) const
{
	int rowCompSize = (width * 3) % 4;
	char* rowComp = NULL;

	if (rowCompSize > 0)
	{
		rowComp = new char[rowCompSize];
		memset(rowComp, 0, rowCompSize);
	}

	for (unsigned int row = 0; row < height; ++row)
	{
		for (unsigned int column = 0; column < width; ++column)
		{
			at(column, row).save(stream);
		}

		if (rowCompSize > 0)
			stream.write(rowComp, rowCompSize);
	}
}

unsigned int Bitmap::getFileSize() const
{
	unsigned int size = 0;

	size += getHeaderFileSize();
	size += getHeaderBitmapSize();
	size += getPaletteSize();
	size += getPixelsSize();

	return size;
}

unsigned int Bitmap::getHeaderFileSize() const
{
	return 14;
}

unsigned int Bitmap::getHeaderBitmapSize() const
{
	return 40;
}

unsigned int Bitmap::getPaletteSize() const
{
	return 0;
}

unsigned int Bitmap::getPixelsSize() const
{
	return width * height * 3;
}

std::ostream& operator<<(std::ostream& stream, const Bitmap& bitmap)
{
	bitmap.save(stream);

	return stream;
}