#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>//exit()
#include <vector>
#include <algorithm>
#include "store.h"

void ShowStr(std::string const &);

void GetStrs(std::ifstream& fin,std::vector<std::string>& vistr);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;

	cout<<"Enter strings(empty line to exit):\n";
	while(getline(cin,temp) && temp[0]!='\0')
		vostr.push_back(temp);
	
	cout<<"Here is your data :\n";
	for_each(vostr.begin(),vostr.end(),ShowStr);
	
	//saving to file
	ofstream fout("strings.dat",ios_base::out|ios_base::binary);
	for_each(vostr.begin(),vostr.end(),Store(fout));
	fout.close();
	
	//read from file
	vector<string> vistr;
	ifstream fin("strings.dat",ios_base::in|ios_base::binary);
	if(!fin.is_open())
	{
		cerr <<"Error. Cannot open file";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin,vistr);
	cout<<"\nHere are strings read from file :\n";
	for_each(vistr.begin(),vistr.end(),ShowStr);

	return 0;

}

void ShowStr(std::string const & str)
{
	std::cout<<str<<std::endl;
}
void GetStrs(std::ifstream& fin,std::vector<std::string>& vistr)
{
	size_t size;
	std::string str_temp("");
	char char_temp;
	fin.read((char*)& size,sizeof(size_t));
	while(fin.good())
	{
		for(size_t i = 0; i < size; i++)
		{
			fin.read((char*)&char_temp,1);//sizeof(char) = 1;
			str_temp.push_back(char_temp);
		}
		vistr.push_back(str_temp);
		str_temp = "";
		fin.read((char*)& size,sizeof(size_t));
	}
}