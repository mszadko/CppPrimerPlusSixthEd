#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::for_each;
using std::string;


void askAboutFriends(const string& hostname,vector<string>& guests);
void show(string s)
{
	cout<<s<<", ";
}
int main()
{
	vector<string> bolekFriends;
	vector<string> lolekFriends;
	askAboutFriends("Bolek",bolekFriends);
	askAboutFriends("Lolek",lolekFriends);
	cout<<"Bolek quest list:\n";
	for_each(bolekFriends.begin(),bolekFriends.end(),show);
	cout<<"\nLolek quest list:\n";
	for_each(lolekFriends.begin(),lolekFriends.end(),show);
	cout<<"\n";
	vector<string> friendsOfBoth = bolekFriends;
	size_t length = lolekFriends.size();
	
	for(size_t i = 0; i<length;i++)
	{
		friendsOfBoth.push_back(lolekFriends[i]);
	}
	std::sort(friendsOfBoth.begin(),friendsOfBoth.end());
	vector<string>::iterator end= std::unique(friendsOfBoth.begin(),friendsOfBoth.end());
	friendsOfBoth.erase(end,friendsOfBoth.end());
	cout<<"Guest list:\n";
	for_each(friendsOfBoth.begin(),friendsOfBoth.end(),show);	cout<<"\n";
	return 0;
}

void askAboutFriends(const string& hostname,vector<string>& guests)
{
	cout<<hostname<<", please enter names of guests (\"done\" when you finish):";
	string name;
	getline(cin,name);
	while(cin && name!="done")
	{
		guests.push_back(name);
		cout<<"Enter another guest :";
		getline(cin,name);
	}
	std::sort(guests.begin(),guests.end());
}