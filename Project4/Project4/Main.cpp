#include<iostream>
#include "Patient.h"
#include <time.h>
int main()
{
	srand(time(NULL));
	Patient p;
	char t = 0;
	while (p.GetState() == 1)
	{
		printf("Take Medicine (0 = NO, 1 = YES): ");
		std::cin >> t;
		p.TakeMedicine(t);
		if (p.GetHealthy()) break;
	}
	getchar();
	return 0;
}