//base class header - given in task
class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	//all those (char*) casting are for hiding warnings in g++ compiler
	// char* ="none" === char* = const char[] and complier does not like it
	Cd(char * s1=(char*)"none", char *s2=(char*)"none", int n=-1, double x=-1.0);
	
	//Cd(const Cd* d);//shallow copy is enough
	virtual ~Cd();//this should be virtual becouse derived class may need to delete some objects
	virtual void Report() const;//this should be virtaul becouse we need to display additional info in derived class
	//Cd& operator=(const Cd&);//different signature is wont be derrived
	//this operator in derived class will be declared as Derived& operator=() <->different signature
};