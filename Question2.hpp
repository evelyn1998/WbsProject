//C++ Assignment
//Section A
//Question 2: One-Factor Option Pricing and Sensitivities
//Header file 

#ifndef Question2_HPP
#define Question2_HPP
#include <iostream>
#include <cmath>
#include "Question1.hpp"


//--------------------------------------------------------------------------------
//THE FOLLOWING LINES OF CODE ARE USED FOR THE CONSTRUCTION OF EXERCISE 2 PART (a)
//--------------------------------------------------------------------------------

//Creating a free functin to calculate the price of European call option
double call(double S, double K, double r, double y, double sigma, double T, double t)  //S-asset price, K-strike price, r-riskfree rate, y-dividend yield, sigma-volatility, T-maturity, t-time to maturity
{

	double d_1 = (std::log(S / K) + (r - y + (sigma * sigma) / 2) * (T - t)) / (sigma * std::sqrt(T - t));  
	
	double d_2 = d_1 - sigma * std::sqrt(T - t);

	return S * std::exp(-y * (T-t)) *  N(d_1) - K * std::exp(-r * (T - t)) * N(d_2); //calculating the value of a European call option according to the Black Scholes formula
}


//Creating a free function to calculate the price of a European put option
double put(double S, double K, double r, double y, double sigma, double T, double t)
{
	double d_1 = (std::log(S / K) + (r - y  + (sigma * sigma) / 2) * (T - t)) / (sigma * std::sqrt(T - t));

	double d_2 = d_1 - sigma * std::sqrt(T - t);

	return K * std::exp(-r * (T - t)) * N(-d_2) - S * std::exp(-y * (T - t))* N(-d_1);  //calculating the value of a European put option according to the Black Scholes formula
}


//-----------------------------------------------------------------------------------------
//THE FOLLOWING LINES OF CODE ARE USED FOR THE CONSTRUCTION OF EXERCISE 2 PART (d)
//------------------------------------------------------------------------------------------


//Creating a free function to calculate the delta of a European call option
double delta_call(double S, double K, double r, double y, double sigma, double T, double t)
{
	double d_1 = (std::log(S / K) + (r - y + (sigma * sigma) / 2) * (T - t)) / (sigma * std::sqrt(T - t));

	return std::exp(-y*(T-t)) * N(d_1);  //see report for further details of this calculations

}

//Creating a free function to calculate the delta of a European put option 
double delta_put(double S, double K, double r, double y, double sigma, double T, double t)
{
	double d_1 = (std::log(S / K) + (r - y  + (sigma * sigma) / 2) * (T - t)) / (sigma * std::sqrt(T - t));

	return std::exp(-y * (T - t)) * (N(d_1) - 1);
}

//Creating a free function to calculate the gamma of a European call option and a European put option
double gamma(double S, double K, double r, double y, double sigma, double T, double t)
{
	double d_1 = (std::log(S / K) + (r - y + (sigma * sigma) / 2) * (T - t)) / (sigma * std::sqrt(T - t));

	return (std::exp(-y * (T - t)) * n(d_1)) / (S * sigma * std::sqrt(T - t));

}

//-----------------------------------------------------------------------
//PRINT FUNCTIONS
//-----------------------------------------------------------------------

	//Creating a print function for the European call option price
	void printCall(double S, double K, double r, double y, double sigma, double T, double t)
	{
		double C = call(S, K, r, y, sigma, T, t);
		std::cout << "The value of a European call option with asset price " << char(156) << S;
		std::cout << " , strike price " << char(156) << K << ", interest rate " << r * 100 << "%, volatility " << sigma * 100 ;
		std::cout << "%, "<< std::endl <<  "cost of carry " << y * 100 << "% " << " and time to expirty " << T << " years is : " << C << std::endl;
	}

	//Creating a print function for the European call option price
	void printPut(double S, double K, double r, double y, double sigma, double T, double t)
	{

		double P = put(S, K, r, y, sigma, T, t);
		std::cout << "The value of a European put option with asset price " << char(156) << S ;
		std::cout << " , strike price " << char(156) << K << ", interest rate " << r * 100 << "%, volatility " << sigma * 100;
		std::cout << "%, " << std::endl << "cost of carry " << y * 100 << "% " << " and time to expirty " << T << " years is : " << P << std::endl;

	}

	//Creating a print function for the delta of the European call option
	void printDeltaCall(double S, double K, double r, double y, double sigma, double T, double t)
	{
		double dc = delta_call(S, K, r, y, sigma, T, t);

		std::cout << "The delta of a European call option with asset price " << char(156) << S;
		std::cout << " , strike price " << char(156) << K << ", interest rate " << r * 100 << "%, volatility " << sigma * 100;
		std::cout << "%, " << std::endl << "cost of carry " << y * 100 << "% " << " and time to expirty " << T << " years is : " << dc << std::endl;
	}

	//Creating a print function for the delta of the European put option
	void printDeltaPut(double S, double K, double r, double y, double sigma, double T, double t)
	{
		double dp = delta_put(S, K, r, y, sigma, T, t);

		std::cout << "The delta of a European put option with asset price " << char(156) << S;
		std::cout << " , strike price " << char(156) << K << ", interest rate " << r * 100 << "%, volatility " << sigma * 100;
		std::cout << "%, " << std::endl << "cost of carry " << y * 100 << "% " << " and time to expirty " << T << " years is : " << dp << std::endl;
	}

	//Creating a print function for the gamma of the European call and put options
	void printGamma(double S, double K, double r, double y, double sigma, double T, double t)
	{

		double g = gamma(S, K, r, y, sigma, T, t);
		std::cout << "The gamma of European call an put options with asset price " << char(156) << S;
		std::cout << " , strike price " << char(156) << K << ", interest rate " << r * 100 << "%, volatility " << sigma * 100;
		std::cout << "%, " << std::endl << "cost of carry " << y * 100 << "% " << " and time to expirty " << T << " years is : " << g << std::endl;
	}

#endif 
