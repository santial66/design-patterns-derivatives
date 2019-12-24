#include "Vanilla.h"



VanillaOption::VanillaOption(PayOff & payOff, double const expiry):
	_expiry(expiry)
{
	_payOff = payOff.clone();
}

VanillaOption::VanillaOption(VanillaOption const & orig)
{
	_expiry = orig._expiry;
	_payOff = orig._payOff->clone();
}

VanillaOption & VanillaOption::operator=(VanillaOption const & orig)
{
	if (this != &orig)
	{
		_expiry = orig._expiry;
		delete _payOff;
		_payOff = orig._payOff->clone();
	}
	return *this;
}

double VanillaOption::getExpiry() const
{
	return _expiry;
}

double VanillaOption::optionPayoff(double spot)const
{
	return (*_payOff)(spot);
}

VanillaOption::~VanillaOption()
{
	delete _payOff;
}
