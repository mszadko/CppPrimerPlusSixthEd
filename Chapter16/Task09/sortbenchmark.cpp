#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

using std::cin;
using std::cout;
using std::vector;
using std::list;

int main()
{
	//srand(time(NULL)); i comented this out cuz i want to have always the same random values
	vector<unsigned int> mainVector;
	int size;
	cout<<"How many elements in vector/list you want to benchmark? : ";
	cin>>size;
	for(size_t i = 0; i<size; i++)
	{
		mainVector.push_back(rand());
	}
	
	vector<unsigned int> benchmarkVector;
	list<unsigned int>benchmarkList;
	benchmarkVector.insert(benchmarkVector.begin(),mainVector.begin(),mainVector.end());
	benchmarkList.insert(benchmarkList.begin(),mainVector.begin(),mainVector.end());
	
	clock_t start = clock();
	std::sort(benchmarkVector.begin(),benchmarkVector.end());
	clock_t end = clock();
	cout<<"Sorting of vector with std::sort took :"<<(double)(end-start)/CLOCKS_PER_SEC<<std::endl;
	
	
	
	start = clock();
	benchmarkList.sort();
	end = clock();
	cout<<"Sorting of list with list::sort took :"<<(double)(end-start)/CLOCKS_PER_SEC<<std::endl;
	
	benchmarkList.assign(mainVector.begin(),mainVector.end());//restoring data to state before sorting;
	start = clock();
	benchmarkVector.assign(benchmarkList.begin(),benchmarkList.end());
	std::sort(benchmarkVector.begin(),benchmarkVector.end());
	benchmarkList.assign(benchmarkVector.begin(),benchmarkVector.end());
	end = clock();
	cout<<"Copying data form list to vector, sorting vector and copying it back to list took :"<<(double)(end-start)/CLOCKS_PER_SEC<<std::endl;
	
	return 0;
}
