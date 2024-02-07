/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Jan 27,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/

#include <iostream>
#include <chrono>


#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

namespace seneca {
	class TimedEvents{
		size_t m_numOfRecords;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		static const int numOfObjects = 10;  //holds the info for every instace of that class

		struct Events{
			std::string eventName;
			std::string preDefinedUnits;
			std::chrono::steady_clock::duration durationTime;
		}events[numOfObjects];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents&);
	};
}
#endif
