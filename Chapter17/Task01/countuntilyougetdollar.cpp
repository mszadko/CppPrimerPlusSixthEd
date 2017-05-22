#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	cout<<"Enter data, program will count how many characters you entered before $ sing : ";
	char ch;
	int counter = 0;
	while(cin.get(ch) && ch!='$')//i could use peek() so i don't have to put dollar sing back to the buffer explicitly
	{
		cout<<ch;
		counter++;
	}
	cin.putback('$');//putting dollar sign back to the buffer
	cout<<"\nYou entered "<<counter<<" characters before dollar sing\n";
	cin>>ch;
	cout<<"Next character in buffer was - "<<ch;
	return 0;
}