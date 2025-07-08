#pragma once
#ifndef tiQueueSet_hpp
#define tiQueueSet_hpp

#include "..\tiTypes.hpp"

class tiQueueSet final
{
	friend class tiQueueBase; 
	template<typename T>
	friend class tiQueue; 

private:
	
	static tiQueueSet *getInstance();
	
	tiQueueBase *get(IDTYPE ID) const;
	
	bool isExist(IDTYPE ID) const;
	
	IDTYPE add(tiQueueBase *QueuePtr);
	
	int del(IDTYPE ID);
	
	IDTYPE getCount() const 
	{
		return queueCount; 
	}
	
	bool isFull() const;

	tiQueueSet(); 
	tiQueueSet(const tiQueueSet &) = delete; 
	tiQueueSet(tiQueueSet &&) = delete; 
	~tiQueueSet(); 
	tiQueueSet &operator=(const tiQueueSet &) = delete; 
	tiQueueSet &operator=(tiQueueSet &&) = delete; 
	
	int newSeg();
	
	const IDTYPE SegSize = SSIZE;
	
	const IDTYPE NSegMAX = NSEG;
	
	const IDTYPE maxID = (SegSize * NSegMAX) - 1;
	
	IDTYPE Seg = 0;
	
	IDTYPE SegI = 0;
	
	IDTYPE ArrI = 0;
	
	tiQueueBase ***SegArr = nullptr;
	
	IDTYPE queueCount = 0;
	
};

#endif 