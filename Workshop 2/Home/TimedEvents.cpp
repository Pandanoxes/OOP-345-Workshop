#include "TimedEvents.h"
#include <string.h>
#include <iomanip>
namespace sdds
{
	//startClock function
	void TimedEvents::startClock()
	{
		this->m_start_t = std::chrono::steady_clock::now();
	} //End startClock function

	//stopClock function
	void TimedEvents::stopClock()
	{
		this->m_end_t = std::chrono::steady_clock::now();
	} //End stopClock function

	//recordEvent function
	void TimedEvents::recordEvent(const char *eventDescription)
	{
		if (this->m_numRecord < MAX_RECORDS)
		{
			this->m_arrayRecord[this->m_numRecord].m_eventName = std::string(eventDescription);
			this->m_arrayRecord[this->m_numRecord].m_unitOfTime = "nanoseconds";
			this->m_arrayRecord[this->m_numRecord].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(this->m_end_t - this->m_start_t);
			;
			this->m_numRecord++;
		}
	} //End recordEvent function

	//overload operator<<
	std::ostream &operator<<(std::ostream &os, const TimedEvents &event)
	{
		os << "--------------------------\nExecution Times:\n--------------------------" << std::endl;
		for (int i = 0; i < event.m_numRecord; i++)
			os << std::setw(20) << std::left << event.m_arrayRecord[i].m_eventName
			   << std::setw(12) << std::right << event.m_arrayRecord[i].m_duration.count()
			   << " " << event.m_arrayRecord[i].m_unitOfTime << std::endl;
		os << "--------------------------" << std::endl;
		return os;
	} //End overload operator<<
} // namespace sdds