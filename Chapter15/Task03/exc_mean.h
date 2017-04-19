#include<iostream>
#include <stdexcept>
#include <string>
#ifndef EXC_MEAN_H
#define EXC_MEAN_H
class bad_hmean:public std::invalid_argument
{
private:
	double param_a;
	double param_b;
public:
	bad_hmean(double a,double b,const char* info):std::invalid_argument(info),param_a(a),param_b(b){}
	void display()
	{
		std::cout<<invalid_argument::what()<<"\nPassed parameters: "<<param_a<<" and "<<param_b<<std::endl;
	}
};
class bad_gmean:public std::domain_error
{
private:
	double param_a;
	double param_b;
public:
	bad_gmean(double a,double b,const char* info):std::domain_error(info),param_a(a),param_b(b){}
	void display()
	{
		std::cout<<domain_error::what()<<"\nPassed parameters: "<<param_a<<" and "<<param_b<<std::endl;
	}
};
#endif