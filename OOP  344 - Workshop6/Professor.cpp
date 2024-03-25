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
#include <iostream>
#include <string>
#include <iomanip>
#include "Professor.h"
#include "Employee.h"

namespace seneca {

	Professor::Professor(std::istream& in):Employee(in) {
		std::string record;
		std::getline(in, record);
		Employee::trim(record);
		m_department = record;
	}

	void Professor::display(std::ostream& out) const {
		out << "| " << std::fixed << std::left << std::setw(10) << "Employee" << "| "
			<< std::setw(10) << Employee::id() << "| "
			<< std::setw(20) << Employee::name() << " | "
			<< std::setw(3) << Employee::age() << " |" 
		    << m_department << "| " << "Professor" << std::endl;
	}

	std::string Professor::status() const { return "Professor"; }

	std::string Professor::department() const { return m_department; }

}
