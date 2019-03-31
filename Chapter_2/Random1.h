//
//
//			               	Random1.h
//
//             


#ifndef RANDOM1_H
#define RANDOM1_H

double GetOneGaussianBySummation();
double GetOneGaussianByBoxMuller();
double GetOneGaussianByBoxMullerOrig();

class GetOneGaussian
{
public:
	virtual double gaussian() = 0;
	GetOneGaussian();
};

class GaussianBoxMuller :public GetOneGaussian
{
private:
	bool _status;
	double _result;
public:
	virtual double gaussian();
	GaussianBoxMuller();
};

class GaussianBoxMullerOrig :public GetOneGaussian
{
private:
	bool _status;
	double _result;
public:
	virtual double gaussian();
	GaussianBoxMullerOrig();
};

class GaussianSimul :public GetOneGaussian
{
public:
	virtual double gaussian();
	GaussianSimul();
};

#endif

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

