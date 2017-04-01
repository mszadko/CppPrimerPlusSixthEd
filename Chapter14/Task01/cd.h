//base class header - given in task
class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char * s1, char *s2, int n, double x);
	Cd(const Cd* d);
	Cd();
	virtual ~Cd();//this should be virtual becouse derived class may need to delete some objects
	virtual void Report() const;//this should be virtaul becouse we need to display additional info in derived class
	Cd& operator=(const Cd&);//no need to make this virtual
	//this operator in derived class will be declared as Derived& operator=() <->different signature
};