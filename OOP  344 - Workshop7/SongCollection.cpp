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
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "SongCollection.h"

namespace seneca {
	SongCollection::SongCollection(const std::string& filename) {

		std::ifstream file(filename);
		if (!file.is_open()) {
			throw "Can not open the file";
		}
		std::string line;
		while (std::getline(file, line)) {
			Song newSong;
			newSong.m_title = line.substr(0, 25);
			trim(newSong.m_title);
			newSong.m_artist = line.substr(25, 25);
			trim(newSong.m_artist);
			newSong.m_album = line.substr(50, 25);
			trim(newSong.m_album);
			newSong.m_releaseYear = line.substr(75, 5);
			trim(newSong.m_releaseYear);
			std::string temp;
			temp = line.substr(80, 5);
			temp = trim(temp);
			int tempLen = std::stoul(temp);
			newSong.m_length = tempLen;
			temp = line.substr(85, 5);
			temp = trim(temp);
			newSong.m_price = std::stod(temp);
			songs.push_back(newSong);
		}
	}

	std::string SongCollection::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	void SongCollection::display(std::ostream& out) const {
		std::for_each(songs.begin(), songs.end(), [&out](const Song& songs) {out << songs << std::endl; });
		size_t totalSeconds = std::accumulate(songs.begin(), songs.end(), 0,[](size_t total, const Song& s) { return total + s.m_length; });
		std::string totalLength = secondsToTimeString(totalSeconds);
		std::cout << "----------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|                                                        Total Listening Time: " << totalLength << " |" << std::endl;
		
	}

	void SongCollection::sort(const std::string name) {
		std::sort(songs.begin(), songs.end(), [=](const Song& s1, const Song& s2) {
			if (name == "title") {
				return s1.m_title < s2.m_title;
			}
			if (name == "album") {
				return s1.m_album < s2.m_album;
			}
			if (name == "length"){
				return s1.m_length < s2.m_length;
			}	
			return false;
		});
	}

	void SongCollection::cleanAlbum() {
		std::transform(songs.begin(), songs.end(), songs.begin(), [](Song& s) {
			if (s.m_album == "[None]") {
				s.m_album = "";
			}
			return s;
			});
	}

	bool SongCollection::inCollection(std::string artistName) const {
		if (std::any_of(songs.begin(), songs.end(), [=](Song s) {return s.m_artist == artistName; })) {
			return true;
		}
		return false;
	}

	std::list<Song> SongCollection :: getSongsForArtist(std::string artistName) const {
		std::list <Song> allSongs;
		std::copy_if(songs.begin(), songs.end(), std::back_inserter(allSongs), [=](const Song& s) {return s.m_artist == artistName; });
		return allSongs;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.m_title << " | " << std::setw(15)
			<< theSong.m_artist << " | " << std::setw(20) << theSong.m_album << " | " 
			<< std::setw(6) << std::right << theSong.m_releaseYear << " | " << secondsToTimeString(theSong.m_length)
			<< " | " << theSong.m_price << " |" ;
		return out;
	} 

	std::string secondsToTimeString(size_t seconds) {
		int hour = seconds / 3600;
		seconds %= 3600;
		int minutes = seconds / 60;
		int secondsLeft = seconds % 60;

		std::string secondsString = (secondsLeft < 10) ? "0" + std::to_string(secondsLeft) : std::to_string(secondsLeft);
		std::string time;
		if (hour > 0) {
			time += std::to_string(hour) + ":";
		}
		time += std::to_string(minutes) + ":" + secondsString;
		return time;
	}

}