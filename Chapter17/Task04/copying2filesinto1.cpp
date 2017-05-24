#include <fstream>
#include <iostream>
#include <string>

inline bool doesExist(const char*fileName)
{
	std::ifstream fin(fileName);
	return fin.good();
}

int main()
{
	using std::cin;
	using std::cout;
	using std::ifstream;
	using std::ofstream;
	using std::string;
	
	string path;
	cout<<"Enter path to first file: ";
	cin>>path;
	while(!doesExist(path.c_str()))
	{
		cout<<"Wrong file name! Try another one: ";
		cin>>path;
	}
	ifstream fin1(path.c_str());
	cout<<"Enter path to second file: ";
	cin>>path;
	while(!doesExist(path.c_str()))//i dont like this repetition
	{
		cout<<"Wrong file name! Try another one: ";
		cin>>path;
	}
	ifstream fin2(path.c_str());
	cout<<"Where do you want to copy content of those files to? :";
	cin>>path;
	ofstream fout(path.c_str());
	char ch;
	while(fin1.good() && fin2.good())
	{
		while(fin1.get(ch) && ch!='\n')
			fout.put(ch);
		fout.put(' ');
		while(fin2.get(ch) && ch!='\n')
			fout.put(ch);
		fout.put('\n');
	}
	while(fin1.get(ch))
		fout.put(ch);
	while(fin2.get(ch))
		fout.put(ch);
	return 0;
}