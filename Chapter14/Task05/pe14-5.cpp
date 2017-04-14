#include <iostream>
#include "emp.h"

int main()
{
	using std::cout; using std::cin; using std::endl;
	employee em("Bill","Hilly","Seller");
	manager ma("Foo","Boo","Painter",5);
	fink fi("Marcus","Brutus","Politician","Everyone");
	highfink hf(ma,"his boss");
	cout<<em<<endl;
	em.showAll();
	
	cout <<ma<<endl;
	ma.showAll();
	
	cout<<fi<<endl;
	fi.showAll();
	
	hf.showAll();
	
	cout<<"Enter any key to proceed ";
	cin.get();
	cin.get();
	highfink hf2;
	hf2.setAll();
	
	cout<<"Usage of abstr_emp* pointer"<<endl;
	
	abstr_emp* tri[4]={&em,&fi,&hf,&hf2};
	for(int i = 0;i<sizeof(tri)/sizeof(abstr_emp*);i++)
	{
		tri[i]->showAll();
	}
	return 0;
}