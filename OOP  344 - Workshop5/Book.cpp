/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Feb 17,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

namespace seneca {
	Book::Book() {}
	
	const std::string& Book::title() const { 
		return bookTitle; 
	}
	const std::string& Book::country() const {
		return countryPublic;
	}
	
	const size_t& Book::year() const {
		return yearPublic;
	}

	double& Book::price() {
		return bookPrice;
	}

	Book::Book(const std::string& strBook) {
		std::string tempBook = strBook;
		size_t delimiter = tempBook.find(",");

		std::string substr = tempBook.substr(0, delimiter);
		substr = trim(substr);
		author = substr;

		tempBook.erase(0, delimiter + 1);
		delimiter = tempBook.find(",");
		substr = tempBook.substr(0, delimiter);
		substr = trim(substr);
		bookTitle = substr;

		tempBook.erase(0, delimiter + 1);
		delimiter = tempBook.find(",");
		substr = tempBook.substr(0, delimiter);
		substr = trim(substr);
		countryPublic = substr;

		tempBook.erase(0, delimiter + 1);
		delimiter = tempBook.find(",");
		substr = tempBook.substr(0, delimiter);
		substr = trim(substr);
		bookPrice = std::stod(substr);

		tempBook.erase(0, delimiter + 1);
		delimiter = tempBook.find(",");
		substr = tempBook.substr(0, delimiter);
		substr = trim(substr);
		yearPublic = std::stoi(substr);

		tempBook.erase(0, delimiter + 1);
		delimiter = tempBook.find("\n");
		substr = tempBook.substr(0, delimiter);
		substr = trim(substr);
		desc = substr;
	}
		

	std::string Book::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}


	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::setw(20) << book.author << " | " << std::setw(22) << book.bookTitle << " | "
			<< std::setw(5) << book.countryPublic << " | " << std::setw(4) << book.yearPublic << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.bookPrice 
			<< " | " << book.desc << std::endl;
		return os;
	}
}