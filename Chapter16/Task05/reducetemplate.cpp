#include <iostream>
#include <algorithm>
#include <string>

template<typename T>
int reduce(T ar[],int n);



int main()
{
	long arr[12] = {1,4,2,3,5,5,5,3,3,3,2,2};
	int size = reduce(arr,12);
	for(size_t i = 0; i < size; i++)
	{
		std::cout<<arr[i]<<", ";
	}
	std::cout<<'\n';
	std::string arr1[10] = {"ace","bee","ace","ace","mob","bee","foo","boo","boo","foo"};
	size = reduce(arr1,10);
	for(size_t i = 0; i < size; i++)
	{
		std::cout<<arr1[i]<<", ";
	}
	return 0;
}
template<typename T>
int reduce(T ar[],int n)
{
	std::sort(ar,ar+n);
	T* end = std::unique(ar,ar+n);
	return std::distance(ar,end);	
}