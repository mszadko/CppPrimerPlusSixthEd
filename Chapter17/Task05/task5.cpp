#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>


using std::vector;
using std::cout;
using std::cin;
using std::for_each;
using std::string;

void readGuestFile(vector<string>& guests);
inline void show(string const & s)
{
	cout<<s<<", ";
}
inline bool doesFileExist(string const& path)
{
	std::ifstream inputFile(path.c_str());
	return inputFile.good();
}

int main()
{
	vector<string> boleksFriends;
	vector<string> loleksFriends;
	std::cout<<"Reading boleks friends...\n";
	readGuestFile(boleksFriends);
	std::cout<<"Reading loleks friends...\n";
	readGuestFile(loleksFriends);
	cout<<"Bolek guest list:\n";
	for_each(boleksFriends.begin(),boleksFriends.end(),show);
	cout<<"\nLolek guest list:\n";
	for_each(loleksFriends.begin(),loleksFriends.end(),show);
	cout<<"\n";
	vector<string> friendsOfBoth = boleksFriends;
	size_t length = loleksFriends.size();
	for(size_t i = 0; i<length;i++)
	{
		friendsOfBoth.push_back(loleksFriends[i]);
	}
	std::sort(friendsOfBoth.begin(),friendsOfBoth.end());
	vector<string>::iterator end = std::unique(friendsOfBoth.begin(),friendsOfBoth.end());
	friendsOfBoth.erase(end,friendsOfBoth.end());
	cout<<"Guest list:\n";
	for_each(friendsOfBoth.begin(),friendsOfBoth.end(),show);	cout<<"\n";
	
	return 0;
}


void readGuestFile(vector<string>& guests)
{
	std::string filePath;
	std::cout<<"Please enter file path :";
	std::cin>>filePath;
	while(!doesFileExist(filePath))
	{
		std::cout<<"There is no file --"<<filePath<<std::endl<<"Please enter another path :";
		std::cin>>filePath;
	}
	std::ifstream input(filePath.c_str());
	{
		std::string guestName;
		while(input.good())
		{
			getline(input,guestName);
			if(guestName=="\n" ||guestName=="")
				break;
			guests.push_back(guestName);
		}
	}
}