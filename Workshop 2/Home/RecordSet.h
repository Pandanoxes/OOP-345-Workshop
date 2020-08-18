#pragma once
#ifndef _SDDS_RECORDSET_H
#define _SDDS_RECORDSET_H
#include <iostream>

namespace sdds
{
	class RecordSet
	{
		std::string *m_record = nullptr;
		size_t m_recordTrack{0};

	public:
		RecordSet();
		RecordSet(const char *);
		RecordSet(const RecordSet &);
		RecordSet &operator=(const RecordSet &);
		~RecordSet();
		size_t size();
		std::string getRecord(size_t);
		RecordSet(RecordSet &&);
		RecordSet &operator=(RecordSet &&);
	}; //End class
} // namespace sdds
#endif
