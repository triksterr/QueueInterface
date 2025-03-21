

#include "tiQueueSet.hpp"

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
		if(newSeg()) 
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

	SegArr = new tiQueue * *[NSegMAX];
	
	for(IDTYPE i = 0; i < NSegMAX; ++i)
		SegArr[i] = nullptr;

	Seg = 0; 
	
	SegArr[Seg] = new tiQueue * [SegSize]; 
	
	for(IDTYPE i = 0; i < SegSize; ++i)
		SegArr[Seg][i] = nullptr;

	SegI = 0; 
	ArrI = 0; 
}

tiQueueSet::~tiQueueSet()
{
	
#if defined(_DEBUG) && !defined(NDEBUG)
	std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
#endif

	for(IDTYPE i = 0; i <= Seg; ++i)
		delete[] SegArr[i];
	
	delete[] SegArr;
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

