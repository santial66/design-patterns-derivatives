#include "ParkMiller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;


ParkMiller::ParkMiller(long seed):_seed(seed)
{
	if (_seed == 0)
		_seed = 1;
}

long ParkMiller::getOneRandomInteger()
{
	long k;
	k = _seed / q;
	_seed = a * (_seed - k * q) - r * k;

	if (_seed < 0)
		_seed += m;

	return _seed;
}

void ParkMiller::setSeed(long seed)
{
	_seed = seed;
	if (_seed == 0)
		_seed = 1;
}

unsigned long ParkMiller::Max()
{
	return m - 1;
}

unsigned long ParkMiller::Min()
{
	return 1;
}
