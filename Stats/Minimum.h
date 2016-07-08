#pragma once
#include <limits>
class Minimum
{
public:
	Minimum();
	~Minimum();

	int getMin() const;
	void operator() (int x);

private:
	int min;
};

