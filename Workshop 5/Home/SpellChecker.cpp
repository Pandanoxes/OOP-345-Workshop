#include "SpellChecker.h"
#include <algorithm>
#include <fstream>

namespace sdds
{
	//Constuctor
	SpellChecker::SpellChecker(const char *filename)
	{
		std::ifstream file(filename);
		if (!file)
			throw("Bad file name!");
		size_t counter = 0;
		do
		{
			if (file)
			{
				file >> this->m_badWords[counter] >> this->m_goodWords[counter];
				++counter;
			}
		} while (file);
		file.close();
	} //End Constuctor

	//overload operator()
	void SpellChecker::operator()(std::string &text) const
	{
		for (auto i = 0; i < 5; i++)
		{
			if (text.find(this->m_badWords[i]) != (size_t)(-1))
			{
				text.replace(text.find(this->m_badWords[i]), this->m_badWords[i].length(), this->m_goodWords[i]);
				i--;
			}
		}
	} //End overload operator()
} // namespace sdds