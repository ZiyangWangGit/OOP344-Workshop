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
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Toy.h"

namespace seneca {
	//Toy::Toy() {}

	Toy::Toy(const std::string& toy) {
		std::string tempToy = toy;
		//returns the position of the first occurrence of the substring
		size_t delimiter = tempToy.find(":");
		/*two parameters : the starting position of the substring and the length of the substring		
		converts a string representing an integer into an integer value*/
		std::string substr = tempToy.substr(0, delimiter);
		substr = trim(substr);
		orderId = std::stoi(substr);

		/*two parameters : the starting position from which to begin erasing
		characters and the number of characters to erase*/
		tempToy.erase(0, delimiter + 1);
		delimiter = tempToy.find(":");
		substr = tempToy.substr(0, delimiter);
		substr = trim(substr);
		name = substr;

		tempToy.erase(0, delimiter + 1);
		delimiter = tempToy.find(":");
		substr = tempToy.substr(0, delimiter);
		substr = trim(substr);
		numOfItems = std::stoi(substr);
		tempToy.erase(0, delimiter + 1);
		price = std::stod(tempToy);
	}

	std::string Toy::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	};

	void Toy::update(int numItems) {
		numOfItems = numItems;
	}


	
	
	std::ostream& operator<<(std::ostream& os, const Toy& toy) {
		double subtotal = toy.numOfItems * toy.price;
		double taxes = subtotal * toy.hst;
		os << "Toy" << std::setw(8) << toy.orderId << ":" << std::setw(18) << std::right << toy.name 
		   << std::setw(3) << toy.numOfItems << " items" << std::setw(8) << toy.price <<"/item  subtotal:"
		   << std::setw(7) << subtotal << " tax:" << std::setw(6) << std::fixed << std::setprecision(2) << taxes << " total:"
		   << std::setw(7) << std::fixed << std::setprecision(2) << subtotal+taxes << std::endl;
		return os;
	}

}


