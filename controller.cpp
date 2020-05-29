#include "controller.h"
#include "fractale-factory.h"
#include "bitmap-factory.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include <omp.h>

Controller::Controller(int argc, char* argv[])
	: outputWidth(1920), outputHeight(1080), fractaleType("mandelbrot"), maxIteration(50), xCenter(0), yCenter(0), width(1), fileName("picture"), frames(1), zoomStep(1), maxIterationStep(1), timer(false), array(false), threads(0)
{
	auto timerStart = std::chrono::high_resolution_clock::now();

	extractParameters(argc, argv);

	if (threads > 0)
		omp_set_num_threads(threads);

	std::cout << "Generation de " << frames << " fractale" << (frames > 1 ? "s" : "") << " avec " << omp_get_max_threads() << " threads..." << std::endl;
	
	drawFractales();

	auto timerEnd = std::chrono::high_resolution_clock::now();

	if (timer)
	{
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timerEnd - timerStart).count();
		std::cout << "Temps de traitement total : " << duration << " ms" << std::endl;
	}
}

void Controller::extractParameters(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		if (std::string(argv[i]) == "-timer")
			timer = true;
		else if (std::string(argv[i]) == "-array")
			array = true;
		else if (i < argc - 1)
		{
			if (std::string(argv[i]) == "-t")
				fractaleType = argv[++i];
			else if (std::string(argv[i]) == "-ow")
				outputWidth = std::stoi(argv[++i]);
			else if (std::string(argv[i]) == "-oh")
				outputHeight = std::stoi(argv[++i]);
			else if (std::string(argv[i]) == "-itmax")
				maxIteration = std::stoi(argv[++i]);
			else if (std::string(argv[i]) == "-x")
				xCenter = std::stod(argv[++i]);
			else if (std::string(argv[i]) == "-y")
				yCenter = std::stod(argv[++i]);
			else if (std::string(argv[i]) == "-w")
				width = std::stod(argv[++i]);
			else if (std::string(argv[i]) == "-f")
				fileName = argv[++i];
			else if (std::string(argv[i]) == "-frames")
				frames = std::stoi(argv[++i]);
			else if (std::string(argv[i]) == "-zoomstep")
				zoomStep = std::stod(argv[++i]);
			else if (std::string(argv[i]) == "-itmaxstep")
				maxIterationStep = std::stod(argv[++i]);
			else if (std::string(argv[i]) == "-threads")
				threads = std::stoi(argv[++i]);
		}
	}
}

void Controller::drawFractales()
{
	auto fractale = FractaleFactory::createFractale(fractaleType);

	std::shared_ptr<Bitmap> bitmap = BitmapFactory::createBitmap((array ? "array" : "vector"), outputWidth, outputHeight);

	for (int iFrame = 0; iFrame < frames; ++iFrame)
	{
		auto timerStart = std::chrono::high_resolution_clock::now();

		//Lambda function to colorize the fractale
		auto colorize = [](const unsigned int& iterations, const unsigned int& maxIteration)
		{
			return static_cast<unsigned int>(((1.0 * iterations) / maxIteration) * 0xFFFFFF);
		};

		fractale->draw(*bitmap, xCenter, yCenter, width, maxIteration);

		std::stringstream name;
		name << fileName << "-" << (iFrame < 10 ? "00" : (iFrame < 100 ? "0" : "")) << ".bmp";
		std::ofstream file(name.str(), std::ios::binary | std::ios::out);
		file << *bitmap;
		file.close();

		width *= zoomStep;
		maxIteration *= maxIterationStep;

		auto timerEnd = std::chrono::high_resolution_clock::now();

		if (timer)
		{
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timerEnd - timerStart).count();
			std::cout << "Temps de traitement frame " << (iFrame + 1) << " : " << duration << " ms" << std::endl;
		}

	}

	auto timerEnd = std::chrono::high_resolution_clock::now();
}

