#pragma once
class Average
{
public:
	Average();
	~Average();

	void operator() (const int x);
	float getAverage() const;
	float getSum() const;
	int getSize() const;
private:
	float sum;
	int size;
};

