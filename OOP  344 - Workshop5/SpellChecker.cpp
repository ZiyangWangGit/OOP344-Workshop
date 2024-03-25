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
#include<iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "SpellChecker.h"

namespace seneca {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			size_t i = 0;
			//using the extraction operator >> with std::ifstream,automatically skips leading whitespace characters
			while (i < arraySize && file >> m_badWords[i] >> m_goodWords[i]) {  //whitespace as delimiter
				++i;
			}
		}
	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < arraySize; i++) {
			size_t delimiter = text.find(m_badWords[i]); // Search for the bad word in the text
			while (delimiter != std::string::npos) { 
				size_t length = m_badWords[i].length();
				text.replace(delimiter, length, m_goodWords[i]); // Replace bad word with good word
				mispelledTimes[i] += 1; // Increment misspelled count
				delimiter = text.find(m_badWords[i], delimiter + 1);
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < arraySize; i++) {
			out << std::setw(15) << std::fixed << std::right << m_badWords[i] << ": " << mispelledTimes[i] << " replacements" << std::endl;
		}
	
	}

}