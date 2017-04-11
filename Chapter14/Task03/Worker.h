//code form book (listing 14.10)
#ifndef WORKER_H_
#define WORKER_H_
#include <string>

class Worker{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker() :fullname("empty"),id(0L){}
	Worker(const std::string & s,long n):fullname(s),id(n){}
	virtual ~Worker()= 0; //this one is purely virtual
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter:virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter():Worker(),panache(0){}
	Waiter(const std::string &s,long n,int p):Worker(s,n),panache(p){}
	Waiter(const Worker &w,int p):Worker(w),panache(p){}
	void Set();
	void Show() const;	
};

class Singer:virtual public Worker
{
protected:
	enum {other,alto,contralto,soprano,bass,baritone,tenor};
	enum {Vtypes = 7};
	void Data()const;
	void Get();
private:
	static const char *pv[Vtypes];
	int voice;
public:
	Singer():Worker(),voice(other){}
	Singer(const std::string &s,long n,int v=other):Worker(s,n),voice(v){}
	Singer(const Worker &w,int v =other):Worker(w),voice(v){}
	void Set();
	void Show() const;	
};

class SingingWaiter:public Singer,public Waiter
{
protected:
	void Data()const;
	void Get();
public:
	SingingWaiter(){}
	SingingWaiter(const std::string &s,long n,int p =0,int v=other):Worker(s,n),Singer(s,n,v),Waiter(s,n,p){}//waiter and singer are virtual classes
	SingingWaiter(const Worker & w, int p,int v=other):Worker(w),Waiter(w,p),Singer(w,v){}
	SingingWaiter(const Waiter & wt, int v=other):Worker(wt),Waiter(wt),Singer(wt,v){}
	SingingWaiter(const Singer & s,int p):Worker(s),Waiter(s,p),Singer(s){}
	void Set();
	void Show()const;
};
#endif