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
		map.insert(std::pair<int, int>(x, 0));
	}

	else
	{
		(*it).second++;
	}

 
}

void OccuresMoreThan::setMultiplicity(int x) { mult = x; }

void OccuresMoreThan::trimMap()
{
	for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		if ((*it).second < mult) {
			map.erase(it);
		}

	}
}
std::map<int, int> OccuresMoreThan::getMap() const { return map; }


OccuresMoreThan::~OccuresMoreThan()
{
}
