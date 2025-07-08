

#include <iostream>
#include <clocale>
#include <string>
#include "..\tiQueue\tiQueue.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Test 2\n\n";
	
	tiQueue<int> q1(2); 

	q1.printData();
	q1.push(127);
	q1.push(128);
	q1.printData();
	
	std::cout << q1.pop() << "\n";
	std::cout << q1.pop() << "\n";
	std::cout << q1.pop() << "\n";
	std::cout << q1.pop() << "\n";
	
	q1.pushOver(1);
	q1.pushOver(2);
	q1.printData();
	q1.push(3);
	q1.push(4);
	q1.printData();

	std::cout << q1.pop() << "\n";
	std::cout << q1.pop() << "\n";

	return 0; 
	
	tiQueue<std::string> *q2 = new tiQueue<std::string>(26); 

	q2->print();
	q2->printData();

	q2->push("Hello"); q2->push("World");
	q2->printData();
	q2->push("1"); q2->push("2"); q2->push("3"); q2->push("4"); q2->push("5"); q2->push("6"); q2->push("7"); q2->push("8"); q2->push("9"); q2->push("10");
	q2->printData();

	delete q2;

	return 0;
}

