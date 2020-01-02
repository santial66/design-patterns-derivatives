
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

class Parameters
{
public:
	Parameters(ParametersInner const& innerObject);
	Parameters(Parameters const& orig);
	Parameters& operator=(Parameters const& orig);
	virtual ~Parameters()
	{
		delete _innerObjt;
	}

	double Integral(const double time1, const double time2)const;
	double IntegralSquare(const double time1, const double time2)const;

	//double Mean(const double time1, const double time2)const;
	//double RootMeanSquare(const double time1, const double time2)const;

private:
	ParametersInner* _innerObjt;
};

class ParametersConstant : public ParametersInner
{
public:
	ParametersConstant(double constant);

	virtual ParametersConstant* clone()const;
	virtual double Integral(const double time1, const double time2)const;
	virtual double IntegralSquare(const double time1, const double time2)const;


private:
	double _constant;
	double _constantSquare;

};






#endif // !PARAMETERS_H



