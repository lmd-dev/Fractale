#include "fractale-julia.h"

void FractaleJulia::draw(Bitmap& bitmap, const double& xCenter, const double& yCenter, const double& width, const unsigned int& maxIteration, unsigned int (*colorize)(const unsigned int& iteration, const unsigned int& maxIteration))
{
	const double ratio = (1.0 * bitmap.getHeight()) / bitmap.getWidth();

	double height = width * ratio;

	double x1 = xCenter - width / 2;
	double x2 = xCenter + width / 2;
	double y1 = yCenter - height / 2;
	double y2 = yCenter + height / 2;

	double zoom_x = bitmap.getWidth() / (x2 - x1);
	double zoom_y = bitmap.getHeight() / (y2 - y1);

#pragma omp parallel for
	for (int x = 0; x < bitmap.getWidth(); ++x)
	{
#pragma omp parallel for
		for (int y = 0; y < bitmap.getHeight(); ++y)
		{
			double z_r = x / zoom_x + x1;
			double z_i = y / zoom_y + y1;
			double c_r = 0.285;
			double c_i = 0.01;

			unsigned int i = 0;

			do
			{
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i*tmp + c_i;
				i++;
			} while (z_r*z_r + z_i * z_i < 4 && i < maxIteration);

			if (i != maxIteration)
			{
				bitmap.at(x, y) = (colorize ? colorize(i, maxIteration) : i);
			}
		}
	}
}