#include "SongCollection.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
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
			out << song;
		});
	} //End display function

	//operator<< overload
	std::ostream &operator<<(std::ostream &out, const Song &theSong)
	{
		out << "| " << std::left << std::setw(20) << theSong.m_title << " | "
			<< std::setw(15) << theSong.m_artist << " | "
			<< std::setw(20) << theSong.m_album << " | "
			<< std::right << std::setw(6) << theSong.m_year << " | "
			<< (theSong.m_lenght_song / 60) << ":" << std::setfill('0') << std::setw(2) << (theSong.m_lenght_song % 60) << " | "
			<< std::setfill(' ') << theSong.m_price << " |" << std::endl;
		return out;
	} //operator<< overload

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