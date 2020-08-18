#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "Car.h"

namespace sdds
{
	//Constructor
	Car::Car(std::istream &is)
	{
		std::string data{""};
		std::string tag{""};
		std::getline(is, data);

		tag = data.substr(0, data.find(','));
		this->trim(tag);
		data.erase(0, data.find(',') + 1);

		if (tag == "c" || tag == "C")
		{

			this->m_marker = data.substr(0, data.find(','));
			this->trim(this->m_marker);
			data.erase(0, data.find(',') + 1);

			this->m_condition = data.substr(0, data.find(','));
			this->trim(this->m_condition);
			data.erase(0, data.find(',') + 1);

			if (!(this->m_condition == "n" || this->m_condition == "b" || this->m_condition == "u"))
				this->m_condition = "";

			std::string tempNum = data.substr(0, data.find(','));
			this->trim(tempNum);
			if (tempNum.find_first_not_of("0123456789") == (size_t)(-1))
				this->m_top_speed = stod(tempNum);
			else
				this->m_top_speed = 0;
		}
	} //End Constructor

	//condition fucntion
	std::string Car::condition() const
	{
		std::string condition{""};
		if (this->m_condition == "n" || this->m_condition == "N")
			condition = "new";
		else if (this->m_condition == "b" || this->m_condition == "B")
			condition = "broken";
		else if (this->m_condition == "u" || this->m_condition == "U")
			condition = "Used";
		return condition;
	} //End condition fucntion

	//topSpeed fucntion
	double Car::topSpeed() const
	{
		return this->m_top_speed;
	} //End topSpeed fucntion

	//display fucntion
	void Car::display(std::ostream &out) const
	{
		out << "| " << std::setw(10) << this->m_marker << " | "
			<< std::left << std::setw(6) << this->condition() << " | "
			<< std::right << std::setw(6) << std::fixed << std::setprecision(2) << this->topSpeed() << " |";
	} //End display fucntion

	//trim function
	void Car::trim(std::string &str)
	{
		bool hasSpace = true;
		while (hasSpace)
		{
			if (str.length() > 0)
			{
				if (str[0] == ' ')
					str.erase(0, 1);
				else if (str[str.length() - 1] == ' ')
					str.erase(str.length() - 1, str.length());
				else
					hasSpace = false;
			}
			else
				hasSpace = false;
		}
	} //End trim function
} // namespace sdds