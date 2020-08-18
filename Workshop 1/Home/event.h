#pragma once
#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H
//extern value
extern unsigned int g_sysClock;

namespace sdds
{
	class Event
	{
		char *m_desc;
		unsigned int m_time;

	public:
		Event();
		~Event();
		Event(const Event &);
		void display();
		void setDescription(const char *);
		Event &operator=(const Event &);
	}; //End Class
} //End namespace sdds
#endif