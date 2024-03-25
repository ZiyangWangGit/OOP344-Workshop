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

#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <vector>
#include <list>
#include "Person.h"


namespace seneca {
	class College {
		std::vector<Person*> m_persons;
	public:
		College() = default;
		~College();
		College(const College&) = delete;
		College& operator=(const College&) = delete;
		College& operator +=(Person* thePerson);
		void display(std::ostream& out) const;
		template<typename T>
		void select(const T& test, std::list<const Person*>& persons);

	};
	template<typename T>
	void College::select(const T& test, std::list<const Person*>& persons) {
		for (const auto& person : m_persons) {
			if (test(person)) {
				persons.push_back(person);
			}
		}
	}

}

#endif