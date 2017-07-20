#include <string>
#include <iostream>



class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
		Info(std::string q="",std::string z=""):qcode(q),zcode(z){}
	};
private:
	Info *pi_;
public:
	Cpmv();
	Cpmv(std::string q,std::string z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator=(const Cpmv&cp);
	Cpmv & operator=(Cpmv&&mv);
	Cpmv operator+(const Cpmv &obj)const;
	void Display() const;
};

Cpmv::Cpmv()
{
	std::cout<<"Cpmv()\n";
	pi_ = new Info();
	std::cout<<"I made ";
	Display();
}
Cpmv::Cpmv(std::string q, std::string z)
{
	std::cout<<"Cpmv(q,z)\n";
	pi_ = new Info(q,z);
	std::cout<<"I made ";
	Display();
}
Cpmv::Cpmv(const Cpmv & cp)
{
	std::cout<<"Cpmv(const &)\n";
	pi_ = new Info();
	pi_->qcode=cp.pi_->qcode;
	pi_->zcode=cp.pi_->zcode;
	std::cout<<"I made ";
	Display();
}

Cpmv::Cpmv(Cpmv && mv)
{
	std::cout<<"Cpmv(&&)\n";
	pi_ = mv.pi_;
	mv.pi_ = nullptr;
	std::cout<<"I made ";
	Display();
}	
Cpmv::~Cpmv()
{
	std::cout<<"~Cpmv()\n";
	delete pi_;
}

Cpmv & Cpmv::operator=(const Cpmv& cp)
{
	std::cout<<"operator=(&)\n";
	if(this == &cp)
		return *this;
	delete pi_;
	pi_ = new Info(cp.pi_->qcode,cp.pi_->zcode);
	return *this;
}
Cpmv & Cpmv::operator=(Cpmv&&mv)
{
	std::cout<<"operator=(&&)\n";
	if(this == &mv)
		return *this;
	delete pi_;
	pi_ = mv.pi_;
	mv.pi_=nullptr;
	return *this;
}
Cpmv Cpmv::operator+(const Cpmv &obj)const
{
	Cpmv temp(this->pi_->qcode+obj.pi_->qcode,this->pi_->zcode+obj.pi_->zcode);
	return temp;
}
void Cpmv::Display() const
{
	std::cout<<"Q: " <<pi_->qcode<<"\t Z: "<<pi_->zcode<<std::endl;
}

int main()
{
	Cpmv a("qqq","zzz");
	a.Display();
	Cpmv b(a);
	b.Display();
	std::cout<<"c=a+b\n";
	Cpmv c = a + b;
	std::cout<<"c+a\n";
	c+a;
	return 0;
}