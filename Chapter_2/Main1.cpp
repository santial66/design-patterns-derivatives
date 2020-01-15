//
//
//	          	Main1.cpp
//
//     
//

#include <iostream>
#include <SimpleMCMain1.h>
#include <Vanilla.h>
#include <DoubleDigital.h>

int main()
{

	double Expiry;
	double Strike;
	double lowerLevel;
	double upperLevel;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	std::cout << "\nEnter expiry\n";
	std::cin >> Expiry;

	std::cout << "\nEnter strike\n";
	std::cin >> Strike;

	std::cout << "\nEnter lower level\n";
	std::cin >> lowerLevel;

	std::cout << "\nEnter upper level\n";
	std::cin >> upperLevel;

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
	PayOffPut putPayOff(Strike);
	PayoffDoubleDigital doubleDigital(lowerLevel, upperLevel);

	VanillaOption callVanilla(callPayOff, Expiry);
	VanillaOption putVanilla(putPayOff, Expiry);
	VanillaOption doubleDigitalVanilla(doubleDigital, Expiry);

	ParametersConstant volParam(Vol);
	ParametersConstant rParam(r);

	StatisticsMean gatherer;

	// simul
	SimpleMonteCarlo1(callVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianSimul,
		gatherer);

	std::cout << "the call price gaussianSimul is " << (gatherer.GetResultSoFar())[0][0] << "\n";

	gatherer.reset();
	SimpleMonteCarlo1(putVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianSimul,
		gatherer);

	std::cout << "the put price gaussianSimul is " << (gatherer.GetResultSoFar())[0][0] << "\n";

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

	std::cout << "the call price gaussianBM is " << (gatherer.GetResultSoFar())[0][0] << "\n";

	gatherer.reset();
	SimpleMonteCarlo1(putVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianBM,
		gatherer);

	std::cout << "the put price gaussianBM is " << (gatherer.GetResultSoFar())[0][0] << "\n";

	GaussianBoxMullerOrig gaussianBMorig;

	// BM original
	gatherer.reset();
	SimpleMonteCarlo1(callVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianBMorig,
		gatherer);

	std::cout << "the call price gaussianBMorig is " << (gatherer.GetResultSoFar())[0][0] << "\n";

	gatherer.reset();
	SimpleMonteCarlo1(putVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianBMorig,
		gatherer);

	std::cout << "the put price gaussianBMorig is " << (gatherer.GetResultSoFar())[0][0] << "\n";

	gatherer.reset();
	SimpleMonteCarlo1(doubleDigitalVanilla,
		Spot,
		volParam,
		rParam,
		NumberOfPaths,
		gaussianBM,
		gatherer);

	std::cout << "the double digital price gaussianBM is " << (gatherer.GetResultSoFar())[0][0] << "\n";

	double tmp;
	std::cout << "\nEnter a number to finish\n";
	std::cin >> tmp;

	return 0;
}

