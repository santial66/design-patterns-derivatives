//
//
//	          	Main1.cpp
//
//     
//

#include <iostream>
#include <SimpleMCMain1.h>
#include <ConvergenceTable.h>
#include <Vanilla.h>
#include <DoubleDigital.h>

int main()
{

	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	std::cout << "\nEnter expiry\n";
	std::cin >> Expiry;

	std::cout << "\nEnter strike\n";
	std::cin >> Strike;

	std::cout << "\nEnter spot\n";
	std::cin >> Spot;

	std::cout << "\nEnter vol\n";
	std::cin >> Vol;

	std::cout << "\nr\n";
	std::cin >> r;

	std::cout << "\nNumber of paths\n";
	std::cin >> NumberOfPaths;

	GaussianSimul gaussianSimul;

	PayOffCall callPayOff(Strike);

	VanillaOption callVanilla(callPayOff, Expiry);


	ParametersConstant volParam(Vol);
	ParametersConstant rParam(r);

	StatisticsMean gathererMean;
	ConvergenceTable gatherer(gathererMean);


	// simul
	SimpleMonteCarlo1(callVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianSimul,
		gatherer);

	std::cout << "the call price gaussianSimul is " << std::endl;
	gatherer.writeResults();



	GaussianBoxMuller gaussianBM;

	// BM
	gatherer.reset();
	SimpleMonteCarlo1(callVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianBM,
		gatherer);

	std::cout << "the call price gaussianBM is " << std::endl;
	gatherer.writeResults();



	double tmp;
	std::cout << "\nEnter a number to finish\n";
	std::cin >> tmp;

	return 0;
}

