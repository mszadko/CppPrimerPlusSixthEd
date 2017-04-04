#include <iostream>
#ifndef __PORTVIN_H__
#define __PORTVIN_H__
class Port
{
private:
	char * brand;
	char style[20];
	int bottles;
public:
	Port(const char*br="EMPTY", const char *st ="EMPTY", int b=0);
	Port(const Port& other);
	virtual ~Port(){delete []brand;}
	Port& operator=(const Port & other);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount()const {return bottles;}
	virtual void Show() const;
	friend std::ostream & operator<<(std::ostream & os,const Port& p);
};
#
class VintagePort:public Port
{
private:
	char*nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char*br,int b, const char* nn,int y);//it will be more elegant with same order as port but task is a task + why there is no style here?
	VintagePort(const VintagePort& other);
	~VintagePort(){delete[]nickname;}
	VintagePort & operator=(const VintagePort& other);
	void Show() const;
	friend std::ostream & operator<<(std::ostream&os, const VintagePort& vp);
};
#endif