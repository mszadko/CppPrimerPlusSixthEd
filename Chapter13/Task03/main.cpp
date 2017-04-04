#include "abstractDMA.h"
#include <iostream>

#define arr_len 3
int main()
{
	baseDMA b1("First obj of baseDMA", 101);
	baseDMA b2;
	b2=b1;
	b1=baseDMA("I changed my mind with base obj",-101);
	lacksDMA l1("First obj of lacksDMA", 1001,"colorfull");
	lacksDMA l2;
	l2=l1;
	l1=lacksDMA("I changed my mind with lacksDMA",-101,"black and white");
	hasDMA h1("First obj of hasDMA", 1001,"modern");
	hasDMA h2;
	h2=h1;
	h1=hasDMA("I changed my mind with has",-1001,"oldshool");
	b1.View();
	b2.View();
	l1.View();
	l2.View();
	h1.View();
	h2.View();
	std::cout<<"\n\n\n";
	abstractDMA* arr[arr_len];
	arr[0] = new baseDMA("Abstract pointer to base",199);
	arr[1] = new lacksDMA("Abstract pointer to lacks",299,"blue");
	arr[2] = new hasDMA("Abstract pointer to has",399,"greek");
	for(int i =0;i<arr_len;i++)
	{
		arr[i]->View();		
	}
	return 0;
}