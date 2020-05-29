#pragma once
#include "bitmap.h";
#include "fractale.h"

/**
 * Mandelbrot fractale
 */
class FractaleMandelbrot: public Fractale
{
public:
	/**
	 * Draw the fractale on a bitmap
	 * @param bitmap Bitmap to use to draw the fractale
	 * @param xCenter X coordinate of the center of the fractale area to target
	 * @param yCenter Y coordinate of the center of the fractale area to target
	 * @param width Width of the fractale area to display
	 * @param maxIteration Max number of iterations to produce the fractale
	 */
	void draw(Bitmap& bitmap, const double& xCenter, const double& yCenter, const double& width, const unsigned int& maxIteration, unsigned int(*colorize)(const unsigned int& iteration, const unsigned int& maxIteration) = NULL);
};

