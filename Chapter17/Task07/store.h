#include <fstream>
class Store
{
public:
	Store(std::ofstream & fout);
	Store & operator()(std::string const & str);
private:
	std::ofstream * fout_;
};