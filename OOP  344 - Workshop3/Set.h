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
#ifndef SENECA_SET_H
#define SENECA_SET_H

#include <cmath>
#include "Collection.h"

namespace seneca {
    template<typename T>
    class Set : public Collection<T, 100> {
    public:
        bool add(const T& item) override {
            for (unsigned i = 0; i < Collection<T, 100>::size(); ++i) {
                if (this->operator[](i) == item) { // check if Item already exists
                    return false;
                }
            }
            return Collection<T, 100>::add(item);
        }
    };

    template<>
    bool Set<double>::add(const double& item) {
        for (unsigned i = 0; i < Collection<double, 100>::size(); ++i) {
            if (std::fabs(this->operator[](i) - item) <= 0.01) {
                return false;
            }
        }
        Collection<double, 100>::add(item);
        return true;
    }
}

#endif