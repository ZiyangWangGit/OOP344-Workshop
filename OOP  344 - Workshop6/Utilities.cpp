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
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

namespace seneca {
    Person* buildInstance(std::istream& in) {
        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ss(line);
            char firstChar;
            ss >> firstChar;
            if (firstChar == 'e' || firstChar == 'E') {
                try {
                    return new Employee(ss);
                }
                catch (const std::string& e) {
                    std::cout << e << std::endl;
                    return nullptr; 
                }
            }
            else if (firstChar == 's' || firstChar == 'S') {
                try {
                    return new Student(ss);
                }
                catch (const std::string& e) {
                    std::cout << e << std::endl;
                    return nullptr;
                }
            }
            else if (firstChar == 'p' || firstChar == 'P') {
                try {
                    return new Professor(ss);
                }
                catch (const std::string& e) {
                    std::cout << e << std::endl;
                    return nullptr;
                }
            }
            else {
                return nullptr;
            }
        }
        return nullptr;
	}
}