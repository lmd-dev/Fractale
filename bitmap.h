#pragma once
#include "pixel.h"
/**
 * Bitmap without pixels storage which needs to be defined by child class
 */
class Bitmap
{
private:
	//Width of the picture
	unsigned int width;

	//Height of the picture
	unsigned int height;

	/**
	 * Saves file header structure
	 * @param stream Output stream to store data
	 */
	void saveFileHeader(std::ostream& stream) const;

	/**
	 * Saves bitmap header structure
	 * @param stream Output stream to store data
	 */
	void saveBitmapHeader(std::ostream& stream) const;

	/**
	 * Saves colors palette data
	 * @param stream Output stream to store data
	 */
	void savePalette(std::ostream& stream) const;

	/**
	 * Saves pixels data
	 * @param stream Output stream to store data
	 */
	void savePixels(std::ostream& stream) const;

	/**
	 * Returns the full size of the bitmap file
	 */
	unsigned int getFileSize() const;

	/**
	 * Returns the size of the file header structure
	 */
	unsigned int getHeaderFileSize() const;

	/**
	 * Returns the size of the bitmap header structure
	 */
	unsigned int getHeaderBitmapSize() const;

	/**
	 * Returns the size of the colors palette data
	 */
	unsigned int getPaletteSize() const;

	/**
	 * Returns the size of the pixels data
	 */
	unsigned int getPixelsSize() const;

public:
	/**
	 * Constructor
	 * @param w Default width of hte picture
	 * @param h Default height of the picture
	 */
	Bitmap(const unsigned int& w, const unsigned int& h);

	/**
	 * Sets the size of the picture and allocates memory space to store pixels.
	 * Has to be override by child class
	 */
	virtual void setSize(const unsigned int& w, const unsigned int& h);

	/**
	 * Returns the width of the picture
	 */
	const unsigned int& getWidth() const;

	/**
	 * Returns the height of the picture
	 */
	const unsigned int& getHeight() const;

	/**
	 * Returns a pixel of the picture (const function)
	 * @param x X coodinate of the pixel in the picture grid
	 * @param y Y coodinate of the pixel in the picture grid
	 */
	virtual const Pixel& at(const unsigned int& x, const unsigned int& y) const = 0;

	/**
	 * Returns a pixel of the picture
	 * @param x X coodinate of the pixel in the picture grid
	 * @param y Y coodinate of the pixel in the picture grid
	 */
	virtual Pixel& at(const unsigned int& x, const unsigned int& y) = 0;

	/**
	 * Saves the bitmap on the given stream
	 * @param stream Output stream to save the bitmap
	 */
	void save(std::ostream& stream) const;
};

/**
 * Serializing operator for Bitmap objects
 * @param stream Output stream where serialize data
 * @param bitmap Bitmap object to serialize
 */
std::ostream& operator<<(std::ostream& stream, const Bitmap& bitmap);
