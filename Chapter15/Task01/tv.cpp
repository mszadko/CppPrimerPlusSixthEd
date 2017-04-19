#include <iostream>
#include "tv.h"

bool Tv::volup()
{
	if(volume <MaxVal)
	{
		volume++;
		return true;
	}
	return false;
}

bool Tv::voldown()
{
	if(volume>MinVal)
	{
		volume--;
		return true;
	}
	return false;
}

void Tv::chanup()
{
	if(channel<maxchannel)
	 channel++;
	channel = 1;
}

void Tv::chandown()
{
	if(channel>1)
		channel--;
	channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout; using std::endl;
	cout<<"Tv is turned "<<(state==Off?"off\n":"on\n");
	if(state==On)
	{
		cout<<"Volume: "<<volume<<endl
		<<"Channel: "<<channel<<endl
		<<"Mode: "<<(mode==Antenna?"antenna\n":"cable\n")
		<<"Input: "<<(input==TV?"TV\n":"DVD\n");
	}
}
bool Tv::set_remote(Remote &r) const
{
	if(ison())
	{
		r.set_interactive();
		return true;
	}
	return false;
}
void Remote::display()
{
	std::cout<<"Remote "<<(isInteractive==true?"is in interactive mode\n":"is in regular mode\n");
}