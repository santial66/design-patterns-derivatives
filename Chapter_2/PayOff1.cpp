#include "PayOff1.h"
#include <algorithm>


PayOffCall::PayOffCall(double strike):_strike(strike)
{
}

double PayOffCall::operator()(double spot) const
{
	return std::max(spot - _strike, 0.0);
}

PayOffCall * PayOffCall::clone()const
{
	return new PayOffCall(*this);
}

PayOffPut::PayOffPut(double strike):_strike(strike)
{
}

double PayOffPut::operator()(double spot) const
{
	return std::max(_strike - spot, 0.0);
}

PayOffPut * PayOffPut::clone()const
{
	return new PayOffPut(*this);
}
