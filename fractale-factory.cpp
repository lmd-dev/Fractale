#include "fractale-factory.h"
#include "fractale-mandelbrot.h"
#include "fractale-julia.h"

std::shared_ptr<Fractale> FractaleFactory::createFractale(const std::string& fractaleType)
{
	if (fractaleType == "mandelbrot")
		return std::make_shared<FractaleMandelbrot>();
	else if (fractaleType == "julia")
		return std::make_shared<FractaleJulia>();

	throw std::string("FractaleFactory::createFractale - Unknown type '") + fractaleType + std::string("'");
}