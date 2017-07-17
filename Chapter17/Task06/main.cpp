#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>//exit()
#include "emp.h"

int const MAX = 10;

bool inline DoesFileExist(std::string const file_path)
{
	std::ifstream file_input(file_path);
	return file_input.good();
}
int main(int argc, char* argv[])
{
	int count = 0;
	abstr_emp * pc[MAX];
	if(argc==1)//if there are no arguments(argv[0] is program name)
	{
		std::cerr<<"You did't pass file name!";
		exit(EXIT_FAILURE);
	}
	if(DoesFileExist(argv[1]))
	{ 
		std::ifstream file_input(argv[1]);
		{
			int employee_type;
			std::string f_name;
			std::string l_name;
			std::string job_position;
			std::string reports_to;
			int in_charge_of;
			file_input>>employee_type;
			file_input.get();//clears new line
			while(file_input.good())
			{
				getline(file_input,f_name);
				getline(file_input,l_name);
				getline(file_input,job_position);
				
				switch(employee_type)
				{
					case classkind::Employee:
						pc[count++] = new employee(f_name,l_name,job_position);
						break;
					case classkind::Manager :
						file_input>>in_charge_of;
						file_input.get();
						pc[count++] = new manager(f_name,l_name,job_position,in_charge_of);
						break;
					case classkind::Fink	:
						getline(file_input,reports_to);
						pc[count++] = new fink(f_name,l_name,job_position,reports_to);
						break;
					case classkind::Highfink:
						file_input>>in_charge_of;
						file_input.get();
						getline(file_input,reports_to);
						pc[count++] = new highfink(f_name,l_name,job_position,reports_to,in_charge_of);
						break;
				}
				file_input>>employee_type;
				file_input.get();//clears new line
			}
			std::cout<<"Displaying content of "<<argv[1]<<"\n";
			for(size_t i = 0; i<count; i++)
			{
				pc[i]->showAll();
			}
			std::cout<<"\nEND OF FILE.\n";
		}
	}
	std::ofstream file_output(argv[1],std::ios_base::out|std::ios_base::app);//opens output file stream that append new content to the old one.
	if(!file_output.is_open())
	{
		std::cerr<<"ERROR. Cannot open file in write mode.\n";	
		exit(EXIT_FAILURE);
	}
	{//this part asks for new employees and their personal data.
		int employee_type = classkind::Employee;
		while(employee_type && count < MAX)
		{
			std::cout<<"What type of a employee you want to add?\n"<<
			classkind::Employee<<". Employee\n"<<
			classkind::Manager <<". Manager\n" <<
			classkind::Fink    <<". Fink\n"    <<
			classkind::Highfink<<". Highfink: ";
			std::cin>>employee_type;
			std::cin.get();
			if(!std::cin.good())//reset cin when invalid data entered
			{
				std::cin.clear();
				while(std::cin.get()!='\n')
					continue;
			}
			switch(employee_type)
			{
				case classkind::Employee:	
					pc[count] = new employee();
					break;
				case classkind::Manager	:	
					pc[count] = new manager();
					break;
				case classkind::Fink	:	
					pc[count] = new fink();
					break;
				case classkind::Highfink:	
					pc[count] = new highfink();
					break;
				default:
					continue;//i want to skip the ->setAll() function because i don't have new element
			}
			pc[count]->setAll();
			pc[count++]->writeAll(file_output);
		}
	}
	for(size_t i = 0; i<count; i++)
	{
		pc[i]->showAll();
		delete pc[i];
	}
	return 0;
}
