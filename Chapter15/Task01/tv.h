//tv.h --tv and remote classes
#ifndef TV_H
#define TV_H


class Tv
{
public:
	friend class Remote;//Remote class now have access to private data form tv class
	enum {Off,On};
	enum {MinVal,MaxVal = 20};//of the volume
	enum {Antenna,Cable};
	enum {TV, DVD};
private:
	int state;//on/off
	int volume;
	int maxchannel;
	int channel;//which one is turned on
	int mode;//cable or antenna
	int input;//tv or dvd
public:
	Tv(int s = Off,int mc = 125):state(s),volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV){};
	void onoff(){state = (state==Off)? On:Off;}
	bool ison()const {return state==On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
	void set_input(){input=(input==TV)?DVD:TV;}
	void settings() const;//display all settings	
	bool set_remote(Remote&r)const;
};

class Remote
{
	friend class Tv;
private:
	int mode;//controlls dvd or tv
	bool isInteractive;
public:
	Remote(int m =Tv::TV):mode(m),isInteractive(false){}
	bool volup(Tv&t){return t.volup();}
	bool voldown(Tv&t){return t.voldown();}
	void onoff(Tv&t){t.onoff();}
	void chanup(Tv&t){t.chanup();}
	void chandown(Tv&t){t.chandown();}
	void set_chan(Tv &t,int c){t.channel=c;}
	void set_mode(Tv&t){t.set_mode();}
	void set_input(Tv &t){t.set_input();}	
	void set_interactive() {isInteractive=(isInteractive==true?false:true);}
	void display();
};
#endif