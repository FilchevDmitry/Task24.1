#include <iostream>
#include<ctime>

int main()
{
	std::time_t t = time(nullptr);
	int f = 0;
	std::cin >> f;
	std::time_t d = time(NULL);

	double tin = difftime(d, t);
	std::time_t c = d + (std::time_t)tin;

	std::tm* local = std::localtime(&c);
	std::cout <<std::asctime(local) << std::endl;
	
}
