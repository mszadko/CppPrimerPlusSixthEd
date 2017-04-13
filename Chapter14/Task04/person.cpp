#include "person.h"
#include <ctime>//time
#include <cstdlib>//rand srand
#include <iostream>
int pokerPlayer::draw()
{
	return rand()%52;
}

void person::set()
{
	std::cout<<"Please enter a name and surname: ";
	getline(std::cin,fullname);
}
void gunslinger::set()
{
	person::set();
	std::cout<<"Enter time of pulling out a gun(in seconds): ";
	std::cin>>draw_time;
	std::cout<<"Enter number of kills: ";
	std::cin>>kills;
}