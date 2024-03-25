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
#ifndef SENECA_TOY_H 
#define SENECA_TOY_H

#include <iostream>

namespace seneca {
    class Toy {
        size_t  orderId{ 0 };
        std::string name;
        size_t numOfItems{ 0 };
        double price{ 0.00 };
        const double hst{ 0.13 };

    public:
        //Toy();
        Toy(const std::string& toy);
        void update(int numItems);
        std::string trim(std::string& str);
        friend std::ostream& operator<<(std::ostream& os, const Toy&);
    };
}

#endif