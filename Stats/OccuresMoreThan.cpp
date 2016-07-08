#include "OccuresMoreThan.h"




OccuresMoreThan::OccuresMoreThan()
{
}

bool OccuresMoreThan::isLargerThanMultiplicity(int x) const
{
	return x > mult;
}


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
void OccuresMoreThan::trimMap() { std::remove_if(map.begin(), map.end(), !isLargerThanMultiplicity); }
std::map<int, int> OccuresMoreThan::getMap() const { return map; }


OccuresMoreThan::~OccuresMoreThan()
{
}
