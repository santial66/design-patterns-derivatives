#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(Wrapper<StatisticsMC> const & inner):
	_inner(inner), _stoppingPoint(2), _pathsDone(0)
{
}

void ConvergenceTable::DumpOneResult(double result)
{
	_inner->DumpOneResult(result);
	++_pathsDone;

	if (_pathsDone == _stoppingPoint)
	{
		_stoppingPoint *= 2;
		std::vector<std::vector<double> > thisResult(_inner->GetResultSoFar());

		for (std::vector<std::vector<double> >::iterator it = thisResult.begin(); it != thisResult.end(); ++it)
		{
			it->push_back(_pathsDone);
			_resultSoFar.push_back(*it);
		}

	}
	return;
}

std::vector<std::vector<double>> ConvergenceTable::GetResultSoFar() const
{
	std::vector<std::vector<double> > tmp(_resultSoFar);
	if (_stoppingPoint != _pathsDone * 2)
	{
		std::vector<std::vector<double> > thisResult(_inner->GetResultSoFar());

		for (std::vector<std::vector<double> >::iterator it = thisResult.begin(); it != thisResult.end(); ++it)
		{
			it->push_back(_pathsDone);
			tmp.push_back(*it);
		}
	}
	return tmp;
}

ConvergenceTable * ConvergenceTable::clone() const
{
	return new ConvergenceTable(*this);
}
