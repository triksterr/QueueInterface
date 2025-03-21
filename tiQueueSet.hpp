#pragma once
#ifndef tiQueueSet_hpp
#define tiQueueSet_hpp

#include "tiInterface.hpp"

#define IDTYPE unsigned int 

class tiQueueSet final
{
public:
	
	
	static tiQueueSet *getInstance();
	
	
	
	
	tiQueue *get(IDTYPE ID);
	

	

	
	
	
	
	int set(IDTYPE ID, tiQueue *QueuePtr);
	
	
	
	

	

	
	
	
	IDTYPE add(tiQueue *QueuePtr);
	

	
	
	
	int del(IDTYPE ID);
	

	
	
	bool isFull();

private:
	
	tiQueueSet();
	
	tiQueueSet(const tiQueueSet &) = delete;
	
	tiQueueSet(tiQueueSet &&) = delete;
	
	tiQueueSet &operator=(const tiQueueSet &) = delete;
	
	tiQueueSet &operator=(tiQueueSet &&) = delete;
	
	~tiQueueSet() = default;

	bool isSegFull(); 

	
	

	IDTYPE SegSize = 256; 
	IDTYPE NSegMAX = 256; 
	IDTYPE NSeg = 0; 
	IDTYPE SetSize = 0; 
	
};

#endif 