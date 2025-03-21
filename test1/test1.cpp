
#include <iostream>
#include <string>
#include <clocale>

#include <__msvc_ostream.hpp>

#include "tiQueueSet.hpp"
#include "tiQueue.hpp"

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

tiQueue *tiQueue::getPtr(IDTYPE ID) const
{
	return tiQueueSet::getInstance()->get(ID);
}

void tiQueue::print() const
{
	if(this == nullptr)
		return;
	std::cout << "Привет, я Очередь " << name << ", ID: " << ID << "\n";
}

tiQueue *tiQueueSet::get(IDTYPE ID) const
{
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif
		
		return nullptr;
		

	return SegArr[segInd][index];
}

bool tiQueueSet::isExist(IDTYPE ID) const
{
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif
		
		return false;
		

		return false;
	else
		return true;
}

IDTYPE tiQueueSet::add(tiQueue *QueuePtr)
{
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	if(ArrI >= maxID)

	if(SegI >= SegSize)
		
	SegArr[Seg][SegI++] = QueuePtr;
		
	return ArrI++;
}

int tiQueueSet::del(IDTYPE ID)
{
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	return 0;
}

bool tiQueueSet::isFull() const
{
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

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

	for(IDTYPE i = 0; i < SegSize; ++i)
		SegArr[Seg][i] = nullptr;

}

int tiQueueSet::newSeg()
{
	#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
	#endif

	{
	}
	else
	{
			SegArr[Seg][i] = nullptr;
	}
}

int main()
{
	setlocale(0, "Russian");
	cout << "Файл: " << __FILE__ << endl;

	

	cout << "L:" << __LINE__ << "\n";

	
	
	q1 = q->getPtr(q0ID);

	cout << "L:"<<__LINE__<<"\n";

	q->print();

	q1->print();

	cout << "L:" << __LINE__ << "\n";

	
	cout << "L:" << __LINE__ << "\n";

	cout << "L:" << __LINE__ << "\n";

	cout << "L:" << __LINE__ << "\n";

	q1->getPtr(2)->print(); 

	cout << "L:" << __LINE__ << "\n";

	cout << "******************\n";

	return 0;
}

