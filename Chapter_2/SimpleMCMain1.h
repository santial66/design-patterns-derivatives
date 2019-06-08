
#ifndef SIMPLEMCMAIN1_H
#define SIMPLEMCMAIN1_H

#include <Random1.h>
#include <Vanilla.h>


double SimpleMonteCarlo1(VanillaOption const& theOption,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths,
	GetOneGaussian& gaussian);

#endif