#include "cd.h"
class Classic : public Cd
{
	private:
char *legendarySong;
	public:
	Classic(char *s1=(char*)"none",char *s2=(char*)"none",char *s3=(char*)"none", int n=-1,double x=-1.0);
	Classic(const Classic&c);//we need deep copy
	virtual ~Classic();// virtual keyword is optional but it is a good practice to use it in every derived class
	Classic& operator=(const Classic&);
	virtual void Report() const;
};