
#ifndef SIMPLEMCMAIN1_H
#define SIMPLEMCMAIN1_H

#include <Random1.h>

double SimpleMonteCarlo1(double Expiry,
	double Strike,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths,
	GetOneGaussian& gaussian);

#endif