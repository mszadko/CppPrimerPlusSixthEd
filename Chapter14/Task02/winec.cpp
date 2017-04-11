#include "winec.h"
#include <iostream>
Wine::Wine(const char *l,int  y):std::string(l), numberOfVintages(y)
{
	first().resize(numberOfVintages);
	second().resize(numberOfVintages);	
}

Wine::Wine(const char * l,int y, const int yr[],const int bot[]):std::string(l),numberOfVintages(y)
{
	first().resize(numberOfVintages);
	second().resize(numberOfVintages);
	for(int i = 0; i < numberOfVintages; i++)
	{
		first()[i]=yr[i];
		second()[i]=bot[i];
	}
}
void Wine::GetBottles()
{
	int vintage;
	int nrOfBottles;
	for(int i = 0;i <numberOfVintages;i++)
	{
		std::cout<<"Enter vintage: ";
		std::cin>>vintage;
		std::cout<<"Enter number of bottles: ";
		std::cin>>nrOfBottles;
		first()[i]=vintage;
		second()[i]=nrOfBottles;
	}
}
void Wine::Show() const
{
	std::cout<<"Label: "<<*this<<std::endl;
	for(int i = 0; i<numberOfVintages; i++)
	{
		std::cout<<"Year :"<<first()[i]<<" Bottles: "<<second()[i]<<std::endl;
	}
}
int Wine::Sum() const
{
	int sum = 0;
	for(int i = 0; i<numberOfVintages; i++)
	{
		sum+=second()[i];
	}
	return sum;
}