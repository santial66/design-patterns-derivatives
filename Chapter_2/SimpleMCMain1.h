
#ifndef SIMPLEMCMAIN1_H
#define SIMPLEMCMAIN1_H

#include <Random1.h>
#include <PayOff1.h>

double SimpleMonteCarlo1(double Expiry,
	PayOff const& payOff,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths,
	GetOneGaussian& gaussian);

#endif