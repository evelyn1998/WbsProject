//C++ Assignment
//Section A
//Question 1: C++11 Error Function, Standard Gaussian Probability and Cumulative Distribution



#ifndef Question1_HPP
#define Question1_HPP
#include <iostream>
#include <cmath>

//Construct the standard normal probability density function

double n(double x)
{
	return std::exp(-x * x * 0.5) * (1.0 / std::sqrt(2.0 * 3.1415));

}

//Use the Error Function supported by C++11 in order to construct the standard normal cumulative distribution function

double N(double x)
{

	return 0.5 * (1 + std::erf(x / std::sqrt(2.0)));  //this expression was obtained after algebraic manipulations of the error function 

}




#endif
