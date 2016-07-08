#pragma once
#include "Average.h"
#include <math.h>
class Deviation
{

	/*
	   Deviation() - standard deviation is a measure of how much the data is 
                 dispersed from the average. 
                 formula Deviation( x_1, ... , x_n ) = sqrt ( 1/n * sum ( x_i -a )^2 )
                 Where 'a' is the Average.
                 Basically deviation is an average of the squares of the distances to the average.
	
	*/
public:
	Deviation();
	~Deviation();

	void operator() (int x);
	float getDev() const;

private:
	Average avg;
	float sumSquares;
	//float dev;


};

