#include <valarray>
template <typename T1,typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	Pair() {};
	Pair(const T1& itemOne,const T2& itemTwo): a(itemOne), b(itemTwo){}
	//for editing
	T1 & first() {return a;}
	T2 & second() {return b;}
	//for reading
	T1 first() const {return a;}
	T2 second() const {return b;}
};