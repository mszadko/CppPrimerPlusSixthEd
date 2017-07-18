#include <fstream>
#include "store.h"



Store::Store(std::ofstream & fout)
	{
		fout_ = &fout;
	}
Store& Store::operator()(std::string const & str)
	{
		size_t size = str.size();
		fout_->write((char*)&size,sizeof(size_t));
		fout_->write(str.data(),size);
		return *this;
	}