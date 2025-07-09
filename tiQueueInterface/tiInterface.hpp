#pragma once
#ifndef tiInterface_hpp
#define tiInterface_hpp

class tiQueue
{
public:
	
	virtual void push(int value) = 0;
	
	virtual int pop() = 0;
	
	virtual int size() = 0;
	
	virtual bool isEmpty() = 0;
	
	virtual bool isFull() = 0;
	
	virtual ~tiQueue() {} 
};

#endif 