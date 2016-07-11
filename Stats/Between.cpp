#include "Between.h"



Between::Between() : upper(-1), lower(-1)
{
}

Between::Between(int u, int l) : upper(u), lower(l) {}
Between::Between(const Between& b) : upper(b.upper), lower(b.lower) {}
const Between& Between::operator=(const Between& b) { if (this != &b) { upper = b.upper; lower = b.lower; } return *this; }

bool Between::operator() (int x) const
{
	return (lower <= x) && (x < upper);
}


void Between::update(int x)
{
	lower = upper;
	upper += x;
}

int Between::getUpper() const { return upper; }
int Between::getLower() const { return lower; }

Between::~Between()
{
}
