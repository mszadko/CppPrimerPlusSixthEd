#include <iostream>
#ifndef __ABSTRACT_H__
#define __ABSTRACT_H__
//DMA - dynamic memory allocation.
class abstractDMA
{
private:
	char *label;
	int rating;
public:
	abstractDMA(const char* label_="EMPTY",int rating_=-1);
	abstractDMA(const abstractDMA& other);
	virtual ~abstractDMA();
	abstractDMA& operator=(const abstractDMA& other);
	virtual void View()=0;//pure virtual function. now you can't make abstractDMA object.	
	friend std::ostream & operator<<(std::ostream & outStream,const abstractDMA & obj);
};
#endif

#ifndef __BASEDMA_H__
#define __BASEDMA_H__
class baseDMA:public abstractDMA
{
public:
	baseDMA(const char* label_="EMPTY",int rating_=-1);
	//baseDMA(const baseDMA& other);
	//baseDMA& operator=(const baseDMA& other);
	//virtual ~baseDMA();//now virtual is optional
	virtual void View();
	//friend std::ostream& operator<<(std::ostream&outStream,const abstractDMA&obj);
};
#endif

#ifndef __LACKSDMA_H__
#define __LACKSDMA_H__
class lacksDMA:public abstractDMA
{
private:
	char color[40];//this will copy properly without operator == or copy constructor!
	//default functions copy object bit after bit so we only need to worry with pointers
public:
	lacksDMA(const char*label_="EMPTY",int rating_=-1, const char* color_="EMPTY");
	virtual void View();
	friend std::ostream& operator<<(std::ostream&outStream,const lacksDMA& obj);
};
#endif

#ifndef __HASDMA_H__
#define __HASDMA_H__
class hasDMA:public abstractDMA
{
private:
	char * style;
public:
	hasDMA(const char*label_="EMPTY",int rating_=-1,const char* style="EMPTY");
	hasDMA(const hasDMA& other);
	hasDMA& operator=(const hasDMA& other);
	~hasDMA();
	virtual void View();
	friend std::ostream& operator<<(std::ostream&outStream,const hasDMA &obj);
};
#endif