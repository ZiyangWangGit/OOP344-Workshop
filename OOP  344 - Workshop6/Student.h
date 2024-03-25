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

#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H

#include "Person.h"

namespace seneca{
	class Student : public Person {
		std::string m_name;
		std::string m_age;
		std::string m_id;
		std::string* m_courses;
		size_t m_count;
	public:
		Student(std::istream&);
		~Student();
		std::string trim(std::string& str);
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream& out) const;
		Student(const Student&) = delete;
		Student& operator=(const Student&) = delete;

	};
}

#endif