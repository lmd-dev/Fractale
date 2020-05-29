#pragma once
#include <string>
/**
 * Main controller of the application
 */
class Controller
{
private:
	//Width of the output picture
	unsigned int outputWidth;

	//Height of the output picture
	unsigned int outputHeight;

	//Type of fractal to produce
	std::string fractaleType;

	//Max iterations
	unsigned int maxIteration;

	//X coordinate of the center of the fractal
	double xCenter;

	//Y coordinate of the center of the fractal
	double yCenter;

	//Width of the area of the fractal to display
	double width;

	//Name of the bitmap file to produce
	std::string fileName;

	//Number of frames to produce
	unsigned int frames;

	//Zoom coefficient at each frame
	double zoomStep;

	//Coefficient of increasing for the max iteration at each frame
	double maxIterationStep;

	//Number of max threads to use
	unsigned int threads;

	//Display timing performances
	bool timer;

	//Use C array storage mode
	bool array;

	/**
	 * Extracts parameters from execution command line
	 */
	void extractParameters(int argc, char* argv[]);

	/**
	 * Produces frames with fractales
	 */
	void drawFractales();

public:
	/**
	 * Constructor
	 * @param argc Number of parameters ginven in the command line
	 * @param argv String values of the parameters
	 */
	Controller(int argc, char* argv[]);
};

