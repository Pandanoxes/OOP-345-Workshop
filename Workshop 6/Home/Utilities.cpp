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
		if (data.length() > 0)
		{
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
			//stringstream the data
			std::stringstream dataToStream(data);

			if (data[0] == 'c' || data[0] == 'C')
				myVehicle = new Car(dataToStream);
			else if (data[0] == 'r' || data[0] == 'R')
				myVehicle = new Racecar(dataToStream);
			else
				throw data[0];
		}
		return myVehicle;
	} //End createInstance function
} // namespace sdds