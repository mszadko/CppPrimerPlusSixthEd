// most of this code is from the book
// i had to add method to get the wordlist from a .txt
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
using std::string;
using std::vector;
const int NUM = 26;
void parseWordsFromTxtFile(const vector<string>& wordlist, const string& path);
void show(const string&s);

const vector<string> wordlist;

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
	parseWordsFromTxtFile(wordlist,"words.txt");
    std::srand(std::time(0));
    char play;
    cout << "Czy chcesz zagrać w grę słowną? <t/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 't')
    {
        string target = wordlist[std::rand() % wordlist.size()];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Zgadnij moje sekretne słowo. Ma ono " << length 
            << " liter. Możesz zgadywać\n"
            << "po jednej literze naraz. Możesz pomylić się " << guesses
            << " razy.\n";
        cout << "Twoje słowo: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Zgadnij literę: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                    || attempt.find(letter) != string::npos)
            {
                cout << "Ta litera już była. Spróbuj innej.\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Nie ma takiej litery!\n";
                --guesses;
                badchars += letter; // dodaje do ciągu
            }
            else
            {
                cout << "Poprawna litera!\n";
                attempt[loc] = letter;
                // sprawdza, czy litera nie pojawia się ponownie w innym miejscu
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }  
            cout << "Twoje słowo: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Niepoprawne litery: " << badchars << endl;
                cout << "Możesz pomylić się jeszcze " << guesses << " razy\n";
            }
        }
        if (guesses > 0)
            cout << "To już całe słowo!\n";
        else
            cout << "Niestety, to słowo to " << target << ".\n";

        cout << "Czy chcesz zagrać jeszcze raz? <t/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Koniec\n";

    return 0;
}
//my code right here
void parseWordsFromTxtFile(const vector<string>& wordlist, const string& filePath)
{
	using std::fstream;
	//Using RTTI right here cuz i want to edit wordlist which is constant
	vector<string>& nonConstVector= const_cast<vector<string>&> (wordlist);
	fstream fileReader;
	fileReader.open(filePath);
	string word;
	while(fileReader.good())
	{
		fileReader>>word;
		nonConstVector.push_back(word);
		fileReader.get();
	}
	fileReader.close();	
}