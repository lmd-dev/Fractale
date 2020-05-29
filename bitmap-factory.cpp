#include "bitmap-factory.h"
#include "bitmap-array.h"
#include "bitmap-vector.h"

std::shared_ptr<Bitmap> BitmapFactory::createBitmap(const std::string& bitmapType, const unsigned int& width, const unsigned int& height)
{
	if (bitmapType == "array")
		return std::make_shared<BitmapWithArray>(width, height);
	else if (bitmapType == "vector")
		return std::make_shared<BitmapWithVector>(width, height);

	throw std::string("BitmapFactory::createBitmap - Unknown type '") + bitmapType + std::string("'");
}