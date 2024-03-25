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
#ifndef SENECA_CONFIRMORDER_H 
#define SENECA_CONFIRMORDER_H

#include "Child.h"
namespace seneca {
	class ConfirmOrder {
		const seneca::Toy** m_toy{nullptr};
		size_t m_size{ 0 };
		void setToys(const ConfirmOrder& other);
	public:
		ConfirmOrder();
		~ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& other);
		ConfirmOrder& operator = (const ConfirmOrder&);
		ConfirmOrder(ConfirmOrder&& other);
		ConfirmOrder& operator=(ConfirmOrder&& other);
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder&);
	};
}


#endif
