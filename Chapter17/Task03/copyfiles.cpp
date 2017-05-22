//this program ask for 2 file names and copy content form one to another
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::ifstream;
using std::ofstream;

inline bool doesExist(const char* filename) //this checks if there is file called filename (important - us ifstream or you just create empty file)
{
	ifstream f(filename);
	return f.good();
}

int main(int argc, char* args[])//argc represents number of arguments passed to command line, args is array with pointers to passed arguments (same as char** args)
{
	
	if(argc!=3)
	{
		std::cerr<<"Error. Invalid number of arguments. "<<argc<<" instead of 3.\n";
		exit(1);
	}
	if(!doesExist(args[1]))//args[0] is a program name, proper arguments starts on args[1]
	{
		std::cerr<<"Error. There is no such file as \""<< args[1] <<"\". Cannot copy from file that do not exist. Exiting";
		exit(1);
	}
	ifstream fin(args[1]);
	ofstream fout(args[2]);
	char ch;
	while(fin.get(ch))
	{
		fout<<ch;
	}
	cout<<"File copied successfully"
	return 0;
}