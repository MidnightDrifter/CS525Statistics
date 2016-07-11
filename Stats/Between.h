#pragma once

class Between {

public:
	Between();
	Between(int u, int l);
	Between(const Between& b);
	const Between& operator=(const Between& b);
	~Between();

	void update(int x);

	bool operator() (int x) const;
	int getUpper() const;
	int getLower() const;

private:
	int upper;
	int lower;
};
