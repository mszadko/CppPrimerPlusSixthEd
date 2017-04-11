//code from book (listing 14.11)
#include "Worker.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
//================Worker================
Worker::~Worker() {};

void Worker::Data() const
{
	cout<<"Name and surname: "<<fullname<<endl;
	cout<<"Id: "<<id<<endl;
}
void Worker::Get()
{
	getline(cin,fullname);
	cout<<"Enter id: ";
	cin>>id;
	while(cin.get()!='\n')//clears buffer
		continue;
}

//================Waiter=================
void Waiter::Set()
{
	cout<<"Enter name and surname of a waiter: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout<<"Waiter: "<<endl;
	Worker::Data();
	Data();
}
void Waiter::Data() const
{
	cout<<"Panache: "<<panache<<endl;
}

void Waiter::Get()
{
	cout<<"Enter panache level: ";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}
//==============singer===================
const char* Singer::pv[Singer::Vtypes]={"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::Set()
{
	cout<<"Enter name and surname of a singer: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout <<"Singer: "<<endl;
	Worker::Data();
	Data();
}
void Singer::Data()const
{
	cout<<"Voice timbre: "<<pv[voice]<<endl;
}
void Singer::Get()
{
	cout<<"Enter voice timbre: "<<endl;
	int i;
	for(i = 0; i<Vtypes;i++)
	{
		cout<< i<<". "<<pv[i]<<'\t';
		if(i%4==3)
			cout<<endl;
	}
	if(i%4==0)
		cout<<endl;
	cin>>voice;
	while(cin.get()!='\n')
		continue;
}
void SingingWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set()
{
	cout<<"Enter name of a singing waiter: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout <<"Singing Waiter :"<<endl;
	Worker::Data();
	Data();
}