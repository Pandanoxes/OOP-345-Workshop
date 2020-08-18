#include "Autoshop.h"
namespace sdds
{
	//Overload operator +=
	Autoshop &Autoshop::operator+=(Vehicle *theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);
		return *this;
	} //End Overload operator +=

	//display function
	void Autoshop::display(std::ostream &out) const
	{
		out << "--------------------------------\n"
			<< "| Cars in the autoshop!        |\n"
			<< "--------------------------------" << std::endl;
		for (auto i = this->m_vehicles.begin(); i != this->m_vehicles.end(); i++)
		{
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	} //End display function

	//Destructor
	Autoshop::~Autoshop()
	{
		while (!this->m_vehicles.empty())
		{
			delete this->m_vehicles.back();
			this->m_vehicles.pop_back();
		}
	} //End Destructor
} // namespace sdds