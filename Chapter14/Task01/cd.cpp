#include "classic.h"//which includes cd.h
#include <string.h>
#include <iostream>
Cd::Cd(char*s1,char *s2, int n,double x)
{
	strcpy(performers,s1);
	strcpy(label,s2);
	selections = n;
	playtime = x;
}
Cd::~Cd(){std::cout<<"Destroying cd";};
void Cd::Report() const
{
	std::cout<<performers<<", label: "<<label<<", songs: "<<selections<<" playtime :"<<playtime<<std::endl;	
}
Classic::Classic(char *s1,char*s2,char *s3,int n,double x):Cd(s2,s3,n,x)
{
	strcpy(legendarySong,s1);
}
void Classic::Report() const
{
	Cd::Report();
	std::cout<<"Includes legendary "<<legendarySong<<std::endl;
}
Classic::~Classic(){std::cout<<"Destroying the legend";}