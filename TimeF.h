#include <chrono>

//	Some help from
//	https://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/

template<typename F>
auto timeF(F f) -> double{
	auto start = std::chrono::steady_clock::now();
	f();
	auto end = std::chrono::steady_clock::now();
	double toReturn = std::chrono::duration<double, std::milli>(end - start).count();
	return toReturn;
}