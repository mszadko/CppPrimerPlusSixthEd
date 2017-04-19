#include <iostream>
#include <cmath>
#include "exc_mean.h"

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
		catch(std::logic_error&le)
		{
			//rtti
			if(typeid(le)==typeid(bad_hmean))
			{
				bad_hmean err=(bad_hmean&)le;
				err.display();	
			}
			if(typeid(le)==typeid(bad_gmean))
			{
				bad_gmean err=(bad_gmean&)le;
				err.display();	
			}
			cout<<"Closing program\n";
			break;
		}
	}
	cout<<"END";
	return 0;
}

double hmean(double a,double b)
{
	if(a==-b) throw bad_hmean(a,b,"ERROR IN HMEAN(). VALUES CAN'T BE OPPOSITE NUMBERS");
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0||b<0) throw bad_gmean(a,b,"ERROR IN GMEAN(). BOTH VALUES MUST BE POSITIVE");
	return std::sqrt(a*b);
}