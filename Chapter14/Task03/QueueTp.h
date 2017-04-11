#include <iostream>
#ifndef QUEUE_H_
#define QUEUE_H_
template<typename T>
class QueueTp
{
private:
	T*elements;
	int count;
	int size;
public:
	QueueTp(int s=0):size(s),count(0){elements = new T[size];}
	QueueTp(const QueueTp<T> & other);
	~QueueTp(){delete[] elements;}
	QueueTp & operator=(const QueueTp<T>&other);
	bool enqueue(const T&element);
	bool dequeue(T&element);
};

template<typename T>
QueueTp<T>::QueueTp(const QueueTp<T>&other)
{
	elements = new T[other.size];
	for(int i = 0;i<other.count;i++)
	{
		elements[i]=other.elements[i];
	}
}

template<typename T>
QueueTp<T>& QueueTp<T>::operator=(const QueueTp<T>&other)
{
	if(this!=*other)
	{
		delete[] elements;
		size=other.size;
		count=other.count;
		elements= new T[other.size];
	}
	return *this;
}

template<typename T>
bool QueueTp<T>::enqueue(const T&element)
{
	if(count==size)
	{
		return false;
	}
	else
	{
		elements[count++]=element;
		return true;
	}
}
template<typename T>
bool QueueTp<T>::dequeue( T&element)
{
	if(count==0)
	{
		return false;
	}
	else
	{
		element=elements[--count];
		return true;
	}
}
#endif