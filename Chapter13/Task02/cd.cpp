#include "classic.h"//which includes cd.h
#include <string.h>
#include <iostream>
//================Cd================
Cd::Cd(char*s1,char *s2, int n,double x)
{
	int len = strlen(s1);
	performers = new char[len+1];
	strcpy(performers,s1);
	performers[len]='\0';
	
	len =strlen(s2);
	label=new char[len+1];
	strcpy(label,s2);
	label[len]='\0';
	
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd& d):Cd(d.performers,d.label,d.selections,d.playtime){}
Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}
Cd& Cd::operator=(const Cd&d)
{
	if(this != &d)
	{
	delete []performers;
	delete []label;
	
	int len = strlen(d.performers);
	performers = new char[len+1];
	strcpy(performers,d.performers);
	performers[len]='\0';
	
	len =strlen(d.label);
	label=new char[len+1];
	strcpy(label,d.label);
	label[len]='\0';
	
	selections = d.selections;
	playtime = d.playtime;
	}
	return *this;
}
void Cd::Report() const
{
	std::cout<<performers<<", label: "<<label<<", songs: "<<selections<<" playtime :"<<playtime<<std::endl;	
}
//==============End of Cd==============


//===============Classic===============
Classic::Classic(char *s1,char*s2,char *s3,int n,double x):Cd(s2,s3,n,x)
{
	int len = strlen(s1);
	legendarySong = new char[len+1];
	strcpy(legendarySong,s1);
	legendarySong[len]='\0';
}
Classic::Classic(const Classic& other) :Cd(other)
{	
		int len = strlen(other.legendarySong);
		legendarySong=new char[len+1];
		strcpy(legendarySong,other.legendarySong);
		legendarySong[len]='\0';
}
Classic& Classic::operator=(const Classic&other)
{
	if(this!=&other)
	{
		Cd::operator=(other);
		delete [] legendarySong;
		int len =strlen(other.legendarySong);
		legendarySong=new char[len+1];
		strcpy(legendarySong,other.legendarySong);	
	}
	return *this;
}
void Classic::Report() const
{
	Cd::Report();
	std::cout<<"Includes legendary "<<legendarySong<<std::endl;
}
Classic::~Classic()
{
	//Cd's destructor will be called automaticaly becouse it is virtual;
	delete [] legendarySong;
}
//=============End of Classic==========