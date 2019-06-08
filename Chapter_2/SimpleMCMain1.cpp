//
//
//	          	SimpleMCMain1.cpp
//
//     
//       requires Random1.cpp

//#include <Random1.h>
#include <SimpleMCMain1.h>
#include <iostream>
#include <cmath>


double SimpleMonteCarlo1(VanillaOption const& theOption,
						 double Spot, 
						 double Vol, 
						 double r, 
						 unsigned long NumberOfPaths,
						 GetOneGaussian& gaussian)
{
	double Expiry = theOption.getExpiry();
	double variance = Vol * Vol * Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = Spot * exp(r * Expiry + itoCorrection);
	double thisSpot;
	double runningSum=0;

	for (unsigned long i=0; i < NumberOfPaths; ++i)
	{
		double thisGaussian = gaussian.gaussian();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayoff = theOption.optionPayoff(thisSpot);
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r * Expiry);
	return mean;
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

