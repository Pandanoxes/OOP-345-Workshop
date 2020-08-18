#include "Restaurant.h"
namespace sdds
{
	//Constructor
	Restaurant::Restaurant(Reservation *reservations[], size_t cnt)
	{
		this->r_reservations = new Reservation[cnt];
		this->sizes = cnt;

		for (auto i = 0u; i < this->sizes; ++i)
			this->r_reservations[i] = *reservations[i];
	} //End Constructor

	//Copy Constructor
	Restaurant::Restaurant(const Restaurant &src)
	{
		*this = src;
	} //End Copy Constructor

	//Move Constructor
	Restaurant::Restaurant(Restaurant &&src) noexcept
	{
		*this = std::move(src);
	} //End Move Constructor

	//Copy Assignment
	Restaurant &Restaurant::operator=(const Restaurant &src)
	{
		if (this != &src)
		{
			delete[] this->r_reservations;
			this->r_reservations = nullptr;
			this->sizes = src.sizes;

			if (src.sizes != 0)
			{
				this->r_reservations = new Reservation[src.sizes];

				for (auto i = 0u; i < src.sizes; ++i)
					this->r_reservations[i] = src.r_reservations[i];
			}
		}
		return *this;
	} //End Copy Assignment

	//End Move Assignment
	Restaurant &Restaurant::operator=(Restaurant &&src) noexcept
	{
		if (this != &src)
		{
			delete[] this->r_reservations;
			this->r_reservations = src.r_reservations;
			this->sizes = src.sizes;
			src.r_reservations = nullptr;
			src.sizes = 0;
		}
		return *this;
	} //End Move Assignment

	//Deconstructor
	Restaurant::~Restaurant()
	{
		if (this->sizes != 0)
		{
			delete[] this->r_reservations;
		}
		this->r_reservations = nullptr;
	} //End Deconstructor

	//size function
	size_t Restaurant::size() const
	{
		return this->sizes;
	} //End size function

	//Overload operator<< for display
	std::ostream &operator<<(std::ostream &os, const Restaurant &restaurant_)
	{
		os << "--------------------------\nFancy Restaurant\n--------------------------" << std::endl;
		if (restaurant_.size() == 0)
			os << "The object is empty!" << std::endl;

		else
		{
			for (auto i = 0u; i < restaurant_.size(); i++)
				os << restaurant_.r_reservations[i];
		}

		os << "--------------------------" << std::endl;
		return os;
	} //End Overload operator<< for display
} // namespace sdds