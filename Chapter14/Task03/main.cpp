#include <iostream>
#include <cstring>
#include "Worker.h"
#include "QueueTp.h"

const int SIZE=5;
int main()
{
	using std::cout;
	using std::cin;
	QueueTp<Worker*> queue(SIZE);
	int ct;
	Worker* worker_u_hired;
	for(ct = 0;ct<SIZE; ct++)
	{
		char choice;
		cout<<"What kind of worker do you want to hire?\n"
		<<"w-Waiter\ts-Singer\ta-Singing Waiter\te-Exit:\t";
		cin>>choice;
		while(strchr("wsae",choice)==NULL)//strchr returns index of choice in 'wsae' or null if there is not choice in the string
		{
			cout<<"Enter w,s,a,or e: ";
			cin>>choice;
		}
		if(choice=='e')
			break;
		switch(choice)
		{
			case 'w':
			case 'W': worker_u_hired = new Waiter();
					break;
			case 's':
			case 'S': worker_u_hired = new Singer();
					break;
			case 'a':
			case 'A': worker_u_hired = new SingingWaiter();
					break;
		}
		cin.get();
		worker_u_hired->Set();
		queue.enqueue(worker_u_hired);
	}
	cout<<"Workers list\n";
	int i;
	for(i = 0;i<ct; i++)
	{
		queue.dequeue(worker_u_hired);
		worker_u_hired->Show();
	}
	cout<<"END";
	return 0;
}