#pragma once
#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H
#include <iostream>
namespace sdds
{
	class Movie
	{
		std::string m_title{""};
		size_t m_year{0};
		std::string m_description{""};

	public:
		Movie();
		const std::string &title() const;
		Movie(const std::string &strMovie);
		void cutSpace(std::string &);
		//Template
		template <typename T>
		//fixSpelling function
		void fixSpelling(T spellChecker)
		{
			spellChecker(this->m_description);
			spellChecker(this->m_title);
		} //End fixSpelling function
		friend std::ostream &operator<<(std::ostream &, const Movie &);
	}; //End Class
} // namespace sdds
#endif