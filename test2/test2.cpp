

#include <iostream>
#include <string>
#include "..\tiQueue\tiQueue.hpp"

int main()
{
	
	tiQueue<int> queue1; 

	queue1.print();
	
	tiQueue<std::string> *queue2 = new tiQueue<std::string>("queue2"); 

	queue2->print();

	delete queue2;

	return 0;
}

