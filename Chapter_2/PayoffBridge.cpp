#include "PayoffBridge.h"

PayoffBridge::PayoffBridge(PayoffBridge const & orig)
{
	_payOff = orig._payOff->clone();
}

PayoffBridge::PayoffBridge(PayOff const & innerPayoff)
{
	_payOff = innerPayoff.clone();
}

PayoffBridge & PayoffBridge::operator=(PayoffBridge const & orig)
{
	if (this != &orig)
	{
		delete _payOff;
		_payOff = orig._payOff->clone();
	}
	return *this;
}

double PayoffBridge::operator()(double const Spot) const
{
	return (*_payOff)(Spot);
}

PayoffBridge::~PayoffBridge()
{
	delete _payOff;
}
