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


void SimpleMonteCarlo1(VanillaOption const& theOption,
						double Spot, 
						Parameters const& Vol,
						Parameters const& r,
						unsigned long NumberOfPaths,
						GetOneGaussian& gaussian,
						StatisticsMC& gatherer)
{
	double Expiry = theOption.getExpiry();
	double variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = Spot * exp(r.Integral(0,  Expiry) + itoCorrection);
	double thisSpot;
	double discounting = exp(-r.Integral(0, Expiry));
	
	for (unsigned long i=0; i < NumberOfPaths; ++i)
	{
		double thisGaussian = gaussian.gaussian();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayoff = theOption.optionPayoff(thisSpot);
		gatherer.DumpOneResult(discounting * thisPayoff);		
	}	
	return;
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
