
#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H

#include <MCStatistics.h>
#include <Wrapper.h>
#include <vector>

class ConvergenceTable : public StatisticsMC
{
public:
	ConvergenceTable(Wrapper<StatisticsMC> const& inner);

	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double> > GetResultSoFar() const;
	virtual void reset();

	virtual ConvergenceTable* clone()const;

private:
	Wrapper<StatisticsMC> _inner;
	std::vector<std::vector<double> > _resultSoFar;
	unsigned long _stoppingPoint;
	unsigned long _pathsDone;
};




#endif // !CONVERGENCE_TABLE_H




