#include "DoubleDigital.h"

PayoffDoubleDigital::PayoffDoubleDigital(double lowerLevel, double upperLevel):
	_lowerLevel(lowerLevel), _upperLevel(upperLevel)
{
}

double PayoffDoubleDigital::operator()(double spot) const
{
	if (spot <= _lowerLevel)
		return 0.0;
	if (spot >= _lowerLevel)
		return 0.0;
	return 1.0;

}
