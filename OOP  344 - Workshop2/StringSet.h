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
#include<iostream>

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

namespace seneca {
	class StringSet {
		std::string* element{nullptr};
		size_t m_numOfString{0};
		void set(const StringSet& other);
	public:
		StringSet();
		StringSet(const char*);
		~StringSet();
		StringSet(StringSet&&);
		StringSet(const StringSet& other);
		StringSet& operator=(StringSet &&);
		StringSet& operator=(const StringSet&other);
		size_t size()const;
		std::string operator[](size_t)const;

	};
}
#endif