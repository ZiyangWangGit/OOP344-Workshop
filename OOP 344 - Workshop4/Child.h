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
#ifndef SENECA_CHILD_H 
#define SENECA_CHILD_H

#include <string>
#include<iostream>
#include"Toy.h"

namespace seneca {
	class Child {
		std::string m_name{};
		size_t m_age{0};
		const seneca::Toy** m_pptoys{nullptr};
		size_t m_count{0};
		static int CALL_CNT;
		void set(std::string name, int age, const Toy* toys[], size_t count);
		void clearToys();
	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		~Child();
		Child(const Child& other);
		Child& operator=(const Child& other);
		Child(Child&& other);
		Child& operator=(Child&& other);
		friend std::ostream& operator<<(std::ostream& os, const Child&);
	};

}


#endif
