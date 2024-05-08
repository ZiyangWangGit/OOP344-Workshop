/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 23,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace seneca {

	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {};

	CustomerOrder::CustomerOrder(const std::string& string) {
		seneca::Utilities newInfo;
		bool more = true;
		size_t pos = 0u;
		m_name = newInfo.extractToken(string, pos, more);
		m_product = newInfo.extractToken(string, pos, more);
		//find how many delimiters we found,and minus one to get item number;
		m_cntItem = std::count_if(string.begin(), string.end(), [&newInfo](char deli) {return deli == newInfo.getDelimiter(); }) - 1;
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; ++i) {
			m_lstItem[i] = new Item(newInfo.extractToken(string, pos, more));
		}
		if (CustomerOrder::m_widthField < newInfo.getFieldWidth()) {
			CustomerOrder::m_widthField = newInfo.getFieldWidth();
		}

	};

	CustomerOrder::CustomerOrder(const CustomerOrder& src) { throw std::string("*** WRONG ***"); };


	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {

		*this = std::move(src);
	};

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		if (this != &src) {

			for (size_t i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;

		}
		return *this;
	}



	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!(m_lstItem[i]->m_isFilled)) {
				return false;
			}
		}
		return true;
	};

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == itemName) {
				if (!m_lstItem[i]->m_isFilled) {
					return false;
				}
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() > 0 && !m_lstItem[i]->m_isFilled) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					return;
				}
				else if(station.getQuantity() == 0) {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					continue;
				}
			}
		}
	};

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; ++i) {
			os << "[" << std::setw(6) << std::setfill('0') <<std::right<< m_lstItem[i]->m_serialNumber << "] "
				<< std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - "
				<< (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	};



}