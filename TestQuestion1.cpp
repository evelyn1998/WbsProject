//C++ Assignment
//Section A
//Question 1: C++11 Error Function, Standard Gaussian Probability and Cumulative Distribution
//Test function 


#include <iostream>
#include <cmath>
#include <climits>
#include "Question1.hpp"

int main()
{
	double inf = std::numeric_limits<double>::infinity(); //would like to stress test the program for large positive and negative value of the input arguments

	//Calculating and printing the standard normal probability density function for a range of arguments (using multiple inputs for a more accurate represenation in the report)
	for (int i = 0; i <= 4; ++i)
	{
		PrintPDF(i);
	}
	PrintPDF(inf);
	PrintPDF(-inf);

	std::cout << std::endl;

	//Calculating and printing the standard normal probability density function for a range of arguments (using multiple inputs for a more accurate representation in the report)
	for (int j = -3; j <= 3; ++j)
	{
		PrintCDF(j);
	}
	PrintCDF(inf);
	PrintCDF(-inf);

	
}