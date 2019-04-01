#include "PayOff1.h"
#include <algorithm>

PayOff::PayOff(double strike, OptionType optType):
	_strike(strike), _optType(optType)
{
}

double PayOff::operator()(double spot) const
{
	switch (_optType)
	{
	case PayOff::call:
		return std::max(spot - _strike, 0.0);
	case PayOff::put:
		return std::max(_strike - spot, 0.0);
	default:
		throw("unknown option type found");
	}
}
