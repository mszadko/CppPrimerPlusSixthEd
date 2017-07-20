#include <iostream>
#include <initializer_list>
#include <list>

template <typename T>
std::list<T> average_list(std::initializer_list<T> init_list);


int main()
{
	using namespace std;
	
	auto q = average_list({15.4,10.7,9.0});

	for(auto q_elem : q)
		cout<<q_elem<<", ";
	cout<<endl;

	return 0;
}

template <typename T>
std::list<T> average_list(std::initializer_list<T> init_list)
{
	std::list<T> list_to_return;
	for(const T* i = init_list.begin(); i<init_list.end(); i++)
	{
		list_to_return.push_back(*i);
	}
	return list_to_return;
}