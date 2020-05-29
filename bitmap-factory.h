#pragma once
#include <string>
#include "bitmap.h"

/**
 * Bitmap factory
 */
class BitmapFactory
{
public:
	/**
	 * Creates a bitmap of the given type
	 */
	static std::shared_ptr<Bitmap> createBitmap(const std::string& bitmapType, const unsigned int& width, const unsigned int& height);
};

