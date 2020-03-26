//C++ Assignment
//Section A
//Question 5: The <tuple> Library
//Test Function

#include <iostream>
#include <tuple>
#include <cmath>
#include <string>
#include "Question5.hpp"
#include "Stopwatch.cpp"


int main()

{	//-----------------------------------------------------------------------------------------------------------------------
	//THE FOLLOWING LINES OF CODE USED FOR THE CONSTRUCTION OF QUESTION 5 PART (a)-PRINTING THE VALUES (u AND d) OF OUR TUPLE 
	//-----------------------------------------------------------------------------------------------------------------------

	std::cout << "QUESTION 5 PART A: " << std::endl;
	//Introducing the parameters that wil be used to calculate the up and down jumps
	double sigma = 0.25;
	double dt = 0.01;

	//Creating the "binomial" tuple
	TupleType binomial = std::make_tuple(u(sigma, dt), d(sigma, dt));

	//Accessing the elements of the "binomial" tuple
	std::cout << "The up jump parameter is: " << std::get<0>(binomial) << std::endl;
	std::cout << "The down jump parameter is: " << std::get<1>(binomial) << std::endl;

	//------------------------------------------------------------------------------
	//THE FOLLOWING LINES OF CODE ARE USED FOR THE CONSTRUCTION OF QUESTION 5 PART (b)
	//--------------------------------------------------------------------------------
	//MEASURING THE PERFORMANCE OF A TUPLE INSIDE A FOR LOOP
	//--------------------------------------------------------------------------------

	std::cout << std::endl << "QUESTION 5 PART B: " << std::endl;

	using TupleTest = std::tuple<std::string, int>;

	//Creating a for loop to loop through the tuple
	for (int i = 10; i <= 10000000; i = i * 10)

	{
		//Initialising the stopwatch
		Stopwatch<> sw;
		sw.Start();

		for (int n = 0; n < i; n++)
		{
			//Creating the tuple
			TupleTest myTuple(std::string("A"), 1);

			//Accessing the elements of a tuple - will print A 1 
			//std::cout << "The first element of the tuple is: " << std::get<0>(myTuple) << std::endl;
			//std::cout << "The second element of the tuple is: " << std::get<1>(myTuple) << std::endl;

			//Modifying the elements of a tuple and accessing them - will print B 3
			std::get<0>(myTuple) = std::string("B");
			std::get<1>(myTuple) = 2;
			//std::cout << "The modified first element of the tuple is: " << std::get<0>(myTuple) << std::endl;
			//std::cout << "The modified second element of the tuple is: " << std::get<1>(myTuple) << std::endl;
		}

		std::cout << "Number of iterations: " << i << std::endl;
		sw.Stop();
		std::cout << "Elapsed time in seconds is: " << sw.GetTime() << std::endl;
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------
	//THE FOLLOWING LINES OF CODE ARE USED TO CONSTRUCT EXERCISE 5 PART (c)
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//CREATING A TUPLE WHICH MODELS THE BLACK - SCHOLES PARAMETERS (STRIKE PRICE - K, INTEREST RATE - r, DIVIDEND YIELD - y, MATURITY - T, VOLATILITY - sig)
	//------------------------------------------------------------------------------------------------------------------------------------------------------

		std::cout << std::endl << "QUESTION 5 PART C: " << std::endl;

		using TupleBS = std::tuple<double, double, double, double, double>;

		//Introduce the Black Scholes parameters
		double K = 120.0;
		double r = 0.03;
		double y = 0.01;
		double T = 0.5;
		double sig = 0.35;

		//Creating the tuple
		TupleBS myBSTuple = std::make_tuple(K, r, y, T, sig);

		//Accessing the elements of the tuple
		std::cout << "The first parameter of the Black-Scholes formula is the strike price: " << std::get<0>(myBSTuple) << std::endl;
		std::cout << "The second parameter of the Black-Scholes formula is the interest rate: " << std::get<1>(myBSTuple) << std::endl;
		std::cout << "The third parameter of the Black-Scholes formula is the dividend yield: " << std::get<2>(myBSTuple) << std::endl;
		std::cout << "The fourth parameter of the Black-Scholes formula is the maturity: " << std::get<3>(myBSTuple) << std::endl;
		std::cout << "The fifth parameter of the Black-Scholes formula is the volatility: " << std::get<4>(myBSTuple) << std::endl;


}