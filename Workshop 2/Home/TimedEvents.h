#pragma once
#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H
#include <chrono>
#include <iostream>

namespace sdds
{
	const int MAX_RECORDS = 7;
	class TimedEvents
	{
		int m_numRecord{0};
		std::chrono::steady_clock::time_point m_start_t{};
		std::chrono::steady_clock::time_point m_end_t{};
		struct
		{
			std::string m_eventName{};
			std::string m_unitOfTime{};
			std::chrono::steady_clock::duration m_duration{};
		} m_arrayRecord[MAX_RECORDS];

	public:
		TimedEvents() = default;
		void startClock();
		void stopClock();
		void recordEvent(const char *);
		friend std::ostream &operator<<(std::ostream &, const TimedEvents &);
	}; //End Class
} // namespace sdds
#endif