#include <iostream>
#include <cmath>
#include <stdexcept>
//#include "exc_mean.h"

double hmean(double a,double b);
double gmean(double a,double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x,y,z;
	
	cout<<"Enter 2 numbers: ";
	while(cin>>x>>y)
	{
		try
		{
			z=hmean(x,y);
			cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<endl;
			cout<<"Geometric mean of "<<x<<" and "<<y<<" is "<<gmean(x,y)<<endl;
			cout<<"Enter another values: <e for exit>: ";			
		}
		catch(std::invalid_argument&ia)
		{
			
			cout<<ia.what()<<endl;
			cout<<"Enter another values: ";
			continue;
		}
		catch(std::domain_error&de)
		{
			cout<<de.what()<<endl;
			cout<<"Enter another values: ";
			continue;
		}
	}
	cout<<"END";
	return 0;
}

double hmean(double a,double b)
{
	if(a==-b) throw std::invalid_argument("ERROR IN HMEAN(). VALUES CAN'T BE OPOSSITE NUMBERS");
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0||b<0) throw std::domain_error("ERROR IN GMEAN(). BOTH VALUES MUST BE POSITIVE");
	return std::sqrt(a*b);
}