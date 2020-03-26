//C++ Assignment
//Section A
//Question 5: The <tuple> Library
//Header file

#ifndef Question5_HPP
#define Question5_HPP
#include <iostream>
#include <tuple>
#include <cmath>

//---------------------------------------------------------------------------------------------------
//THE FOLLOWING LINES OF CODE ARE USED FOR THE CONSTRUCTION OF QUESTION 5 PART (a)
//----------------------------------------------------------------------------------------------------
//CREATING A TUPLE CONTAINING THE UP AND DOWN JUMP PARAMETERS (CRR) IN THE BINOMIAL METHOD 
//----------------------------------------------------------------------------------------------------
//CREATING TWO FREE FUNCTIONS FOR u AND d WITH INPUT ARGUMENTS THE VOLATILITY(sigma) AND TIMESTEP(dt)
//----------------------------------------------------------------------------------------------------

using TupleType = std::tuple<double, double>;

	//Introducing the up and down parameters according to CRR 
	double u(double sigma, double dt)
	{
		return std::exp(sigma * std::sqrt(dt));
	}

	double d(double sigma, double dt)
	{
		return std::exp(-sigma * std::sqrt(dt));
	}

#endif;