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
#include <string>
#include "ConfirmOrder.h"

namespace seneca {
    ConfirmOrder::ConfirmOrder() {}

    ConfirmOrder::~ConfirmOrder() {
        delete[] m_toy;
    }

    void ConfirmOrder::setToys(const ConfirmOrder& other) {
        m_size = other.m_size;
        m_toy = new const seneca::Toy * [m_size];
        for (size_t i = 0; i < m_size; i++) {
            m_toy[i] = other.m_toy[i];
        }
    }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& other) {
        setToys(other);
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
        if (this != &other) {
            delete[] m_toy;
            m_toy = new const seneca::Toy * [m_size];
            setToys(other);
        }
        return *this;
    }


    ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) {
        *this = std::move(other);
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) {
        if (this != &other) {
            delete[] m_toy;
            m_toy = other.m_toy;
            m_size = other.m_size;
            other.m_size = 0;
            other.m_toy = nullptr;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        bool found = false;
        for (size_t i = 0; i < m_size; i++) {
            if (m_toy[i] == &toy) {
                found = true;
            }
        }
        if (!found) {
            const Toy** newArray = new const Toy * [m_size + 1];
            for (size_t i = 0; i < m_size; ++i) {
                newArray[i] = m_toy[i];
            }
            newArray[m_size] = &toy;
            delete[] m_toy;
            m_toy = newArray;
            m_size++;
        }
        return *this;
    }


    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        bool found = false;
        size_t i = 0;
        for (; i < m_size && !found; ++i) {
            if (m_toy[i] == &toy) {
                found = true;
            }
        }
        if (found) {
            m_toy[i - 1] = nullptr;
            for (; i < m_size; ++i)
                m_toy[i - 1] = m_toy[i];
            if (m_size > 0) {
                m_toy[m_size - 1] = nullptr;
                m_size--;
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if (order.m_toy == nullptr || order.m_toy[0] == nullptr) {
            os << "There are no confirmations to send!" << std::endl;
        }
        else {
            for (size_t i = 0; i < order.m_size; ++i) {
                os << *order.m_toy[i];
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}

