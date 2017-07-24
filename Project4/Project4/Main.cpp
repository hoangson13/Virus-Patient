#include<iostream>
#include "Patient.h"
#include <time.h>
int main()
{
	srand(time(NULL));
	Patient p;
	char t = 0;
	while (p.GetState() == p.ALIVE)
	{
		std::cout << "Take Medicine (0 = NO, 1 = YES): " << std::endl;
		std::cin >> t;
		p.TakeMedicine(t);
		if (p.GetHealthy()) {
			std::cout << "The patient is now healthy" << std::endl;
			break;
		}
		if (p.GetState() == p.DEATH) std::cout << "The patient die!!!" << std::endl;
	}
	system("pause");
	return 0;
}