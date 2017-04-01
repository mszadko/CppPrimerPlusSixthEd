#include "cd.h"
class Classic : public Cd
{
	private:
char legendarySong [25];
	public:
	Classic(char *s1,char *s2,char *s3, int n,double x);
	Classic(const Classic*c);
	virtual ~Classic();// virtual keyword is optional but it is a good practice to use it in every derived class
	Classic& operator=(const Classic&);
	virtual void Report() const;
};