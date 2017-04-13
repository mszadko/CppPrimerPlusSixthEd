#include <iostream>
#include "person.h"
#include <ctime>//time
#include <cstdlib>//rand srand
#include<cstring> //strchr

const int SIZE = 5;

int main()
{
	srand(time(NULL));
	person* cowboys[SIZE];
	int count = 0;
	for(count = 0; count <SIZE; count++)
	{
		char choice;
		std::cout<<"Enter what kind of cowboy do you need: \n"
		<<"g: gunslinger\tp: poker player\t\tb:badass\te: exit:  ";
		std::cin>>choice;
		std::cin.get();
		while(strchr("gpbe",choice)==NULL)
		{
			std::cout<<"Enter g, p, b or e:  ";
			std::cin>>choice;
			std::cin.get();
		}
		if(choice == 'e') break;
		switch(choice)
		{
			case 'g' : 	
				cowboys[count] = new gunslinger();
				cowboys[count]->set();
				break;
			case 'p' :	
				cowboys[count] = new pokerPlayer();
				cowboys[count]->set();
				break;
			case 'b' :
				cowboys[count] = new badDude();
				cowboys[count]->set();
				break;
		}
	}
	for(int i = 0; i<count;i++)
	{
		cowboys[i]->show();
	}
	for(int i =0; i<count; i++)
	{
		delete cowboys[i];
	}
	return 0;
}