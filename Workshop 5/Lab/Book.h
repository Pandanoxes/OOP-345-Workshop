#pragma once
#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
#include <iostream>

namespace sdds
{
	class Book
	{
		std::string m_author{""};
		std::string m_title{""};
		std::string m_country{""};
		double m_price{0};
		size_t m_year{0};
		std::string m_description{""};

	public:
		Book();
		Book(const std::string &strBook);
		const std::string &title() const;
		const std::string &country() const;
		const size_t &year() const;
		double &price();
		friend std::ostream &operator<<(std::ostream &, const Book &);
		void cutSpace(std::string &);
	}; //End Class
} // namespace sdds
#endif