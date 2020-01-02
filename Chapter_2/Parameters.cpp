#include "Parameters.h"

Parameters::Parameters(ParametersInner const & innerObject)
{
	_innerObjt = innerObject.clone();
}

Parameters::Parameters(Parameters const & orig)
{
	_innerObjt = orig._innerObjt->clone();
}

Parameters & Parameters::operator=(Parameters const & orig)
{
	if (this != &orig)
	{
		delete _innerObjt;
		_innerObjt = orig._innerObjt->clone();
	}
	// TODO: insert return statement here
	return *this;
}

double Parameters::Integral(const double time1, const double time2) const
{
	return _innerObjt->Integral(time1, time2);
}

double Parameters::IntegralSquare(const double time1, const double time2) const
{
	return _innerObjt->IntegralSquare(time1, time2);
}

ParametersConstant::ParametersConstant(double constant):
	_constant(constant), _constantSquare(constant * constant)
{
}

ParametersConstant * ParametersConstant::clone() const
{
	return new ParametersConstant(*this);
}

double ParametersConstant::Integral(const double time1, const double time2) const
{
	return _constant * (time2 - time1);
}

double ParametersConstant::IntegralSquare(const double time1, const double time2) const
{
	return _constantSquare * (time2 - time1);
}
