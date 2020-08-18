#include "Racecar.h"
#include <string>
#include <sstream>
namespace sdds
{
	//Constructor
	Racecar::Racecar(std::istream &in) : Car(in)
	{
		std::string data{""};
		in.clear();
		in.seekg(std::ios::beg);
		std::getline(in, data);
		this->m_booster = std::stod(data.substr(data.find_last_of(',') + 1, data.length()));
	} //End Constructor

	//Display function
	void Racecar::display(std::ostream &out) const
	{
		Car::display(out);
		out << "*";
	} //End Display function

	//topSpeed function
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + this->m_booster);
	} //End topSpeed function
} // namespace sdds