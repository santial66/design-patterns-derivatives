#include "DoubleDigital.h"

PayoffDoubleDigital::PayoffDoubleDigital(double lowerLevel, double upperLevel):
	_lowerLevel(lowerLevel), _upperLevel(upperLevel)
{
}

double PayoffDoubleDigital::operator()(double spot) const
{
	if (spot <= _lowerLevel)
		return 0.0;
	if (spot >= _upperLevel)
		return 0.0;
	return 1.0;

}

PayoffDoubleDigital* PayoffDoubleDigital::clone() const
{
	return new PayoffDoubleDigital(*this);
}
