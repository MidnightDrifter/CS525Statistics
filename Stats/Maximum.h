#pragma once
#include <limits>
class Maximum
{
public:
	Maximum();
	~Maximum();

	void operator() (const int x);
	int getMax() const;


private:
	int max;
};

