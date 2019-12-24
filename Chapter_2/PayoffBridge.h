
#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include <PayOff1.h>

class PayoffBridge
{
public:
	PayoffBridge(PayoffBridge const& orig);
	PayoffBridge(PayOff const& innerPayoff);
	PayoffBridge& operator=(PayoffBridge const& orig);

	double operator()(double const Spot)const;
	~PayoffBridge();

private:
	PayOff* _payOff;
};



#endif // !PAYOFFBRIDGE_H

