//C++ Assignment
//Section A
//Question 2: One-Factor Option Pricing and Sensitivities
//Test function

#include <iostream>
#include <cmath>
#include <climits>
#include "Question2.hpp"


int main()
{
	std::cout << "QUESTION 2 (b): " << std::endl;

	//Calculating and printing the value of a European call and a European put today, for the first set of parameters: S=£150, K=£120, r=5%, y=1%, sigma=25%, T=0.5 years
	std::cout << "Option prices for the first set of parameters: " << std::endl;

	printCall(150, 120, 0.05, 0.01, 0.25, 0.5, 0.0);

	printPut(150, 120, 0.05, 0.01, 0.25, 0.5, 0.0);

	

	//Calculating and printing the value of a European call and a European put today, for the second set of parameters:  S=£210, K=£200, r=7%, y=2%, sigma=30%, T=1 year
	std::cout << std::endl << "Option prices for the second set of parameters: " << std::endl; 

	printCall(210, 200, 0.07, 0.02, 0.30, 1, 0.0);

	printPut(210, 200, 0.07, 0.02, 0.30, 1, 0.0);

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------- 

	std::cout << std::endl << "QUESTION 2 (e): " << std::endl;

	//Calculating and printing the deltas of a European call and a European put for the first set of parameters: S=£150, K=£120, r=5%, y=1%, sigma=25%, T=0.5 years
	std::cout << "Deltas for the first set of parameters: " << std::endl;

	printDeltaCall(150, 120, 0.05, 0.01, 0.25, 0.5, 0.0);
	 
	printDeltaPut(150, 120, 0.05, 0.01, 0.25, 0.5, 0.0);



	//Calculating and printing the value of a European call and a European put today, for the second set of parameters:  S=£210, K=£200, r=7%, y=2%, sigma=30%, T=1 year
	std::cout << std::endl << "Deltas for the second set of parameters: " << std::endl;

	printDeltaCall(210, 200, 0.07, 0.02, 0.30, 1, 0.0);

	printDeltaPut(210, 200, 0.07, 0.02, 0.30, 1, 0.0);



	//Calculating and printing the gamma of European call and put options for the first set of parameters S=£150, K=£120, r=5%, y=1%, sigma=25%, T=0.5 years
	std::cout << std::endl << "Gammas for the first set of parameters: " << std::endl;

	printGamma(150, 120, 0.05, 0.01, 0.25, 0.5, 0.0);

	//Calculating and printing the gamma of European call and put options for the second set of parameters S=£210, K=£200, r=7%, y=2%, sigma=30%, T=1 year
	std::cout << std::endl << " Gammas for the second set of parameters: " << std::endl;

	printGamma(210, 200, 0.07, 0.02, 0.30, 1, 0.0);

}