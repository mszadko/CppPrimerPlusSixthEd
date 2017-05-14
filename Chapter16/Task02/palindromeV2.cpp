#include <iostream>
#include <string>
#include <cctype>//for various character functions(tolower, isdigit etc.)

bool checkIfStringIsPalindrome(std::string& s);

int main()
{
	std::cout<<"Program will check if entered text is a palindrome\n";
	std::string enteredText;
	std::cout<<"Enter text you'd like to check(type \"exit\" to exit):";
	while(getline(std::cin,enteredText) && enteredText !="exit")
	{
		
		std::cout<<"You entered "<<enteredText<<'\n';
		checkIfStringIsPalindrome(enteredText);
		
		
		std::cout<<"Enter another text or type \"exit\" to exit:";
	}
	return 0;
}

bool checkIfStringIsPalindrome(std::string& s)
{
	//this part removes whitespaces and convert all upper cases to lower cases
	for(std::string::iterator beg = s.begin(); beg!=s.end();/*can't increment here cuz if erase will be invoked it will put beg to next char*/)
	{
		if(isupper(*beg))	
			*beg=tolower(*beg);
		else if(isspace(*beg))
			s.erase(beg);//erase a whitespace and reduce str length
		else 
			beg++;
		
	}
	//or i could just do another string and add to it only alphanumerics from source like a smart person :) 
	//for_each char in s
	//if isalnum(char)
	//tempStringVariable += tolower(char)
	
	size_t stringLenght = s.length();
	//this part checks if s is a palindrome
	for(size_t i = 0; i < (stringLenght/2); i++)
	{
		if(s[i]!=s[stringLenght-1-i])
		{
			std::cout<<s<<" is not a palindrome\n";
			return false;
		}
	}
	std::cout<<s<<" is a palindrome\n";
	return true;
}