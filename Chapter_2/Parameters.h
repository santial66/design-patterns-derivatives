
#ifndef PARAMETERS_H
#define PARAMETERS_H

class ParametersInner
{
public:
	ParametersInner(){}
	virtual ParametersInner* clone()const = 0;
	virtual double Integral(const double time1, const double time2)const = 0;
	virtual double IntegralSquare(const double time1, const double time2)const = 0;	

private:
};





#endif // !PARAMETERS_H



