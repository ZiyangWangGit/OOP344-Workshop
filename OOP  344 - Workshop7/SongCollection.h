/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 17,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H


#include <iostream>
#include <list>
#include <vector>
#include <string>

namespace seneca {
    struct Song {
        std::string m_artist;
        std::string m_title;
        std::string m_album;
        double m_price;
        std::string m_releaseYear;
        size_t m_length; 
    };

    class SongCollection {
    private:
        std::vector<Song> songs;
    public:
        SongCollection(const std::string& filename);
        std::string trim(std::string& str);    
        void display(std::ostream& out) const;
        void sort(const std::string name);
        void cleanAlbum();
        bool inCollection(std::string artistName) const;
        std::list<Song> getSongsForArtist(std::string artistName) const;
    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);  
    std::string secondsToTimeString(size_t seconds);  

}

#endif