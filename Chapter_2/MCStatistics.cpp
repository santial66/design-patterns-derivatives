#include "MCStatistics.h"

StatisticsMean::StatisticsMean():
	_runningSum(0.0), _pathsDone(0)
{
}

void StatisticsMean::DumpOneResult(double result)
{
	++_pathsDone;
	_runningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::GetResultSoFar() const
{
	std::vector<std::vector<double> > results(1);
	results.reserve(1);
	results[0].push_back(_runningSum / _pathsDone);
	return results;
}

StatisticsMean * StatisticsMean::clone() const
{
	return new StatisticsMean(*this);
}
