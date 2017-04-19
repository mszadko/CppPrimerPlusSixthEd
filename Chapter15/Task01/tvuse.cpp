#include <iostream>
#include "tv.h"

int main()
{
	Tv s42;
	Remote grey;
	std::cout<<"Settings of 42\" tv\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	std::cout<<"New settings\n";
	s42.settings();
	
	grey.set_chan(s42,1000);
	grey.volup(s42);
	grey.volup(s42);
	std::cout<<"After using remote\n";
	s42.settings();
	std::cout<<"Remote settings\n";
	grey.display();
	s42.set_remote(grey);
	grey.display();
	return 0;
}