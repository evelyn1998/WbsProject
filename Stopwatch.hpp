//C++ Assignment
//Section A
//Question 5: The <tuple> library
// Simple stopwatch to measure real time wall clock time.
// (C) Datasim Education BV 2017


#ifndef Stopwatch_HPP
#define Stopwatch_HPP

#include<chrono>

template <typename TickType = double, typename UnitType = std::ratio<1, 1>>
class Stopwatch {
private:
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;

	bool isStart;//true:if start records the starting time of the operation;otherwise, false;
	bool isEnd; //true if end records the ending time of the operation; otherwise,false;

public:
	Stopwatch() :isStart(false), isEnd(false) {}
	Stopwatch(const Stopwatch<TickType, UnitType>& src) = delete;
	Stopwatch<TickType, UnitType>& operator = (const Stopwatch<TickType, UnitType>& src) = delete;

	void Start();
	void Stop();
	void Reset();			// Reset the time to NOW

	// Duration between start and stop in seconds; reset
	TickType GetTime();
};



#endif
