#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
namespace sdds
{
	Vehicle *createInstance(std::istream &in);
} // namespace sdds
#endif