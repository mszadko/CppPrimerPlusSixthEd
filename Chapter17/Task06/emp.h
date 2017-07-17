#include <iostream>
#include <string>

enum classkind{Employee = 1,Manager = 2,Fink = 3,Highfink = 4};

class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string &fn,const std::string &ln,const std::string &j);
	virtual void showAll()const;//displays all data with titles
	virtual void setAll();//asks user for data
	virtual void writeAll(std::ofstream & ofs) const;
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp &e);//displays only first and last name
	virtual ~abstr_emp()=0;//abstract base class
};

class employee : public abstr_emp
{
public:	
	employee();
	employee(const std::string &fn,const std::string &ln,const std::string &j);
	virtual void showAll() const;
	//virtual void setAll();
	virtual void writeAll(std::ofstream & ofs) const;
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;//number of managed objects of abstr_emp
protected:
	int inChargeOf()const {return inchargeof;}//output
	int & inChargeOf(){return inchargeof;}//input
public:
	manager();
	manager(const std::string &fn,const std::string &ln,const std::string &j,int ico);
	manager(const abstr_emp &e,int ico);
	//manager(const manager &m);
	virtual void showAll()const;
	virtual void setAll();
	virtual void writeAll(std::ofstream & ofs) const;
};

class fink:virtual public abstr_emp
{
private:
	std::string reportsto;
protected:
	const std::string reportsTo() const {return reportsto;}
	std::string & reportsTo(){return reportsto;}
public:
	fink();
	fink(const std::string &fn,const std::string &ln,const std::string &j,const std::string &rt);
	fink(const abstr_emp &e,const std::string &rt);
	//fink(const fink &f);
	virtual void showAll()const;
	virtual void setAll();
	virtual void writeAll(std::ofstream & ofs) const;
};

class highfink:public manager, public fink
{
	public:
	highfink();
	highfink(const std::string &fn,const std::string &ln,const std::string &j,const std::string &rt,int ico);
	highfink(const abstr_emp&e ,const std::string &rt,int ico);
	highfink(const fink&f,int ico);
	highfink(const manager &m,const std::string &rt);
	//highfink(const highfink&hf);
	virtual void showAll()const;
	virtual void setAll();
	virtual void writeAll(std::ofstream & ofs) const;
};