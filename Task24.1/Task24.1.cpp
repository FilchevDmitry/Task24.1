#include <iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>
struct Tasks
{
	std::string name;
	std::time_t start;
	std::time_t end;
};
int main()
{
	/*
	std::time_t t = time(nullptr);
	int f = 0;
	std::cin >> f;
	std::time_t d = time(NULL);

	double tin = difftime(d, t);
	std::time_t c = d + (std::time_t)tin;

	std::tm* local = std::localtime(&c);
	std::cout <<std::asctime(local) << std::endl;
	*/
	std::string command;
	bool exit = true;
	std::vector<Tasks> tracking;
	int num = 0;
	while (exit)
	{
		std::cout << "Enter the command : begin, end, status, exit : ";
		std::cin >> command;
		if (command == "begin")
		{
			if (num > 0)
			{
				tracking[num-1].end= time(NULL);
			}
			tracking.push_back(Tasks());
			std::cout << "Enter the name of the task : ";
			tracking[num].start = time(NULL);
			std::cin.ignore();
			std::getline(std::cin,tracking[num].name);
			num++;
		}
		else if (command == "end")
		{
			if (num != 0) 
			{
				if (tracking[num - 1].end == 0)
				{
					tracking[num - 1].end = time(NULL);
				}
			}
			else
				std::cout << "No tasks assigned" << std::endl;
		}
		else if (command == "status")
		{
			for (int i = 0; i < tracking.size(); i++)
			{
				
				if (tracking[i].end != 0)
				{	
					std::cout << "Name - " << tracking[i].name << std::endl;
					std::cout <<"Task completion time - " << difftime(tracking[i].end, tracking[i].start)<<" seconds "<<std::endl;
				}
				else
				{
					std::cout << "The task is currently running - " << tracking[i].name << std::endl;
				}
			}
		}
		else if (command == "exit")
		{
			exit = false;
		}
		else
		{
			std::cout << "Incorrect input!!!" << std::endl;
		}
	}
}
