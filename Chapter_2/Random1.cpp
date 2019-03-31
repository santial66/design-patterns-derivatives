//
//
//
//       				Random1.cpp
//
//           

//#include <Random1.h>
#include <cstdlib>
#include <cmath>
#include "Random1.h"



double GetOneGaussianBySummation()
{
	double result = 0;
	// rand(): Returns a pseudo-random integral number in the range between 0 and RAND_MAX.
	for(unsigned long j = 0; j < 12; ++j)
		// Generate a random number between 0 and 1.
		result += rand() / static_cast<double>(RAND_MAX);

	result -= 6.0;

	return result;

}


double GetOneGaussianByBoxMuller()
{
	double result;

	double x;
	double y;

	double sizeSquared;
	do
	{
		// Generate a number between -1 and 1
		x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		sizeSquared = x * x + y * y;
	}
	while
		(sizeSquared >= 1.0);

	result = x * sqrt(-2*log(sizeSquared) / sizeSquared);

	return result;
}


double GetOneGaussianByBoxMullerOrig()
{
	
	// Generate a number between 0 and 1
	auto x = rand() / static_cast<double>(RAND_MAX);
	auto y = rand() / static_cast<double>(RAND_MAX);

	const double PI = 3.141592653589793238463;
	auto result = std::sqrt(-2.0 * std::log(x)) * std::cos(2.0 * PI * y);
	

	return result;
}


/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/

double GaussianBoxMuller::gaussian()
{
	if (_status)
	{
		_status = false;
		return _result;
	}
	else
	{
		double x;
		double y;

		double sizeSquared;
		do
		{
			// Generate a number between -1 and 1
			x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
			y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
			sizeSquared = x * x + y * y;
		} while
			(sizeSquared >= 1.0);

		double result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
		_result = y * sqrt(-2 * log(sizeSquared) / sizeSquared);
		_status = true;

		return result;
	}
}

GaussianBoxMuller::GaussianBoxMuller():_status(false)
{
}

double GaussianBoxMullerOrig::gaussian()
{
	if (_status)
	{
		_status = false;
		return _result;
	}
	else
	{
		// Generate a number between 0 and 1
		auto x = rand() / static_cast<double>(RAND_MAX);
		auto y = rand() / static_cast<double>(RAND_MAX);

		const double PI = 3.141592653589793238463;
		auto result = std::sqrt(-2.0 * std::log(x)) * std::cos(2.0 * PI * y);
		_result = std::sqrt(-2.0 * std::log(x)) * std::sin(2.0 * PI * y);
		_status = true;


		return result;
	}
}

GaussianBoxMullerOrig::GaussianBoxMullerOrig():_status(false)
{
}

double GaussianSimul::gaussian()
{
	double result = 0;
	// rand(): Returns a pseudo-random integral number in the range between 0 and RAND_MAX.
	for (unsigned long j = 0; j < 12; ++j)
		// Generate a random number between 0 and 1.
		result += rand() / static_cast<double>(RAND_MAX);

	result -= 6.0;

	return result;
}

GaussianSimul::GaussianSimul()
{
}

GetOneGaussian::GetOneGaussian()
{
}
