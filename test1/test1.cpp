

#include <iostream>
#include <string>
#include <clocale>

#include <__msvc_ostream.hpp>

#include "tiQueueSet.hpp"
#include "tiQueue.hpp"

using namespace std;

tiQueue::tiQueue(): tiQueue("Noname") {}
	
tiQueue::tiQueue(const string &name): name(name)
{
	
	ID = tiQueueSet::getInstance()->add(this);

	std::cout << "Очередь " << name << ", ID: " << ID << " создана!\n";
}

tiQueue::~tiQueue()
{
	
	std::cout << "Очередь " << name << ", ID: " << ID << " уничтожена!\n";
}

IDTYPE tiQueue::getID() const
{
	return ID;
}

tiQueue *tiQueue::getPtr(IDTYPE id) const
{
	return tiQueueSet::getInstance()->get(id);
}

void tiQueue::print() const
{
	if(this == nullptr)
		return;
	std::cout << "Привет, я Очередь " << name << ", ID: " << ID << "\n";
}

tiQueueSet *tiQueueSet::getInstance() 
{
	

	
#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
#endif

	static tiQueueSet instance; 

	return &instance;
}

tiQueue *tiQueueSet::get(IDTYPE ID) const
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif
		
	if(ID < 0 || ID >= ArrI) 
		return nullptr;
		
	IDTYPE segInd = ID / SegSize; 
	IDTYPE index = ID % SegSize; 

	return SegArr[segInd][index];
}

bool tiQueueSet::isExist(IDTYPE ID) const
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif
		
	if(ID < 0 || ID >= ArrI) 
		return false;
		
	IDTYPE segInd = ID / SegSize; 
	IDTYPE index = ID % SegSize; 

	if(!SegArr[segInd][index]) 
		return false;
	else
		return true;
}

IDTYPE tiQueueSet::add(tiQueue *QueuePtr)
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	if(!QueuePtr) 
		return -1; 

	
	if(ArrI >= maxID)
		return -2; 

	
	if(SegI >= SegSize)
		if(!newSeg()) 
			return -3; 
		
	
	SegArr[Seg][SegI++] = QueuePtr;
		
	return ArrI++;
}

int tiQueueSet::del(IDTYPE ID)
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	if(ID < 0 || ID >= ArrI) 
		return -1; 

	IDTYPE segInd = ID / SegSize; 
	IDTYPE index = ID % SegSize; 

	delete SegArr[segInd][index]; 
	SegArr[segInd][index] = nullptr; 

	return 0;
}

bool tiQueueSet::isFull() const
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	if(ArrI > maxID) 
		return true;

	return false;
}

tiQueueSet::tiQueueSet()
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	
	SegArr = new tiQueue **[NSegMAX];

	
	for(IDTYPE i = 0; i < NSegMAX; ++i)
		SegArr[i] = nullptr;

	Seg = 0; 

	
	SegArr[Seg] = new tiQueue *[SegSize]; 

	
	for(IDTYPE i = 0; i < SegSize; ++i)
		SegArr[Seg][i] = nullptr;

	SegI = 0; 
	ArrI = 0; 
}

int tiQueueSet::newSeg()
{
	
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	++Seg; 
	if(Seg > NSegMAX) 
	{
		--Seg; 
		return -1; 
	}
	else
	{
		SegArr[Seg] = new tiQueue * [SegSize]; 
		for(IDTYPE i = 0; i < SegSize; ++i) 
			SegArr[Seg][i] = nullptr;
		SegI = 0; 
		return 0; 
	}
}

int main()
{
	setlocale(0, "Russian");
	#if defined(_DEBUG) && !defined(NDEBUG) 
	cout << "Файл: " << __FILE__ << endl;
	#endif 

	
	

	tiQueue *q, *q1; 

	q = new tiQueue("Q-0"); 

	IDTYPE q0ID = q->getID(); 

	cout << "L:" << __LINE__ << "\n";

	q = new tiQueue("Q-1"); 

	IDTYPE q1ID = q->getID(); 

	

	
	
	
	
	q1 = q->getPtr(q0ID);

	cout << "L:"<<__LINE__<<"\n";

	q->print();

	q1->print();

	cout << "L:" << __LINE__ << "\n";

	q = new tiQueue("Q-2"); 
	
	
	
	cout << "L:" << __LINE__ << "\n";

	q->getPtr(q0ID)->print(); 

	cout << "L:" << __LINE__ << "\n";

	q->print(); 

	cout << "L:" << __LINE__ << "\n";

	q1->getPtr(2)->print(); 

	cout << "L:" << __LINE__ << "\n";

	

	
		

	
	

	
	

	return 0;
}

