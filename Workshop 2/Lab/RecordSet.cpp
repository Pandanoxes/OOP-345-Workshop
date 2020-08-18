#include "RecordSet.h"
#include <fstream>
#include <string>
#include <iostream>

namespace sdds
{
	//Defautl Constructor
	RecordSet::RecordSet() : m_record(nullptr), m_recordTrack(0) {}
	//End Default Constructor

	//Constructor
	RecordSet::RecordSet(const char *record) : m_recordTrack(0)
	{
		if (record[0] != '\0' || record != nullptr)
		{
			std::string temp;
			std::ifstream fin(record);
			if (fin.is_open())
			{
				while (fin.good())
				{
					getline(fin, temp, ' ');
					this->m_recordTrack++;
				}

				fin.seekg(0);
				this->m_record = nullptr;
				this->m_record = new std::string[this->m_recordTrack];
				int i = 0;

				while (fin.good())
					getline(fin, this->m_record[i++], ' ');
			}
		}
		else
			*this = RecordSet();
	} //End Constructor

	//Copy Constructor
	RecordSet::RecordSet(const RecordSet &src)
	{
		*this = src;
	} //End Copy Constructor

	//Copy assignment
	RecordSet &RecordSet::operator=(const RecordSet &src)
	{
		if (this != &src)
		{
			if (this->m_record != nullptr)
				delete[] this->m_record;
			this->m_recordTrack = src.m_recordTrack;
			this->m_record = nullptr;
			if (src.m_record != nullptr)
			{
				this->m_record = new std::string[this->m_recordTrack];
				for (size_t i = 0; i < this->m_recordTrack; i++)
					this->m_record[i] = src.m_record[i];
			}
		}
		return *this;
	} //End Copy assignment

	//Destructor
	RecordSet::~RecordSet()
	{
		delete[] this->m_record;
		this->m_record = nullptr;
	} //End Destructor

	//size function
	//Return m_recordTrack
	size_t RecordSet::size()
	{
		return this->m_recordTrack;
	} //End size function

	//getRecord function
	std::string RecordSet::getRecord(size_t num_record)
	{
		if (this->m_record == nullptr)
			return "";
		else
			return this->m_record[num_record];
	} //End getRecord function
} // namespace sdds