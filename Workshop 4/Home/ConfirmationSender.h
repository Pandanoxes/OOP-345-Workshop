#pragma once
#ifndef _SDDS_COMFIRMATIONSENDER_H
#define _SDDS_COMFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation **c_reservations{nullptr};
		size_t sizes{0};

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender &);
		ConfirmationSender(ConfirmationSender &&) noexcept;
		~ConfirmationSender();
		ConfirmationSender &operator=(const ConfirmationSender &);
		ConfirmationSender &operator=(ConfirmationSender &&) noexcept;
		ConfirmationSender &operator+=(const Reservation &res);
		ConfirmationSender &operator-=(const Reservation &res);
		friend std::ostream &operator<<(std::ostream &, const ConfirmationSender &);
		size_t size() const;
	}; //End Class
} // namespace sdds
#endif