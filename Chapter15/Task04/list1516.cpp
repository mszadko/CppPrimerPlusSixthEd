#include <iostream>
#include <stdexcept>
#include "sales.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	double vals1[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	double vals2[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
	Sales sales1(2011,vals1,12);
	LabeledSales sales2("Blogstar",2012,vals2,12);
	cout<<"First try block\n";
	try 
	{
		int i;
		cout<<"Year = "<<sales1.Year()<<endl;
		for(i = 0; i < 12;++i)
		{
			cout<<sales1[i]<<'\t';
			if(i%4==3)cout<<endl;
		}
		cout<<"Year = "<<sales2.Year()<<endl;
		cout<<"Label ="<<sales2.Label()<<endl;
		for(i = 0; i <= 12;++i)//will cause error
		{
			cout<<sales2[i]<<'\t';
			if(i%4==3)cout<<endl;
		}
		cout<<"End of first try block\n";
	}
	catch(Sales::bad_index& bi)
	{
		cout<<bi.what()<<"Index = "<<bi.bi_val();
		if(typeid(LabeledSales::nbad_index)==typeid(bi))
		{
			LabeledSales::nbad_index nbi = dynamic_cast<LabeledSales::nbad_index&>(bi);
			cout<<"\tLabel = "<<nbi.label_val();
		}
	}
	cout<<"\nSecond try block\n";
	try
	{
		sales2[2]=37.5;
		sales1[20]=10;
		cout<<"End of second try block\n";
	}
	catch(Sales::bad_index&bi)
	{
		cout<<bi.what()<<"Index = "<<bi.bi_val();
		if(typeid(LabeledSales::nbad_index)==typeid(bi))
		{
			LabeledSales::nbad_index nbi = dynamic_cast<LabeledSales::nbad_index&>(bi);
			cout<<"\tLabel = "<<nbi.label_val();
		}
	}
	return 0;
}