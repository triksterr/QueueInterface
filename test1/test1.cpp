

#include <iostream>
#include <clocale>

#include <__msvc_ostream.hpp>

#include "..\tiTypes.hpp"
#include "..\tiQueue\tiQueue.hpp"

using namespace std;

int main()
{
	setlocale(0, "Russian");
	#if defined(_DEBUG) && !defined(NDEBUG) 
	cout << "Файл: " << __FILE__ << endl;
	#endif 

	tiQueue<int> *q, *q1; 

	q = new tiQueue<int>("Q-0"); 

	IDTYPE q0ID = q->getID(); 

	cout << "L:" << __LINE__ << "\n";

	q = new tiQueue<int>("Q-1"); 

	IDTYPE q1ID = q->getID(); 
	
	q1 = q->getPtr(q0ID);

	cout << "L:"<<__LINE__<<"\n";

	q->print();

	q1->print();

	q->getPtr(1)->print();

	cout << "L:" << __LINE__ << "\n";

	q = new tiQueue<int>("Q-2"); 
	
	cout << "L:" << __LINE__ << "\n";

	q->getPtr(q0ID)->print(); 

	cout << "******************\n";

	return 0;
}

