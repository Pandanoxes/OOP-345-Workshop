#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_marker{""};
		std::string m_condition{""};
		double m_top_speed{0};

	public:
		Car(std::istream &);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream &out) const;
		void trim(std::string &);
	}; //End class
} // namespace sdds
#endif