/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 15,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include <iomanip>
#include <iostream>
#include "Station.h"
#include "Utilities.h"

namespace seneca {
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string& string) {
		seneca::Utilities newInfo;
		bool more = true;
		size_t pos = 0u;
		id_generator += 1;
		m_id = id_generator;
		m_name = newInfo.extractToken(string, pos, more);
		m_serialNumber = std::stoul(newInfo.extractToken(string, pos, more));
		m_quantity = std::stoul(newInfo.extractToken(string, pos, more));
		if (Station::m_widthField < newInfo.getFieldWidth()) {
			Station::m_widthField = newInfo.getFieldWidth();
		}
		m_desc = newInfo.extractToken(string, pos, more);
	}

	const std::string& Station::getItemName() const { return m_name; }

	size_t Station::getNextSerialNumber() { return m_serialNumber++; }

	size_t Station::getQuantity() const { return m_quantity; }

	void Station::updateQuantity() {
		if (m_quantity >= 1) {
			m_quantity -= 1;
		}
	}

	void Station::display(std::ostream& os, bool full) const {
		os << std::setw(3) << std::setfill('0') <<std::right << m_id << " | " << std::setw(m_widthField)
			<< std::setfill(' ') << std::fixed << std::left << m_name << " | " << std::right
			<< std::setw(6) << std::setfill('0') << m_serialNumber << " | " << std::setfill(' ');

		if (full) {
			os << std::setw(4) << m_quantity << " | " << m_desc;
		}
		os << std::endl;
	}
}