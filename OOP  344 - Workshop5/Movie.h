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
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace seneca {
	class Movie {
		std::string movieTitle;
		size_t yearRelease;
		std::string desc;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		std::string trim(std::string& str);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(desc);
			spellChecker(movieTitle);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie&);
	};

}


#endif