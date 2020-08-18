#include "Utilities.h"
#include <iostream>
#include <algorithm>
#include <sstream>

namespace sdds
{
	//createInstance function
	Vehicle *createInstance(std::istream &in)
	{
		Vehicle *myVehicle{nullptr};
		std::string data{""};
		std::getline(in, data);
		bool hasSpace = true;

		while (hasSpace)
		{
			if (data.length() > 0)
			{
				if (data[0] == ' ')
					data.erase(0, 1);
				else
					hasSpace = false;
			}
			else
				hasSpace = false;
		}
		std::stringstream dataToStream(data);

		if (data[0] == 'c' || data[0] == 'C')
			myVehicle = new Car(dataToStream);
		return myVehicle;
	} //End createInstance function
} // namespace sdds