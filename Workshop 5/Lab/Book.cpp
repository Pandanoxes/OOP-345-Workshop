#include "Book.h"
#include <algorithm>
#include <iomanip>
#include <string>
namespace sdds
{
	//Default Constructor
	Book::Book() : m_author{""}, m_title{""}, m_country{""}, m_price{0}, m_year{0}, m_description{""} {}
	//End Default Constructor

	//Constructor
	Book::Book(const std::string &strBook)
	{
		std::string str = strBook;
		this->m_author = str.substr(0, str.find(','));
		this->cutSpace(this->m_author);
		str.erase(0, str.find(',') + 1);

		this->m_title = str.substr(0, str.find(','));
		this->cutSpace(this->m_title);
		str.erase(0, str.find(',') + 1);

		this->m_country = str.substr(0, str.find(','));
		this->cutSpace(this->m_country);
		str.erase(0, str.find(',') + 1);

		this->m_price = stod(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		this->m_year = stoi(str.substr(0, str.find(',')));
		str.erase(0, str.find(',') + 1);

		this->m_description = str;
		this->cutSpace(this->m_description);
	}
	//End Constructor

	//title function
	const std::string &Book::title() const
	{
		return this->m_title;
	} //End title function

	//country function
	const std::string &Book::country() const
	{
		return this->m_country;
	} //End country function

	//year function
	const size_t &Book::year() const
	{
		return this->m_year;
	} //End year function

	//price function
	double &Book::price()
	{
		return this->m_price;
	} //End price function

	//overload operator<< display
	std::ostream &operator<<(std::ostream &os, const Book &book_)
	{
		os << std::setw(20) << book_.m_author << " | " << std::setw(22) << book_.m_title << " | "
		   << std::setw(5) << book_.m_country << " | " << std::setw(4) << book_.m_year << " | "
		   << std::setw(6) << std::fixed << std::setprecision(2) << book_.m_price << " | "
		   << book_.m_description << std::endl;
		return os;
	} //End overload operator<< display

	//cutSpace function
	void Book::cutSpace(std::string &str)
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
} // namespace sdds