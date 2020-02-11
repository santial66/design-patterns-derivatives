
#ifndef PARK_MILLER_H
#define PARK_MILLER_H
#include <Random2.h>

class ParkMiller
{
public:
	ParkMiller(long seed = 1);
	
	long getOneRandomInteger();
	void setSeed(long seed);

	static unsigned long Max();
	static unsigned long Min();

private:
	long _seed;

};

ParkMiller::ParkMiller()
{
}

ParkMiller::~ParkMiller()
{
}


#endif // !PARK_MILLER_H



