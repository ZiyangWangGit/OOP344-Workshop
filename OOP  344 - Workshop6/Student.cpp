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
#include <iostream>
#include "Student.h"

namespace seneca {
	Student::Student(std::istream& is) {
		std::string record;
		std::getline(is, record);
		std::string tag;

		size_t delimiter = record.find(",");
		std::string substr = record.substr(0, delimiter);
		substr = trim(substr);
		tag = substr;

		record.erase(0, delimiter + 1);
		delimiter = record.find(",");
		substr = record.substr(0, delimiter);
		substr = trim(substr);
		m_name = substr;

		record.erase(0, delimiter + 1);
		delimiter = record.find(",");
		substr = record.substr(0, delimiter);
		substr = trim(substr);
		bool flag = true;
		for (char c : substr) {
			if (!std::isdigit(c)) {
				flag = false;
			}
		}
		if (flag == false) {
			throw (m_name + "++Invalid record!");
		}
		else {
			m_age = substr;
		}

		record.erase(0, delimiter + 1);
		delimiter = record.find(",");
		substr = record.substr(0, delimiter);
		substr = trim(substr);
		if (substr[0] != 'S') {
			throw (m_name + "++Invalid record!");
		}
		else {
			m_id = substr;
		}

		record.erase(0, delimiter + 1);
		delimiter = record.find(",");
		substr = record.substr(0, delimiter);
		substr = trim(substr);
		size_t count = std::stoull(substr);
		if (!count) {
			throw (m_name + "++Invalid record!");
		}
		else {
			m_count = count;
		}
		record.erase(0, delimiter + 1);
		m_courses = new std::string[m_count];
		for (size_t i = 0; i < m_count; i++) {
			delimiter = record.find(",");
			substr = record.substr(0, delimiter);
			substr = trim(substr);
			m_courses[i] = substr;
			record.erase(0, delimiter + 1);
		}
	}

	Student::~Student() {
		delete[] m_courses;
	}

	std::string Student::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	std::string Student::status() const { return "Student"; }

	std::string Student::name() const { return m_name; }

	std::string Student::age() const { return m_age; }

	std::string Student::id() const { return m_id; }

	void Student::display(std::ostream& out) const {
		out << "| " << std::fixed << std::left << std::setw(10) << "Student" << "| "
			<< std::setw(10) << m_id << "| "
			<< std::setw(20) << m_name << " | "
			<< std::setw(3) << m_age << " |";
		for (size_t i = 0; i < m_count; ++i) {
			std::cout << m_courses[i];
			if (i != m_count - 1) {
				std::cout << ", ";
			}
		}
		out << std::endl;
	}
}

