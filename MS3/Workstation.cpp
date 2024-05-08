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
#include "CustomerOrder.h"
#include "Workstation.h"
#include "Station.h"

namespace  seneca {

	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	Workstation::Workstation(const std::string& string) :Station(string) {}

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			CustomerOrder& order = m_orders.front();
			order.fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder() {
		if (!m_orders.empty()) {
			CustomerOrder& order = m_orders.front();
			// Check if the order can be filled at this station or if quantity is zero
			if (order.isItemFilled(getItemName()) ||getQuantity() == 0 ) {
				if (m_pNextStation != nullptr) {
					*m_pNextStation += std::move(order);
				}
				else {
					if (order.isOrderFilled()) {
						g_completed.push_back(std::move(order));
					}
					else {
						g_incomplete.push_back(std::move(order));
					}
				}
				m_orders.pop_front();
				return true; 
			}
		}
		return false; 
	}


	void Workstation::setNextStation(Workstation* station = nullptr) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation != nullptr) {
			os << getItemName() << " --> " << getNextStation()->getItemName() << std::endl;
		}
		else {
			os << getItemName() << " --> End of Line" << std::endl;
		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}