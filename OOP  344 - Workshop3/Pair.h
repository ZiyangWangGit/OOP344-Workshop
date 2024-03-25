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
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include "Collection.h"

namespace seneca {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		Pair();
		Pair(const std::string& key, const std::string& value);
		const std::string& getKey()const;
		const std::string& getValue()const;
		bool operator==(const Pair& other) const;
		friend std::ostream& operator <<(std::ostream& os, const Pair& pair);
	};
}
#endif