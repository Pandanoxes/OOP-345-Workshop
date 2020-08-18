#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle *> m_vehicles;

	public:
		Autoshop &operator+=(Vehicle *theVehicle);
		void display(std::ostream &out) const;
		~Autoshop();
	}; //End class
} // namespace sdds
#endif
