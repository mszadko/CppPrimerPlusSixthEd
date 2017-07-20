#include <iostream>

template<typename T>
long double SumValues(T value)
{
	return (long double) value;
}

template<typename T,typename... Args>
long double SumValues(T value, Args... args)
{
	return value + SumValues(args...);
}

int main()
{
	
	std::cout<< SumValues(1,10,100,1000)<<std::endl;
	std::cout<< SumValues(1,0.1,0.01,0.001)<<std::endl;
	return 0;
}