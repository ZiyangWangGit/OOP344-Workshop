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
#include <string>
#include <iomanip>
#include <cctype> 
#include <iostream>
#include "Employee.h"
#include "Person.h"
#include "Professor.h"

namespace seneca {
	Employee::Employee(std::istream& is) {
		std::string record;
		std::getline(is, record, ',');
		std::string tag = trim(record);
		std::getline(is, record, ',');
		m_name = trim(record);


		std::getline(is, record, ',');
		std::string substr = trim(record);
		bool flag = true;
		for (char c : substr) {
			if (!std::isdigit(c)) {
				flag = false;
			}
		}
		if (flag == false){
			throw (m_name + "++Invalid record!");
		}
		else { 
			m_age = substr;
		}

		std::getline(is, record, ',');
		substr = trim(record);
		if (substr[0] != 'E') {
			throw (m_name + "++Invalid record!");
		}
		else {
			m_id = substr;
		}
	}

	std::string Employee::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	std::string Employee::status() const { return "Employee"; }
	
	std::string Employee::name() const { return m_name; }
	
	std::string Employee::age() const { return m_age; }
	
	std::string Employee::id() const { return m_id; }
	
	void Employee::display(std::ostream& out) const {
		out << "| " << std::fixed << std::left << std::setw(10) << "Employee" << "| "
			<< std::setw(10) << m_id << "| " 
			<< std::setw(20) << m_name << " | "
			<< std::setw(3) << m_age << " |" << std::endl;
	}

}
