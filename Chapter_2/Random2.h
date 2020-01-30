
#ifndef RANDOM2_H
#define RANDOM2_H

#include <vector>

class RandomBase
{
public:
	RandomBase(unsigned long dimensionality);

	unsigned long getDimensionality()const;

	virtual RandomBase* clone()const = 0;
	virtual void getUniforms(std::vector<double>& variates) = 0;
	virtual void skip(unsigned long numberOfPaths) = 0;
	virtual void setSeed(unsigned long seed) = 0;
	virtual void reset() = 0;

	virtual void getGaussians(std::vector<double> variates);
	virtual void resetDimensionality(unsigned long newDimensionality);

private:
	unsigned long _dimensionality;

};




#endif // !RANDOM2_H




