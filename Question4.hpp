//C++ Assignment
//Section A
//Question 4: Random Number Generation, small Research Topic
//Header File


#ifndef Question4_HPP
#define Question4_HPP
#include <iostream>
#include <random>
#include <vector>
#include <cmath>

//----------------------------------------------------------------------------------------
/*Introduce the inputs that will be used
a-constant
b-constant 
T-maturity of the option 
S_0-initial asset price
N-number of subintervals of (0,T)
dt-time step */
//-----------------------------------------------------------------------------------------

//Create a function that will give an approximation to the solution of the Geometric Brownian motion dS = aSdt + bSdW at each mesh point (we would have values for S(0),...,S(T))
//Since we want it to give a value at each mesh point we would like to return the answer as a vector

std::vector<double> SDE(double a, double b, double T, double S_0, double N)  
{
	//Generate the normally distributed random variable y 
	std::random_device radev;
	std::mt19937 gen(radev());
	std::normal_distribution<double> dis{ 0,1 };
	double y = dis(gen);


	//Create a vector where S(0),...,S(T) will be stored
	std::vector<double> stock;
	stock.push_back(S_0); //adding the initial asset price to the vector 

	//Define the variable S 
	double S;

	//Define the time-step
	double dt = T / N;

	//Loop through each mesh point from 0 to NT-1 to obtain an approximate solution
	for (int i = 0; i < N ; ++i)
	{
		 y = dis(gen); //we want to generate a different random number for each iteration
		 S = stock[i] * (std::exp((a + (0.5 * b * b)) * (dt) + (b * std::sqrt(dt) * y)));  //approximating the solution 
		stock.push_back(S);
		
	}
	return stock;

}

//Creating a print function for the SDE
void printStock(double a, double b, double T, double S_0, double N)
{
	std::vector<double> st = SDE(a, b, T, S_0, N);
	//Loop through the elements of the vector and print all of them since we want to generate the entire path
	std::cout << "The approximate solution of the Geometric Brownian Motion SDE with constants: " << a << " ," << b;
	std::cout << " , maturity " << T << ", " << std::endl;
	std::cout <<" initial stock price " << S_0 << " and number of timesteps " << N << " is: \n";
	for (int j = 0; j < st.size(); ++j)
	{
		std::cout << j << "\t" << st[j] << std::endl;
	}
}



#endif;
