#include "abstractDMA.h"
#include <string>
//===============================abstractDMA=======================================
abstractDMA::abstractDMA(const char* label_,int rating_):rating(rating_)
{
	int len =strlen(label_);
	label=new char[len+1];
	strcpy_s(label,len+1,label_);
	label[len]='\0';
}
abstractDMA::abstractDMA(const abstractDMA& other):abstractDMA(other.label,other.rating){}
abstractDMA::~abstractDMA()
{
	delete []label;
}
abstractDMA& abstractDMA::operator=(const abstractDMA& other)
{
	if(this!=&other)
	{
		delete []label;
		int len = strlen(other.label);
		label=new char[len+1];
		strcpy_s(label,len+1,other.label);
		label[len]='\0';
		rating=other.rating;
	}
	return *this;
}
std::ostream& operator<<(std::ostream &outStream,const abstractDMA&obj)
{
	outStream<<"Label: "<<obj.label<<std::endl;
	outStream<<"Rating: "<<obj.rating<<std::endl;
	return outStream;
}
//=============================end of abstractDMA==================================

//===================================baseDMA=======================================
baseDMA::baseDMA(const char*label_,int rating_):abstractDMA(label_,rating_){};
//baseDMA::baseDMA(const baseDMA& other):abstractDMA(other){};
//baseDMA& operator=(const baseDMA&other)
//{
//	abstractDMA::operator=(other);	
//}
void baseDMA::View()
{
	std::cout<<*this;
}
//===============================end of baseDMA====================================


//===================================lacksDMA======================================
lacksDMA::lacksDMA(const char* label_,int rating_,const char* color_):abstractDMA(label_,rating_)
{
	strncpy_s(color,color_,39);
	color[39]='\0';	
}
void lacksDMA::View()
{
	std::cout<<*this;
}
std::ostream& operator<<(std::ostream&outStream,const lacksDMA& obj)
{
	outStream<<(const abstractDMA&)obj;
	outStream<<"Color: "<<obj.color<<std::endl;	
	return outStream;
}

//===============================end of lacksDMA===================================

//===================================hasDMA========================================
hasDMA::hasDMA(const char*label_,int rating_,const char* style_):abstractDMA(label_,rating_)
{
	int len=strlen(style_);
	style=new char[len+1];
	strcpy_s(style,len+1,style_);
	style[len]='\0';
}
hasDMA::hasDMA(const hasDMA&other):abstractDMA(other)
{
	int len = strlen(other.style);
	style=new char[len+1];
	strcpy_s(style,len+1,other.style);
	style[len]='\0';
}
hasDMA& hasDMA::operator=(const hasDMA&other)
{
	if(this!=&other)
	{
		abstractDMA::operator=(other);
		delete []style;
		int len =strlen(other.style);
		style=new char[len+1];
		strcpy_s(style,len+1,other.style);
		style[len]='\0';
	}
	return *this;
}
hasDMA::~hasDMA()
{
	delete [] style;
}
void hasDMA::View()
{
	std::cout<<*this;
}
std::ostream& operator<<(std::ostream& outStream,const hasDMA&obj)
{
	outStream<<(abstractDMA&)obj;
	outStream<<"Style: "<<obj.style<<std::endl;	
	return outStream;
}
//================================end of hasDMA====================================