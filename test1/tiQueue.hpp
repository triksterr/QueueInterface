#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include <string>

#define IDTYPE unsigned long long 

class tiQueue
{
public:
	
	tiQueue();
	
	tiQueue(const std::string &name);
	
	~tiQueue();
	
	IDTYPE getID() const;
	
	tiQueue *getPtr(IDTYPE ID) const;
	
	void print() const;

private:
	std::string name = "";
	IDTYPE ID = 0;
};

#endif 