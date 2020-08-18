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
		this->m_desc = nullptr;
		this->m_time = 0;
	} //End Default Constructor

	//Deconstructor
	Event::~Event()
	{
		if (this->m_desc != nullptr)
		{
			delete[] this->m_desc;
			this->m_desc = nullptr;
		}
	} //End Deconstructor

	//Copy Constructor
	Event::Event(const Event &src)
	{
		*this = src;
	} //End Copy Constructor

	//display function
	void Event::display()
	{
		static int counter = 0;
		std::cout << std::setfill(' ') << std::setw(3) << ++counter << ". ";
		if (this->m_desc == nullptr)
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
			delete[] this->m_desc;
			this->m_desc = nullptr;
		}
		else
		{
			if (this->m_desc != nullptr)
				delete[] this->m_desc;

			this->m_desc = nullptr;
			this->m_desc = new char[strlen(desc) + 1];
			strcpy(this->m_desc, desc);
			this->m_time = g_sysClock;
		}
	} //End setDescription function

	//operator= function
	Event &Event::operator=(const Event &src)
	{
		if (this != &src)
		{
			this->m_time = src.m_time;
			this->m_desc = nullptr;
			if (src.m_desc != nullptr)
			{
				this->m_desc = new char[strlen(src.m_desc) + 1];
				strcpy(this->m_desc, src.m_desc);
			}
		}
		return *this;
	} //operator= function
} //End namespace sdds