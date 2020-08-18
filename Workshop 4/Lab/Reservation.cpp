#define _CRT_SECURE_NO_WARNINGS
#include "Reservation.h"
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstring>

namespace sdds
{
	//Default Constructor
	Reservation::Reservation() : reservationId{}, name{""}, email{""}, numPeople{0}, day{0}, hour{0} {}
	//End Default Constructor

	//Constructor
	Reservation::Reservation(const std::string &res)
	{
		std::string str = res;
		str.erase(remove(str.begin(), str.end(), ' '), str.end());

		this->reservationId = str.substr(0, str.find(':'));
		str.erase(0, str.find(':') + 1);

		this->name = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		this->email = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		this->numPeople = std::stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		this->day = std::stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		this->hour = std::stoi(str);
	} //End Constructor

	//Overload operator<< for display
	std::ostream &operator<<(std::ostream &os, const Reservation &res_)
	{
		os << "Reservation " << res_.reservationId << ": "
		   << std::right << std::setw(10) << res_.name
		   << "  " << std::left << std::setw(20) << "<" + res_.email + ">"
		   << "    "
		   << ((res_.hour >= 6 && res_.hour <= 9) ? "Breakfast"
												  : (res_.hour >= 11 && res_.hour <= 15) ? "Lunch"
																						 : (res_.hour >= 17 && res_.hour <= 21) ? "Dinner" : "Drinks");
		os << " on day "
		   << res_.day << " @ " << res_.hour << ":00 "
		   << "for " << res_.numPeople << " people." << std::endl;
		return os;
	} //End Overload operator<<
} // namespace sdds