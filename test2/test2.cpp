

#include <iostream>
#include <clocale>
#include <string>
#include "..\tiQueue\tiQueue.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	tiQueue<int> queue1; 

	queue1.setDescription("Очередь 1");

	queue1.print();
	
	tiQueue<std::string> *queue2 = new tiQueue<std::string>(256); 

	queue2->print();

	tiQueue<int> q3; 
	q3.setDescription("Очередь 3");
	q3.print();
	q3.setDescription(); 

	delete queue2;

	return 0;
}

