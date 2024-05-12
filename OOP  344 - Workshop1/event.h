/*************************************************************************************

*
$\displaystyle\sum_{i=1}^{n} i=1+2+3+\ldots+n=\frac{n(n+1)}{2}$
* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

*Date:Jan 20,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include <iostream>

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H


namespace seneca {

	extern unsigned int g_sysClock;
	extern unsigned int maxSeconds;

	class Event {
		char* m_desc{};
		unsigned int m_numOfSeconds;

	public:
		Event();
		~Event();
		void display()const;
		void set(const char* desc = nullptr);
		Event(const Event& other);
		Event& operator=(const Event& other);
	};

}

#endif
