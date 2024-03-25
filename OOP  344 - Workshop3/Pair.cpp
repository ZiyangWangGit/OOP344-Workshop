/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Feb 03,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include "Collection.h"
#include "Pair.h"

namespace seneca {
	Pair::Pair() {}

	Pair::Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

	const std::string& Pair::getKey()const {
		return m_key;
	}

	const std::string& Pair::getValue()const { 
		return m_value; 
	}

	std::ostream& operator<<(std::ostream& os, const Pair& pair) {
		
		os << std::setw(20) << pair.m_key << ": " << pair.m_value;
		return os;
	}

	bool Pair::operator==(const Pair& other) const {
		return m_key == other.m_key || m_value == other.m_value;
	}

}
