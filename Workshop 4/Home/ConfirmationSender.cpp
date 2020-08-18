#include "ConfirmationSender.h"

namespace sdds
{
	//Default COnstructor
	ConfirmationSender::ConfirmationSender() : c_reservations{nullptr}, sizes{0} {}
	//End Default Constructor

	//Copy Constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender &src)
	{
		*this = src;
	} //End Copy Constructor

	//Move Constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender &&src) noexcept
	{
		*this = std::move(src);
	} //End Move Constructor

	//Deconstructor
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] this->c_reservations;
		this->c_reservations = nullptr;
	} //End Deconstructor

	//Copy Assignment
	ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &src)
	{
		if (this != &src)
		{
			delete[] this->c_reservations;
			this->c_reservations = nullptr;
			this->sizes = src.sizes;
			if (src.sizes != 0)
			{
				this->c_reservations = new const Reservation *[src.sizes];
				for (auto i = 0u; i < src.sizes; ++i)
					this->c_reservations[i] = src.c_reservations[i];
			}
		}
		return *this;
	} //End Copy Assignment

	//End Move Assignment
	ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&src) noexcept
	{
		if (this != &src)
		{
			delete[] this->c_reservations;
			this->c_reservations = src.c_reservations;
			this->sizes = src.sizes;
			src.c_reservations = nullptr;
			src.sizes = 0;
		}
		return *this;
	} //End Move Assignment

	//Overload operator+= for adding Reservation
	ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res)
	{
		bool same = false;
		for (auto i = 0u; i < this->sizes; i++)
		{
			if (this->c_reservations[i] == &res)
			{
				same = true;
				break;
			}
		}

		if (!same)
		{
			const Reservation **temp = new const Reservation *[this->sizes + 1];
			for (auto i = 0u; i < this->sizes; i++)
				temp[i] = this->c_reservations[i];

			temp[this->sizes] = &res;

			delete[] this->c_reservations;
			this->c_reservations = nullptr;
			this->c_reservations = new const Reservation *[++this->sizes];

			for (auto i = 0u; i < this->sizes; i++)
				this->c_reservations[i] = temp[i];

			delete[] temp;
			temp = nullptr;
		}

		return *this;
	}

	//Overload operator-= for removing Reservation
	ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res)
	{
		if (this->sizes != 0)
		{
			for (auto i = 0u; i < this->sizes; i++)
			{
				if (this->c_reservations[i] == &res)
				{
					this->c_reservations[i] = nullptr;

					const Reservation **temp = new const Reservation *[this->sizes - 1];

					for (auto j = 0u; j < this->sizes; j++)
						if (this->c_reservations[j] != nullptr)
							temp[(j == i + 1) ? j - 1 : j] = this->c_reservations[j];

					delete[] this->c_reservations;
					this->c_reservations = nullptr;
					this->c_reservations = new const Reservation *[--this->sizes];

					for (auto i = 0u; i < this->sizes; i++)
						this->c_reservations[i] = temp[i];

					delete[] temp;
					temp = nullptr;

					break;
				}
			}
		}
		return *this;
	}

	//size function
	size_t ConfirmationSender::size() const
	{
		return this->sizes;
	} //End size function

	//Overload operator<< for display
	std::ostream &operator<<(std::ostream &os, const ConfirmationSender &confirmationSender_)
	{
		os << "--------------------------\nConfirmations to Send\n--------------------------" << std::endl;
		if (confirmationSender_.size() == 0)
			os << "The object is empty!" << std::endl;

		else
		{
			for (auto i = 0u; i < confirmationSender_.size(); i++)
				os << *confirmationSender_.c_reservations[i];
		}

		os << "--------------------------" << std::endl;
		return os;
	} //Overload operator<< for display
} // namespace sdds