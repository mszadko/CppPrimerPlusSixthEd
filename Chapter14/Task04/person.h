#include <iostream>
#include <string>
#ifndef PERSON_H_
#define PERSON_H_
class person
{
private:
	std::string fullname;
	
public:
	person(const char * name="empty"):fullname(name){}
	virtual void show(){std::cout<<"Personal information: "<<fullname<<std::endl;}
	virtual ~person(){}
	virtual void set();
};

class gunslinger:virtual public person
{
private:
	double draw_time;
	int kills;
public:
	gunslinger(const char* name="empty",double time=-1,int k =-1):person(name),draw_time(time),kills(k){}
	gunslinger(const person& p,double time=-1,int k =-1):person(p),draw_time(time),kills(k){}
	double draw()const{return draw_time;}
	void show(){person::show();		std::cout<<"confirmed kills: "<<kills<<"\nready to shoot in: "<<draw_time<<" sec.\n";}
	void set();
};

class pokerPlayer:virtual public person
{
public:
	pokerPlayer(const char* name="empty"):person(name){}
	int draw();
};

class badDude:public gunslinger,public pokerPlayer
{
public:
	badDude(const char* name="empty",double time=-1,int k =-1):person(name),gunslinger(name,time,k),pokerPlayer(name){}
	double gdraw(){return gunslinger::draw();}
	int cdraw(){return pokerPlayer::draw();}
};
#endif