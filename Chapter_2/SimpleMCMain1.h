
#ifndef SIMPLEMCMAIN1_H
#define SIMPLEMCMAIN1_H

#include <Random1.h>
#include <Vanilla.h>
#include <Parameters.h>
#include <MCStatistics.h>


void SimpleMonteCarlo1(VanillaOption const& theOption,
	double Spot,
	Parameters const& Vol,
	Parameters const& r,
	unsigned long NumberOfPaths,
	GetOneGaussian& gaussian,
	StatisticsMC& gatherer);

#endif