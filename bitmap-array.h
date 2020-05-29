#pragma once
#include "bitmap.h"
/**
 * Bitmap with C array storage
 */
class BitmapWithArray: public Bitmap
{
private:
	//Array of pixels
	Pixel* pixels;

public:
	/**
	 * Constructor
	 * @param w Default width of hte picture
	 * @param h Default height of the picture
	 */
	BitmapWithArray(const unsigned int& w, const unsigned int& h);

	/**
	 * Destructor
	 */
	~BitmapWithArray();
	
	/**
	 * Sets the size of the picture and allocates memory space to store pixels.
	 */
	void setSize(const unsigned int& w, const unsigned int& h);

	/**
	 * Returns a pixel of the picture (const function)
	 * @param x X coodinate of the pixel in the picture grid
	 * @param y Y coodinate of the pixel in the picture grid
	 */
	const Pixel& at(const unsigned int& x, const unsigned int& y) const;

	/**
	 * Returns a pixel of the picture
	 * @param x X coodinate of the pixel in the picture grid
	 * @param y Y coodinate of the pixel in the picture grid
	 */
	Pixel& at(const unsigned int& x, const unsigned int& y);
};
