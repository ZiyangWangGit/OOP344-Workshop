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

#include <string>
#include <iomanip>
#include "Movie.h"

namespace seneca {
	Movie::Movie() {};

	const std::string& Movie::title() const {
		return movieTitle;
	}
	
	std::string Movie::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	Movie::Movie(const std::string& strMovie) {
		std::string tempMovie = strMovie;
		size_t delimiter = tempMovie.find(",");

		std::string substr = tempMovie.substr(0, delimiter);
		substr = trim(substr);
		movieTitle = substr;

		tempMovie.erase(0, delimiter + 1);
		delimiter = tempMovie.find(",");
		substr = tempMovie.substr(0, delimiter);
		substr = trim(substr);
		yearRelease = std::stoi(substr);

		tempMovie.erase(0, delimiter + 1);
		delimiter = tempMovie.find("\n");
		substr = tempMovie.substr(0, delimiter);
		substr = trim(substr);
		desc = substr;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.movieTitle << " | " << std::setw(4) 
	       << movie.yearRelease << " | " << movie.desc << std::endl;
		return os;
	}
}