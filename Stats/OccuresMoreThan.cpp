#include "OccuresMoreThan.h"




OccuresMoreThan::OccuresMoreThan()
{
}


OccuresMoreThan::OccuresMoreThan(const OccuresMoreThan& c) : mult(c.mult), map() { map.insert(c.map.begin(), c.map.end()); }

void OccuresMoreThan::operator() (int x)
{
	std::map<int, int>::iterator it = map.find(x);
	if (it == map.end())
	{
		map.insert(std::pair<int, int>(x, 1));
	}

	else
	{
		(*it).second++;
	}

 
}

void OccuresMoreThan::setMultiplicity(int x) { mult = x; }

void OccuresMoreThan::trimMap()
{
	for (std::map<int, int>::iterator it = map.begin(); it != map.end();)
	{
		if ((*it).second <= mult) {
			std::map<int, int>::iterator temp = it;
			temp++;
			map.erase(it);
			it = temp;
		}

		else
		{
			it++;
		}

	}
}
std::map<int, int> OccuresMoreThan::getMap() const { return map; }


OccuresMoreThan::~OccuresMoreThan()
{
}
