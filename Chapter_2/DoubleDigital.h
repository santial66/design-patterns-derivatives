#pragma once

#ifndef DOUBLE_DIGITAL_H
#define DOUBLE_DIGITAL_H

#include "PayOff1.h"

class PayoffDoubleDigital:public PayOff
{
public:
	PayoffDoubleDigital(double lowerLevel, double upperLevel);
	virtual double operator()(double spot)const;
	virtual PayoffDoubleDigital* clone()const;
	virtual ~PayoffDoubleDigital() {}

private:

	double _lowerLevel;
	double _upperLevel;

};



#endif // !DOUBLE_DIGITAL_H


