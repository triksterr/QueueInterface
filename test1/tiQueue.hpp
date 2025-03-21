#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include <string>

using namespace std;

#define IDTYPE unsigned int 

class tiQueue
{
public:
	
	tiQueue();
	
	tiQueue(const string &name);
	
	~tiQueue();
	
	IDTYPE getID() const;
	
	tiQueue *getPtr(IDTYPE ID) const;
	
	void print() const;

private:
	string name = "";
	IDTYPE ID = 0;
};

#endif 