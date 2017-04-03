#include <iostream>
#include <string.h>

class A
{
	char*property;
public:
	A(char*p=(char*)"puste pole")
	{
		int len = strlen(p);
		property=new char[len+1];
		strcpy(property,p);
		property[len]='\0';		
	}
	A(const A&a):A(a.property)//delegate to previous constructor
	{
		/*
		int len = strlen(a.property);
		property=new char[len+1];
		strcpy(property,a.property);
		property[len]='\0';	
		*/		
	}
	A& operator=(const A& another)
	{
		if(this == &another) return *this;
		
		delete[] property;
		int len = strlen(another.property);
		property = new char [len+1];
		strcpy(property,another.property);
		property[len]='\0';
		return *this;
	}
	~A()
	{
		delete []property;
	}
	void Show()
	{
		std::cout<<property<<std::endl;
	}
	void Edit(char* newprop)
	{
		delete [] property;
		int len = strlen(newprop);
		property=new char[len+1];
		strcpy(property,newprop);
		property[len]='\0';	
	}
};
int main()
{
	A a((char*)"Some prop");
	A b = a;//copy construcor
	A c;
	c = a;//assignment operator
	a.Edit((char*)"Changing a only");
	a.Show();
	b.Show();
	c.Show();
	std::cout<<std::endl;
	b.Edit((char*)"This is b");
	c.Edit((char*)"This is c");
	a.Show();
	b.Show();
	c.Show();
	return 0;
}



