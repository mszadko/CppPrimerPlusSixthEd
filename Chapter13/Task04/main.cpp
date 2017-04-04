#include <iostream>
#include "port.h"

int main()
{
	Port p1 = Port();
	Port p2 = Port("Sowietskoje Igristoje","really cheap",100);
	p1.Show();
	p2.Show();
	std::cout<<std::endl;
	std::cout<<"Assignment test"<<std::endl;
	p1=p2;
	p2=Port("Dom Perignon","champagne",3);
	p1.Show();
	p2.Show();
	std::cout<<p1<<std::endl<<p2;
	std::cout<<std::endl;
	std::cout<<std::endl;
	VintagePort vp1;
	VintagePort vp2("Porto",5,"Pirate's Water",1723);
	vp1.Show();
	vp2.Show();
	vp1=vp2;
	vp2=VintagePort("La geria",1,"Malvasia volcanica",2014);
	std::cout<<std::endl;
	vp1.Show();
	vp2.Show();
	std::cout<<vp1<<std::endl<<vp2<<std::endl<<std::endl;
	std::cout<<"Virtual methods test"<<std::endl;
	Port * pointer = new Port(p2);
	pointer->Show();
	pointer=new VintagePort(vp2);
	pointer->Show();

	return 0;
}