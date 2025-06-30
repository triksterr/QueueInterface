

#include <iostream>
#include <clocale>
#include <string>
#include "..\tiQueue\tiQueue.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Test 2\n\n";
	
	tiQueue<int> q1(10); 

	q1.print();

	q1.printData();
	
	q1.push(127); 
	q1.printData();
	q1.push(2); q1.push(3); q1.push(4); q1.push(5); q1.push(6); q1.push(7); q1.push(8); q1.push(9);
	q1.printData();
	q1.push(1); 
	q1.printData();

	return 0;
	
	tiQueue<std::string> *q2 = new tiQueue<std::string>(256); 

	q2->print();

	delete q2;

	return 0;
}

