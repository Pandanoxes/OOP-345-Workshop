#include "Movie.h"
#include <string>
#include <algorithm>
#include <iomanip>

namespace sdds
{
	//Default Constructor
	Movie::Movie() : m_title{""}, m_year{0}, m_description{""} {}
	//End Default Constructor

	//title function
	const std::string &Movie::title() const
	{
		return this->m_title;
	} //End title function

	//Constructor
	Movie::Movie(const std::string &strMovie)
	{
		std::string str = strMovie;

		this->m_title = str.substr(0, str.find(','));
		this->cutSpace(this->m_title);
		str.erase(0, str.find(',') + 1);

		this->m_year = stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		this->m_description = str;
		this->cutSpace(this->m_description);
	} //End Constructor

	//cutSpace function
	void Movie::cutSpace(std::string &str)
	{
		bool hasSpace = true;
		while (hasSpace)
		{
			if (str[0] == ' ')
				str.erase(0, 1);
			else if (str[str.length() - 1] == ' ')
				str.erase(str.length() - 1, str.length());
			else
				hasSpace = false;
		}
	} //End cutSpace function

	//Overload operator<< for display
	std::ostream &operator<<(std::ostream &os, const Movie &movie_)
	{
		os << std::setw(40) << movie_.m_title << " | " << std::setw(4) << movie_.m_year
		   << " | " << movie_.m_description << std::endl;
		return os;
	} //End Overload operator<< for display
} // namespace sdds