#include "winec.h"
#include <iostream>
Wine::Wine(const char *l,int  y):label(l), numberOfVintages(y)
{
	yearsBottlesPair.first().resize(numberOfVintages);
	yearsBottlesPair.second().resize(numberOfVintages);	
}

Wine::Wine(const char * l,int y, const int yr[],const int bot[]):label(l),numberOfVintages(y)
{
	yearsBottlesPair.first().resize(numberOfVintages);
	yearsBottlesPair.second().resize(numberOfVintages);
	for(int i = 0; i < numberOfVintages; i++)
	{
		yearsBottlesPair.first()[i]=yr[i];
		yearsBottlesPair.second()[i]=bot[i];
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
		yearsBottlesPair.first()[i]=vintage;
		yearsBottlesPair.second()[i]=nrOfBottles;
	}
}
void Wine::Show() const
{
	std::cout<<"Label: "<<label<<std::endl;
	for(int i = 0; i<numberOfVintages; i++)
	{
		std::cout<<"Year :"<<yearsBottlesPair.first()[i]<<" Bottles: "<<yearsBottlesPair.second()[i]<<std::endl;
	}
}
int Wine::Sum() const
{
	int sum = 0;
	for(int i = 0; i<numberOfVintages; i++)
	{
		sum+=yearsBottlesPair.second()[i];
	}
	return sum;
}