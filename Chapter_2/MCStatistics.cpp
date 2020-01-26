#include "MCStatistics.h"
#include <iostream>

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

void StatisticsMean::reset()
{
	_runningSum = 0.0;
	_pathsDone = 0;
}

StatisticsMean * StatisticsMean::clone() const
{
	return new StatisticsMean(*this);
}

void StatisticsMC::writeResults() const
{
	std::vector<std::vector<double> > tmp(this->GetResultSoFar());

	for (std::vector<std::vector<double> >::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		for (std::vector<double>::iterator jt = it->begin(); jt != it->end(); ++jt)
			std::cout << *jt << " ";
		std::cout << std::endl;
	}
}
