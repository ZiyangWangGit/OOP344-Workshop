/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Jan 20,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "StringSet.h"

namespace seneca {
	StringSet::StringSet() {}

	StringSet::StringSet(const char* name) {
		std::ifstream file(name);
		while (file) {
			char x = file.get();
			if (m_numOfString == 0) m_numOfString++;
			if (x == ' ') {
				m_numOfString++;
			}
		}
		
		element = new std::string[m_numOfString];
		
		file.clear();
		file.seekg(0);

		for (size_t i = 0; i < m_numOfString; i++) {
			std::getline(file, element[i],' ');
		}
		file.close();
	}

	StringSet::~StringSet(){
		delete[] element;
	}

	StringSet::StringSet(StringSet&&other) {
		*this = std::move(other);
	}


	void StringSet::set(const StringSet& other) {
		m_numOfString = other.m_numOfString;
		element = new std::string[m_numOfString];

		for (size_t i = 0; i < m_numOfString; i++) {
			element[i] = other.element[i];
		}
	}

	StringSet::StringSet(const StringSet& other) {
		set(other);
	}

	StringSet& StringSet::operator=(StringSet&& other) {
		if (this != &other) {
			delete[] element;
			m_numOfString = other.m_numOfString;
			element = other.element;
			other.m_numOfString = 0;
			other.element = nullptr;
		}
		return *this;
	}


	StringSet& StringSet::operator=(const StringSet& other) {
		if (this != &other) {
			delete[] element; 
			set(other);
		}
		else {
			delete[] element;
			m_numOfString = 0;
			element = nullptr;
		}
		return *this;
	}

	size_t StringSet::size()const { return m_numOfString; }

	std::string StringSet::operator[](size_t index)const { 
		if (index < m_numOfString) {
			return element[index];
		}
		else {
			return std::string();
		}
	}
}

