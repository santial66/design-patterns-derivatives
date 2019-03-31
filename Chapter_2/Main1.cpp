//
//
//	          	Main1.cpp
//
//     
//

#include <iostream>
#include <SimpleMCMain1.h>

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

	// simul
	double result = SimpleMonteCarlo1(Expiry,
		Strike,
		Spot,
		Vol,
		r,
		NumberOfPaths,
		gaussianSimul);

	std::cout << "the price gaussianSimul is " << result << "\n";

	GaussianBoxMuller gaussianBM;

	// BM
	result = SimpleMonteCarlo1(Expiry,
		Strike,
		Spot,
		Vol,
		r,
		NumberOfPaths,
		gaussianBM);

	std::cout << "the price gaussianBM is " << result << "\n";

	GaussianBoxMullerOrig gaussianBMorig;

	// BM original
	result = SimpleMonteCarlo1(Expiry,
		Strike,
		Spot,
		Vol,
		r,
		NumberOfPaths,
		gaussianBMorig);

	std::cout << "the price gaussianBMorig is " << result << "\n";

	double tmp;
	std::cin >> tmp;

	return 0;
}

