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

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace seneca {
	class Book {
		std::string author;
		std::string bookTitle;
		std::string countryPublic;
		size_t yearPublic;
		double bookPrice;
		std::string desc;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		std::string trim(std::string& str);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Book&);
	};
}

#endif