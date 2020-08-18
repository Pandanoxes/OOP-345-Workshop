#pragma once
#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H
#include <stdexcept>
#include <iostream>
#include <string>

namespace sdds
{

	template <typename T>
	class Collection
	{
		std::string m_name{""};
		T *m_items{nullptr};
		size_t sizes{0};
		void (*observer)(const Collection<T> &, const T &){nullptr};

	public:
		Collection(std::string name) : m_name{name}, m_items{nullptr}, sizes{0}, observer{nullptr} {}
		Collection(const Collection &) = delete;
		Collection &operator=(const Collection &) = delete;
		//Destructor
		~Collection()
		{
			delete[] this->m_items;
		} //End Destructor

		//name function
		const std::string &name() const
		{
			return this->m_name;
		} //End name function

		//size function
		size_t size() const
		{
			return this->sizes;
		} //size function

		//setObserver function
		void setObserver(void (*observer)(const Collection<T> &, const T &))
		{
			this->observer = observer;
		} //End setObserver function

		//Overloaad operator+=
		Collection<T> &operator+=(const T &item)
		{
			bool same = false;
			for (size_t i = 0; i < this->sizes; i++)
			{
				if (item.title() == this->m_items[i].title())
				{
					same = true;
					break;
				}
			}
			if (!same)
			{
				T *temp = new T[this->sizes + 1];
				for (size_t i = 0; i < this->sizes; i++)
					temp[i] = this->m_items[i];

				temp[this->sizes] = item;

				delete[] this->m_items;
				this->m_items = nullptr;
				this->m_items = new T[++this->sizes];

				for (size_t i = 0; i < this->sizes; i++)
					this->m_items[i] = temp[i];

				delete[] temp;
				temp = nullptr;

				if (this->observer != nullptr)
					this->observer(*this, item);
			}
			return *this;
		} //End Overloaad operator+=

		//Overload operator[] (size_t idx)
		T &operator[](size_t idx) const
		{
			if (this->sizes <= idx)
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->sizes) + "] items.");
			else
			{
				return this->m_items[idx];
			}
		} //End Overload operator[] (size_t idx)

		//Overload operator[] (std::string title)
		T *operator[](std::string title) const
		{
			for (size_t i = 0; i < this->sizes; i++)
			{
				if (this->m_items[i].title() == title)
					return &this->m_items[i];
			}
			return nullptr;
		} //End Overload operator[] (std::string title)
	};	  //End Class
	//Template
	template <typename T>
	//Overload operator<<
	std::ostream &operator<<(std::ostream &os, const Collection<T> &item_)
	{
		for (size_t i = 0; i < item_.size(); i++)
			os << item_[i];
		return os;
	} //End Overload operator<<
} // namespace sdds
#endif
