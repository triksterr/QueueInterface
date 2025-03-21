#pragma once
#ifndef tiQueueSet_hpp
#define tiQueueSet_hpp

#include "tiQueue.hpp"

#define IDTYPE unsigned long long 

#define SSIZE 2 
#define NSEG 256 

class tiQueueSet final
{
public:
	
	static tiQueueSet *getInstance();
	
	tiQueue *get(IDTYPE ID) const;
	
	bool isExist(IDTYPE ID) const;
	
	IDTYPE add(tiQueue *QueuePtr);
	
	int del(IDTYPE ID);
	
	bool isFull() const;

private:
	
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
	
	tiQueue ***SegArr = nullptr;
};

#endif 