#include <iostream>
#include "classic.h"
void Bravo(const Cd& disk);
int main()
{
	Cd c1("Beatles","Capitol",14,35.5);
	Classic c2 =Classic("Sonata fortepianowa B-dur , Fantazja C-moll","Alfred Brendel","Philips",2,57.17);
	Cd* pcd = &c1;
	
	std::cout<<"Direct usage of object:\n";
	c1.Report();//Cd::Report()
	c2.Report();//Classic::Report()
	std::cout<<std::endl;
	
	std::cout<<"Usage of Cd pointer:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();//should use Classic::Report();
	std::cout<<std::endl;
	
	std::cout<<"Usage of method with reference to Cd as a parameter:\n";
	Bravo(c1);
	Bravo(c2);
	std::cout<<std::endl;

	std::cout<<"Attribution test\n";
	Classic copy;
	copy=c2;
	c2=Classic();
	copy.Report();
	std::cout<<std::endl;
	std::cin.get();
	return 0;
};

void Bravo(const Cd&disk)
{
	disk.Report(); 	
}