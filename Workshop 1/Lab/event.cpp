#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <string.h>
#include <iostream>
#include <iomanip>
unsigned int g_sysClock = 0;

namespace sdds
{
	//Default Constructor
	Event::Event()
	{
		this->m_desc[0] = '\0';
		this->m_time = 0;
	} //End Default Constructor

	//display function
	void Event::display()
	{
		static int counter = 0;
		std::cout << std::setfill(' ') << std::setw(3) << ++counter << ". ";
		if (this->m_desc[0] == '\0')
			std::cout << "[ No Event ]" << std::endl;
		else
		{
			unsigned int sec = m_time;
			unsigned int hours = sec / 3600;
			sec = sec % 3600;
			unsigned int mins = sec / 60;
			sec = sec % 60;
			std::cout << std::setfill('0') << std::setw(2) << hours << ':' << std::setw(2) << mins
					  << ':' << std::setw(2) << sec << " -> " << this->m_desc << std::endl;
		}
	} //End display function

	//setDescription function
	void Event::setDescription(const char *desc)
	{
		if (desc == nullptr)
		{
			this->m_desc[0] = '\0';
		}
		else
		{
			strcpy(this->m_desc, desc);
			this->m_time = g_sysClock;
		}
	} //End setDescription function
} //End namespace sdds