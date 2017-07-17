#include <iostream>
#include <string>
#include <fstream>
#include "emp.h"

//==============abstr_emp class===================
abstr_emp::abstr_emp():fname(""), lname(""), job(""){}
abstr_emp::abstr_emp(const std::string &fn,const std::string &ln,const std::string &j)
:fname(fn),lname(ln),job(j){}
void abstr_emp::showAll()const
{
	std::cout<<"Personal data: "<<fname<<" "<<lname<<"\nWork as: "<<job<<std::endl;
}
void abstr_emp::setAll()
{
	std::cout<<"Enter name: ";
	getline(std::cin,fname);
	std::cout<<"Enter surname: ";
	getline(std::cin,lname);
	std::cout<<"Enter job position: ";
	getline(std::cin,job);
}
void abstr_emp::writeAll(std::ofstream & ofs) const
{
	using std::endl;
	ofs<<fname<<endl
		<<lname<<endl
		<<job  <<endl;
}
std::ostream& operator<<(std::ostream& os,const abstr_emp&e)
{
	os<<e.fname<<" "<<e.lname;
	return os;
}
abstr_emp::~abstr_emp(){};

//================employee class============
employee::employee():abstr_emp(){}
employee::employee(const std::string &fn,const std::string &ln,const std::string &j):abstr_emp(fn,ln,j){}
void employee::showAll() const
{
	std::cout<<"EMPLOYEE\n";
	abstr_emp::showAll();
	std::cout<<std::endl;
}
void employee::writeAll(std::ofstream & ofs) const
{
	using std::endl;
	ofs<<classkind::Employee<<endl;
	abstr_emp::writeAll(ofs);
}
//================manager class============
manager::manager(){}
manager::manager(const std::string &fn,const std::string &ln,const std::string &j,int ico):abstr_emp(fn,ln,j)
{inchargeof=ico;}
manager::manager(const abstr_emp &e,int ico):abstr_emp(e){inchargeof=ico;}
//manager::manager(const manager &m);
void manager::showAll()const
{
	std::cout<<"MANAGER\n";
	abstr_emp::showAll();
	std::cout<<"Is in charge of "<<inchargeof<<" subordinates\n"<<std::endl;
}
void manager::setAll()
{
	abstr_emp::setAll();
	std::cout<<"Enter number of subordinates: ";
	std::cin>>inchargeof;
	while(std::cin.get()!='\n') 
		continue;
}
void manager::writeAll(std::ofstream & ofs) const
{
	using std::endl;
	ofs<<classkind::Manager<<endl;
	abstr_emp::writeAll(ofs);
	ofs<<inchargeof<<endl;
}
//====================fink class===========
fink::fink(){}
fink::fink(const std::string &fn,const std::string &ln,const std::string &j,const std::string &rt)
:abstr_emp(fn,ln,j){reportsto=rt;}
fink::fink(const abstr_emp &e,const std::string &rt):abstr_emp(e){reportsto=rt;}
//fink::fink(const fink &f){}
void fink::showAll()const
{
	std::cout<<"FINK\n";
	abstr_emp::showAll();
	std::cout<<"Is reporting to :"<<reportsto<<std::endl<<std::endl;
}
void fink::setAll()
{
	abstr_emp::setAll();
	std::cout<<"Enter person whom fink is going to report to: ";
	getline(std::cin,reportsto);
}
void fink::writeAll(std::ofstream & ofs) const
{
	using std::endl;
	ofs<<classkind::Fink<<endl;
	abstr_emp::writeAll(ofs);
	ofs<<reportsto<<endl;
}
//==============highfink class================
highfink::highfink(){};
highfink::highfink(const std::string &fn,const std::string &ln,const std::string &j,const std::string &rt,int ico)
:abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rt){}
highfink::highfink(const abstr_emp&e ,const std::string &rt,int ico)
:abstr_emp(e),manager(e,ico),fink(e,rt){}
highfink::highfink(const fink&f,int ico)
:abstr_emp(f),manager(f,ico),fink(f){}
highfink::highfink(const manager &m,const std::string &rt)
:abstr_emp(m),manager(m),fink(m,rt){}
//highfink::highfink(const highfink&hf);
void highfink::showAll()const
{
	std::cout<<"HIGHFINK\n";
	abstr_emp::showAll();
	//can't do the same with both base classes cuz i will display same information 3 times
	std::cout<<"Is in charge of "<<inChargeOf()<<" subordinates\n";
	std::cout<<"Is reporting to :"<<reportsTo()<<std::endl<<std::endl;
}
void highfink::setAll()
{
	//smarter way
	manager::setAll();
	std::cout<<"Enter person whom highfink is going to report to: ";
	getline(std::cin,reportsTo());
}
void highfink::writeAll(std::ofstream & ofs) const
{
	using std::endl;
	ofs<<classkind::Highfink<<endl;
	abstr_emp::writeAll(ofs);
	ofs<<inChargeOf()<<endl;
	ofs<<reportsTo()<<endl;
}