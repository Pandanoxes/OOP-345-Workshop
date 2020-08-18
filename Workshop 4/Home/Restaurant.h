/**
 *	Kevan Yang
 *	164-775-181
 *	kyang47@myseneca.ca
 *	OOP345 NAA
 *	Jun 07 2020
 *	I have done all the coding by myself and only copied the code
 *	that my professor provided to complete my workshops and assignments.
**/
#pragma once
#ifndef _SDDS_RESTAURANT_H
#define _SDDS_RESTAURANT_H
#include "Reservation.h"
#include <iostream>
namespace sdds {
	class Restaurant
	{
		Reservation* r_reservations{ nullptr };
		size_t sizes{ 0 };

	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant(Restaurant&& src)noexcept;
		Restaurant& operator=(const Restaurant&);
		Restaurant& operator=(Restaurant&&)noexcept;
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};//End Class
}//End namespace
#endif