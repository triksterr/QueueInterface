#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include "..\tiTypes.hpp"
#include "tiQueueBase.hpp"

#include <string>

template <typename T>
class tiQueue : public tiQueueBase
{
public:
	
	tiQueue();
	
	tiQueue(SIZETYPE size);
	
	tiQueue(const std::string &name);
	
	~tiQueue();
	
	IDTYPE getID() const;
	
	tiQueue *getPtr(IDTYPE ID) const;
	
	void print() const;

private:
	SIZETYPE size = 1; 
	SIZETYPE capacity = 1; 
	SIZETYPE input = 0; 
	SIZETYPE output = 0; 
	bool isEmpty = true; 
	
	std::string description = ""; 
	IDTYPE ID = 0; 
};

#endif 