#pragma once
#include <string>
#include "fractale.h"

/**
 * Fractale factory
 */
class FractaleFactory
{
public:
	/**
	 * Creates a fractale of the given type
	 */
	static std::shared_ptr<Fractale> createFractale(const std::string& fractaleType);
};

