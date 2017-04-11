#include <string>
#include <valarray>
#include "pair.h"
#ifndef WINEC__H
#define WINEC__H
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;
class Wine
{
private:
	std::string label;
	int numberOfVintages;
	PairArray yearsBottlesPair;
public:
	Wine(const char * l,int y, const int yr[],const int bot[]);
	Wine(){};
	Wine(const char *l,int  y);
	std::string & Label() {return label;}
	void GetBottles();
	void Show() const;
	int Sum() const;
};

#endif