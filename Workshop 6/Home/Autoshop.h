#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>

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
		template <typename T>
		void select(T test, std::list<const Vehicle *> &vehicles)
		{
			for (auto i = this->m_vehicles.begin(); i != this->m_vehicles.end(); i++)
				if (test(*i))
					vehicles.push_back(*i);
		}
	}; //End class
} // namespace sdds
#endif
