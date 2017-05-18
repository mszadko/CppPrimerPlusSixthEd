// vect3.cpp -- uusage of STL
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>//for smart pointers


using std::shared_ptr;

struct Review {
    std::string title;
	double price;
    int rating;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool cheaperThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(shared_ptr<Review> & rr);
void ShowReview(const shared_ptr<Review> & rr);
int main()
{
    using namespace std;

    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp;
    while (FillReview(temp))
        books.push_back(temp);
    if (books.size() > 0)
    {
        cout << "Thanks. You entered "
            << books.size() << " reviews:\n"
            << "Rate\tTitle\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRate\tTitle\n";
        for_each(books.begin(), books.end(), ShowReview);
		
		sort(books.rbegin(), books.rend());
        cout << "Sorted by title(reversed):\nRate\tTitle\n";
        for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(),cheaperThan);
        cout << "Sorted by price:\nRate\tTitle\n";
        for_each(books.begin(), books.end(), ShowReview);
		
        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRate\tTitle\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffle:\nRate\tTitle\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No data.\n ";
    cout << "End.\n";
    return 0;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}
bool cheaperThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if(r1->price < r2->price) 
		return true;
	return false;
}

bool FillReview(shared_ptr<Review> & rr)
{
	rr = shared_ptr<Review>(new Review);
    std::cout << "Enter title of the book (\"exit\" if you want to exit) : ";
    std::getline(std::cin, rr->title);
    if (rr->title == "exit")
        return false;
    std::cout << "Rate the book: ";
    std::cin >> rr->rating;
	 // clear the input buffer
	while (std::cin.get() != '\n')
        continue;
	std::cout << "Enter the price: ";
    std::cin >> rr->price;
    if (!std::cin)
        return false;
    // clear the input buffer
    while (std::cin.get() != '\n')
        continue;
	

    return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title << '\t'<<rr->price<<std::endl;
}

