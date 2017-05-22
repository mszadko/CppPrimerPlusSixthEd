#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::ofstream;
int main()
{
	cout<<"Program will save your input to a file (until ctrl+z in a new line)\n";
	char fileName[20];
	cout<<"Enter file name:";
	cin.getline(fileName,20);
	ofstream fout(fileName);
	char ch;
	while(cin.get(ch))
	{
		fout<<ch;
	}
	if(cin.eof()) cout<<"End of file success";
	return 0;
}