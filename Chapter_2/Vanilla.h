#pragma once
#ifndef VANILLA_H
#define VANILLA_H

#include <PayOff1.h>

class VanillaOption
{
public:
	VanillaOption(PayOff& payOff, double const expiry);
	double getExpiry()const;
	double optionPayoff(double spot)const;
	~VanillaOption(){}

private:
	double _expiry;
	PayOff& _payOff;

};



#endif // !VANILLA_H

