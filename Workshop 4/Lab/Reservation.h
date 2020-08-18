#pragma once
#ifndef _SDDS_RESERVATION_H
#define _SDDS_RESERVATION_H
#include <iostream>
namespace sdds
{
	class Reservation
	{
		std::string reservationId{""};
		std::string name{""};
		std::string email{""};
		unsigned int numPeople{0};
		unsigned int day{0};
		unsigned int hour{0};

	public:
		Reservation();
		Reservation(const std::string &res);
		friend std::ostream &operator<<(std::ostream &, const Reservation &);
	}; //End Class
} // namespace sdds
#endif