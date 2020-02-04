#include "Random2.h"

RandomBase::RandomBase(unsigned long dimensionality):
_dimensionality(dimensionality)
{
}

unsigned long RandomBase::getDimensionality() const
{
	return _dimensionality;
}


void RandomBase::getGaussians(std::vector<double>& variates)
{
	getUniforms(variates);

	for (std::vector<double>::iterator it = variates.begin(); it != variates.end(); ++it)
	{
		double x = *it;
		*it = InverseCumulativeNormal(x);
	}
}

void RandomBase::resetDimensionality(unsigned long newDimensionality)
{
	_dimensionality = newDimensionality;
}
