//code below was given in the book to test wine class
//now i have to use private inheritance instead of aggregation
#include <iostream>
#include "winec.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	cout<<"Enter wine name: ";
	char lab[50];
	cin.getline(lab,50);
	cout<<"Enter number of vintages: ";
	int yrs;
	cin>>yrs;
	Wine holding(lab,yrs);
	holding.GetBottles();
	holding.Show();
	
	const int YRS = 3;
	int y[YRS] = {1993,1995,1998};
	int b[YRS] = {48,60,72};
	
	Wine more("Gushing Grape Red" ,YRS,y,b);
	more.Show();
	cout<<"Bottles of "<<more.Label()<<" in total - "<<more.Sum()<<endl;
	cout<<"END"<<endl;
	return 0;	
}