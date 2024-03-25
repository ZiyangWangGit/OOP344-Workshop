/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Feb 09,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <utility>
#include "Child.h"

namespace seneca {

	static int CALL_CNT = 0;

	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
		set(name, age, toys, count);
	}

	Child:: ~Child(){
		clearToys();
	}

	void Child::set(std::string name, int age, const Toy* toys[], size_t count){
		m_name = name;
		m_age = age;
		m_count = count;
		m_pptoys = new const seneca::Toy * [count];
		for (size_t i = 0; i < count; i++) {
			m_pptoys[i] = new Toy(*toys[i]);
		}
	}

	void Child::clearToys() {
		for (size_t i = 0; i < m_count; i++) {
			delete m_pptoys[i];
		}
		delete[] m_pptoys;
	}

	size_t Child::size() const {
		return m_count;
	}

	Child::Child(const Child& other) {
		set(other.m_name, other.m_age, other.m_pptoys, other.m_count);
	}

	Child& Child::operator=(const Child& other) {
		if (this != &other) {
			clearToys();
			set(other.m_name, other.m_age, other.m_pptoys, other.m_count);
		}
		return *this;
	}

	Child::Child(Child&& other) {
		*this = std::move(other);
	}

	Child& Child::operator=(Child&& other) {
		if (this != &other) {
			clearToys();
			m_name = other.m_name;
			m_age = other.m_age;
			m_pptoys = other.m_pptoys;
			m_count = other.m_count;
			other.m_pptoys = nullptr;
			other.m_count = 0;
			other.m_age = 0;
			other.m_name = {};
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Child& child) {
		CALL_CNT++;
		os << "--------------------------" << std::endl;
		os << "Child " << CALL_CNT << ": " << child.m_name << " " << child.m_age << " years old:" << std::endl;
		os << "--------------------------" << std::endl;

		if (child.m_count == 0) {
			os << "This child has no toys!" << std::endl;
		}
		else {
			for (size_t i = 0; i < child.m_count; ++i) {
				os << *(child.m_pptoys[i]); 
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}
}