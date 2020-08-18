#pragma once
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <vector>
#include <list>
namespace sdds
{
	struct Song
	{
		std::string m_artist{""};
		std::string m_title{""};
		std::string m_album{""};
		double m_price{0};
		std::string m_year{0};
		int m_lenght_song{0};
	};
	class SongCollection
	{
		std::vector<Song> songs;

	public:
		SongCollection(std::string);
		void display(std::ostream &out) const;
		void trim(std::string &);
		void sort(const std::string);
		void cleanAlbum();
		bool inCollection(const std::string str) const;
		std::list<Song> getSongsForArtist(const std::string str) const;
	}; //End Class
	std::ostream &operator<<(std::ostream &out, const Song &theSong);
} // namespace sdds
#endif