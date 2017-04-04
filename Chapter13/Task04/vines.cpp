#include <iostream>
#include "port.h"
//=================================port========================================
Port::Port(const char* br,const char*st,int b)
{
	int len = strlen(br);
	brand = new char[len+1];
	strcpy(brand,br);
	brand[len]='\0';
	
	strncpy(style,st,19);
	style[19]='\0';
	
	bottles = b;
}

Port::Port(const Port & other):Port(other.brand,other.style,other.bottles){}

Port& Port::operator=(const Port& other)
{
	if(this!=&other)
	{
		delete[] brand;
		int len = strlen(other.brand);
		brand = new char[len+1];
		strcpy(brand,other.brand);
		brand[len]='\0';
		
		strncpy(style,other.style,19);
		style[19]='\0';
		
		bottles=other.bottles;
	}
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles+=b;
	return *this;
}
Port& Port::operator-=(int b)
{
	if(bottles>=b)
	{
		bottles-=b;
	}
	else
	{
		std::cout<<"Don't have enough bottles!";
	}	
	return *this;
}
void Port::Show() const
{
	std::cout<<"Brand: "<<brand<<std::endl;
	std::cout<<"Style: "<<style<<std::endl;
	std::cout<<"Number of bottles: "<<bottles<<std::endl;	
}
std::ostream& operator<<(std::ostream &os,const Port&p)
{
	os<<p.brand<<", "<<p.style<<", "<<p.bottles;	
	return os;
}
//==============================end of port====================================

//=============================vintage port====================================

VintagePort::VintagePort():Port()
{
	nickname = new char [1];
	nickname[0] = '\0';
	year = 0;
}
VintagePort::VintagePort(const char*br,int b,const char* nn,int y):Port(br,"EMPTY",b)
{
	int len = strlen(nn);
	nickname = new char [len+1];
	strcpy(nickname,nn);
	nickname[len]='\0';
	
	year=y;
}
VintagePort::VintagePort(const VintagePort& other):Port(other)
{
	int len = strlen(other.nickname);
	nickname = new char [len+1];
	strcpy(nickname,other.nickname);
	nickname[len]='\0';
	
	year=other.year;
}
VintagePort& VintagePort::operator=(const VintagePort&other)
{
	if(this!=&other)
	{
		Port::operator=(other);
		
		int len = strlen(other.nickname);
		nickname = new char [len+1];
		strcpy(nickname,other.nickname);
		nickname[len]='\0';
	
		year=other.year;
	}
	return *this;
}
void VintagePort::Show() const
{
	Port::Show();
	std::cout<<"Nickname: "<<nickname<<std::endl;
	std::cout<<"Year: "<<year<<std::endl;	
}
std::ostream& operator<<(std::ostream&os,const VintagePort& vp)
{
	os<<(const Port&)vp<<", "<<vp.nickname<<", "<<vp.year;
	return os;
}


//==========================end of vintage port================================