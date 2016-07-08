#pragma once
#include <map>
#include <algorithm>
class OccuresMoreThan
{
public:
	OccuresMoreThan();
	~OccuresMoreThan();

	void operator() (int x);
	void setMultiplicity(int x);
	void trimMap();
	std::map<int, int> getMap() const;
	bool isLargerThanMultiplicity(int x) const;


private:
	int mult;
	std::map<int, int> map;

};

