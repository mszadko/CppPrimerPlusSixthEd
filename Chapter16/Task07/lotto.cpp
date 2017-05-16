#include <vector>
#include <iostream>
#include <algorithm>


using std::vector;
using std::cout;
using std::for_each;

vector<int> Lotto(int n,int m);//n - numbers in total, m - number of marked fields by a player
void show(int);
int main()
{
	int n,m;
	cout<<"Enter range (1- :";
	std::cin>>n;
	cout<<"Enter number of fields chosen by player: ";
	std::cin>>m;
	vector<int> result = Lotto(n,m);
	for_each(result.begin(),result.end(),show);
	return 0;
}




vector<int> Lotto(int n,int m)
{
	vector<int> numbersOnCoupon;
	for(size_t i = 1; i <= n; i++)
		numbersOnCoupon.push_back(i);
	std::random_shuffle(numbersOnCoupon.begin(),numbersOnCoupon.end());
	numbersOnCoupon.erase(numbersOnCoupon.begin()+m,numbersOnCoupon.end());	
	return numbersOnCoupon;
}
void show(int a)
{
	cout<<a<<", ";
}