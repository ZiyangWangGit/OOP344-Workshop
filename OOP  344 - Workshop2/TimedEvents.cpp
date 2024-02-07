/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Jan 20,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <iomanip>
#include "TimedEvents.h"

namespace seneca{
	TimedEvents::TimedEvents():m_numOfRecords(0){}

	void TimedEvents::startClock() {
		m_startTime = std::chrono::steady_clock::now();	
	}

	void TimedEvents::stopClock(){
		m_endTime = std::chrono::steady_clock::now();
	}

	
	void TimedEvents::addEvent(const char* name){
		events[m_numOfRecords].eventName = name;
		events[m_numOfRecords].preDefinedUnits = "nanoseconds";
		events[m_numOfRecords].durationTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_numOfRecords++;
	}


	std::ostream& operator<<(std::ostream& os, const TimedEvents& t) 
	{
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (size_t i = 0; i < t.m_numOfRecords; i++) {
			os << std::left << std::setw(21) << t.events[i].eventName << 
				  std::right << std::setw(13) << t.events[i].durationTime.count() <<
				  t.events[i].preDefinedUnits << std::endl;;
		}
		os << "--------------------------" << std::endl;
		return os;
	};

}