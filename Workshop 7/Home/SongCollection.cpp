#include "SongCollection.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>

namespace sdds
{
	//Constructor
	SongCollection::SongCollection(std::string filename)
	{
		std::ifstream file(filename);
		if (!file)
			throw "ERROR: Cannot open file [" + filename + "].";
		while (file)
		{
			std::string tempLine{""};
			std::getline(file, tempLine);
			if (tempLine.length() != 0)
			{
				Song tempSong = Song();
				tempSong.m_title = tempLine.substr(0, 25);
				this->trim(tempSong.m_title);
				tempLine.erase(0, 25);

				tempSong.m_artist = tempLine.substr(0, 25);
				this->trim(tempSong.m_artist);
				tempLine.erase(0, 25);

				tempSong.m_album = tempLine.substr(0, 25);
				this->trim(tempSong.m_album);
				tempLine.erase(0, 25);

				tempSong.m_year = tempLine.substr(0, 5);
				this->trim(tempSong.m_year);
				tempLine.erase(0, 5);

				tempSong.m_lenght_song = std::stoi(tempLine.substr(0, 5));
				tempLine.erase(0, 5);

				tempSong.m_price = std::stod(tempLine.substr(0, 5));
				songs.push_back(tempSong);
			}
		}
	} //End constructor

	//display function
	void SongCollection::display(std::ostream &out) const
	{
		std::for_each(this->songs.begin(), this->songs.end(), [&out](const Song song) {
			out << song << std::endl;
		});
		int length{0};
		std::for_each(this->songs.begin(), this->songs.end(), [&length](const Song song) {
			length += song.m_lenght_song;
		});
		int hour = length / 3600;
		length %= 3600;
		int minute = length / 60;
		length %= 60;
		out << std::setw(89) << std::setfill('-') << '\n'
			<< std::setfill(' ');
		out << "| " << std::setw(76) << "Total Listening Time:" << std::setw(2) << hour << ':' << std::setw(2) << minute << ':' << std::setw(2) << length << " |" << std::endl;
	} //End display function

	//operator<< overload
	std::ostream &operator<<(std::ostream &out, const Song &theSong)
	{
		out << "| " << std::left << std::setw(20) << theSong.m_title << " | "
			<< std::setw(15) << theSong.m_artist << " | "
			<< std::setw(20) << theSong.m_album << " | "
			<< std::right << std::setw(6) << theSong.m_year << " | "
			<< (theSong.m_lenght_song / 60) << ":" << std::setfill('0') << std::setw(2) << (theSong.m_lenght_song % 60) << " | "
			<< std::setfill(' ') << theSong.m_price << " |";
		return out;
	} //operator<< overload

	//sort function
	void SongCollection::sort(const std::string str)
	{
		if (str.compare("length") == 0)
		{ //Sort by lenght
			std::sort(this->songs.begin(), this->songs.end(), [](const auto &lsong, const auto &rsong) {
				return lsong.m_lenght_song < rsong.m_lenght_song;
			});
		}
		else if (str.compare("title") == 0)
		{ //Sort by title
			std::sort(this->songs.begin(), this->songs.end(), [](const auto &lsong, const auto &rsong) {
				return lsong.m_title.compare(rsong.m_title) < 0;
			});
		}
		else if (str.compare("album") == 0)
		{ //Sort by album
			std::sort(this->songs.begin(), this->songs.end(), [](const auto &lsong, const auto &rsong) {
				return lsong.m_album.compare(rsong.m_album) < 0;
			});
		}
	} //End sort function

	//cleanAlbum function
	void SongCollection::cleanAlbum()
	{
		std::for_each(this->songs.begin(), this->songs.end(), [](Song &song) {
			if (song.m_album.compare("[None]") == 0)
				song.m_album = "";
		});
	} //End cleanAlbum function

	//inCollection function
	bool SongCollection::inCollection(const std::string str) const
	{
		auto isFoundd = std::find_if(this->songs.begin(), this->songs.end(), [&](const Song song) {
			return song.m_artist.compare(str) == 0;
		});
		return (isFoundd != this->songs.end()) ? true : false;
	} //End inCollection function

	//getSongsForArtist function
	std::list<Song> SongCollection::getSongsForArtist(const std::string str) const
	{
		std::list<Song> list_songs;
		std::copy_if(this->songs.begin(), this->songs.end(), back_inserter(list_songs), [=](Song song) {
			return (song.m_artist.compare(str) == 0);
		});
		return list_songs;
	} //End getSongsForArtist function

	//trim function
	void SongCollection::trim(std::string &str)
	{
		bool hasSpace = true;
		while (hasSpace)
		{
			if (str.length() > 0)
			{
				if (str[0] == ' ')
					str.erase(0, 1);
				else if (str[str.length() - 1] == ' ')
					str.erase(str.length() - 1, str.length());
				else
					hasSpace = false;
			}
			else
				hasSpace = false;
		}
	} //End trim function
} // namespace sdds