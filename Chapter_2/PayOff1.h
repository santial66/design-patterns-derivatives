
#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:
	enum OptionType
	{
		call,
		put
	};
	PayOff(double strike, OptionType optType);
	double operator()(double spot)const;
	~PayOff(){}

private:
	double _strike;
	OptionType _optType;
};




#endif // !PAYOFF_H



