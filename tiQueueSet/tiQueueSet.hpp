#pragma once
#ifndef tiQueueSet_hpp
#define tiQueueSet_hpp

#include "..\tiQueue\tiQueueBase.hpp"
#include "..\tiTypes.hpp"

class tiQueueSet final
{
public:
	
	static tiQueueSet *getInstance();
	
	tiQueueBase *get(IDTYPE ID) const;
	
	bool isExist(IDTYPE ID) const;
	
	IDTYPE add(tiQueueBase *QueuePtr);
	
	int del(IDTYPE ID);

private:
	
	bool isFull() const;

	tiQueueSet(); 
	tiQueueSet(const tiQueueSet &) = delete; 
	tiQueueSet(tiQueueSet &&) = delete; 
	~tiQueueSet(); 
	tiQueueSet &operator=(const tiQueueSet &) = delete; 
	tiQueueSet &operator=(tiQueueSet &&) = delete; 
	
	bool isSegFull(); 
	
	int newSeg();
	
	const IDTYPE SegSize = SSIZE;
	
	const IDTYPE NSegMAX = NSEG;
	
	const IDTYPE maxID = (SegSize * NSegMAX) - 1;
	
	IDTYPE Seg = 0;
	
	IDTYPE SegI = 0;
	
	IDTYPE ArrI = 0;
	
	tiQueueBase ***SegArr = nullptr;
};

#endif 