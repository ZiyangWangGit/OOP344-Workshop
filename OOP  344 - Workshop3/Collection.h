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
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include<iostream>
#include "Pair.h"


namespace seneca {

	template<typename T, int capacity>
    class Collection {
        static T dummy;
        T element[capacity];
        static unsigned m_count;
    public:

        unsigned size() const { return m_count; }

        std::ostream& display(std::ostream& os = std::cout) const {
            os << "----------------------\n"<< "| Collection Content |\n"
               << "----------------------\n";
            for (unsigned i = 0; i < m_count; i++) {
                os << element[i] << "\n";
            }
            os << "----------------------\n";
            return os;
        }

        virtual bool add(const T& item) {
            if (m_count >= capacity) {
                return false;
            }
            else {
                element[m_count] = item;
                m_count++;
                return true;
            }
        }

        T operator[](unsigned int index)const {
            return (index >= 0 && index < m_count) ? element[index] : dummy; //if the index within the m_count(number of elements),return at the specified index
        }

        virtual ~Collection() = default;

    };


    template<typename T, int capacity>
    unsigned Collection<T, capacity>::m_count = 0u;


    template<typename T, int capacity>
    inline T Collection<T, capacity>::dummy{};

    template<>
    Pair Collection<Pair, 100>::dummy = Pair("No Key", "No Value");

}

#endif