#pragma once
#ifndef VANILLA_H
#define VANILLA_H

#include <PayoffBridge.h>

class VanillaOption
{
public:
	VanillaOption(PayoffBridge const& payOff, double const expiry);
	
	
	double getExpiry()const;
	double optionPayoff(double spot)const;
	~VanillaOption() {}

private:
	double _expiry;
	PayoffBridge _payOff;

};



#endif // !VANILLA_H

