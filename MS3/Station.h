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
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <string>

namespace seneca {
	class Station {
		size_t m_id;
		std::string m_name;
		std::string m_desc;
		unsigned int m_serialNumber;
		unsigned int m_quantity;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& string);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif