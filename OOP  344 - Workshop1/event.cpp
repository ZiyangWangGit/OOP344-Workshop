/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

*Date:Jan 20,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip> 
#include "event.h"

namespace seneca {

	unsigned int g_sysClock = 0;
	unsigned int maxSeconds = 86400;

	Event::Event() :m_desc(nullptr), m_numOfSeconds(0) {}

	Event::~Event() {
		if (m_desc != nullptr) {
			delete[] m_desc;
			m_desc = nullptr;
		}
	}

	void Event::display()const {
		static int times = 0;
		times++;
		std::cout << std::setw(2) << std::setfill(' ') << times << ". ";
		if (m_desc == nullptr) {
			std::cout << "| No Event |" << std::endl;
		}
		else {
			int hours = m_numOfSeconds / 3600;
			int minutes = (m_numOfSeconds % 3600) / 60;
			int seconds = m_numOfSeconds % 60;
			std::cout << std::setw(2) << std::setfill('0') << hours << ":" <<
				std::setw(2) << std::setfill('0') << minutes << ":" <<
				std::setw(2) << std::setfill('0') << seconds << " => " << m_desc << std::endl;
		}
	};

	void Event::set(const char* desc) {
		delete[] m_desc;
		m_desc = nullptr;
		if (m_numOfSeconds < 0 || m_numOfSeconds > maxSeconds) {
			m_numOfSeconds = 0;
		}
		else {
			m_numOfSeconds = g_sysClock;
		}
		if (desc != nullptr && desc[0] != '\0') {
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
		}
		else {
			m_numOfSeconds = 0;
		}
	}

	Event::Event(const Event& other) : m_numOfSeconds(other.m_numOfSeconds) {
		if (other.m_desc) {
			m_desc = new char[strlen(other.m_desc) + 1];
			strcpy(m_desc, other.m_desc);
		}
		else {
			m_desc = nullptr;
		}
	}

	Event& Event::operator=(const Event& other) {
		if (this != &other) {
			delete[] m_desc;

			m_numOfSeconds = other.m_numOfSeconds;
			if (other.m_desc) {
				m_desc = new char[strlen(other.m_desc) + 1];
				strcpy(m_desc, other.m_desc);
			}
			else {
				m_desc = nullptr;
			}
		}
		return *this;
	}
}
