/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 05,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

namespace seneca {
    Person* buildInstance(std::istream& in);
}

#endif



