#include <algorithm>
#include <vector>
#include <iostream>


int reduce(long ar[],int n); //long ar[] == long* ar

int main()
{
	long array[10] = {4,4,1,1,3,2,3,2,2,3};
	int end = reduce(array,10);
	for(size_t i = 0; i<end; i++)
	{
		std::cout<<array[i]<<", ";
	}
	return 0;
}
int reduce (long ar[],int n)
{
	std::sort(ar,ar+n);//this will sort array
	long * end = std::unique(ar,ar+n);//this eliminates all but first element from every consecutive group of equivalent elements
	// in sorted collection it means that we now have collection of sorted unique elements
	return std::distance(ar,end);
}