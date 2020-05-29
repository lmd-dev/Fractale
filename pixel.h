#pragma once
#include <iostream>

/**
 * Represents a pixel of a picture
 */
class Pixel
{
private:
	//Red compononent of the pixel
	unsigned char red;

	//Green compononent of the pixel
	unsigned char green;

	//Blue compononent of the pixel
	unsigned char blue;

public:
	/**
	 * Constructor
	 * @param r Red component of the color
	 * @param r Green component of the color
	 * @param r Blue component of the color
	 */
	Pixel(const unsigned char& r = 0, const unsigned char& g = 0, const unsigned char& b = 0);

	/**
	 * Constructor
	 * @param color 32 bits color
	 */
	Pixel(const unsigned int& color);

	/**
	 * Sets the pixel with the 32 bits given color
	*/
	Pixel& operator=(const unsigned int& color);

	/**
	 * Saves the pixel on the given stream
	 * @param stream Stream to send data
	 */
	void save(std::ostream& stream) const;
};

