#pragma once
class Size
{
public:
	Size();
	~Size();

	int getSize() const;
	void operator() (int x);

private:
	int size;

};

