/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 05,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include <string>
#include "Person.h"

namespace seneca {
	class Employee : public Person {
		std::string m_name;
		std::string m_age;
		std::string m_id;
	public:
		Employee(std::istream&);
		std::string trim(std::string& str);
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream&) const;
	};
}

#endif
