/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 15,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include <iostream>
#include <sstream>
#include "Utilities.h"


namespace seneca {
	char Utilities::m_delimiter = ',';

	void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

	size_t Utilities::getFieldWidth() const { return m_widthField; }

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

		if (str[next_pos] == m_delimiter) { //check if the next char is the delimiter
			more = false;
			throw ("No text between");
		}

		size_t delimiter = str.find(m_delimiter, next_pos);   //find delimiter positiion starting from next_pos

		if (delimiter == std::string::npos) {  //if the delimiter not found,set it the the str length
			delimiter = str.length();
		}

		std::string substr = str.substr(next_pos, delimiter - next_pos);

		substr = trim(substr); //remove leading and trailing spaces                     
		next_pos = delimiter != str.length() ? delimiter + 1 : str.length();
		more = next_pos < str.length(); //check if we are at the end or not

		if (substr.length() > m_widthField) {   //update max string length if nessessary    
			m_widthField = substr.length();
		}

		return substr;
	}

	std::string Utilities::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

	char Utilities::getDelimiter() { return m_delimiter; }

}