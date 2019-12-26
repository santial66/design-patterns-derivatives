#include "Vanilla.h"



VanillaOption::VanillaOption(PayoffBridge const& payOff, double const expiry):
	_payOff(payOff), _expiry(expiry)
{	
}

double VanillaOption::getExpiry() const
{
	return _expiry;
}

double VanillaOption::optionPayoff(double spot)const
{
	return _payOff(spot);
}


