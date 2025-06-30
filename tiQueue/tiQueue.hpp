#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include "..\tiTypes.hpp"
#include "tiQueueBase.hpp"
#include "..\tiQueueSet\tiQueueSet.hpp"
#include <string>

#include <iostream> 
#include <typeinfo> 

template <typename T>
class tiQueue : public tiQueueBase
{
	friend int main(); 
	
public:
	
	tiQueue(): tiQueue(1) {}
	
	tiQueue(const SIZETYPE size):
		size(size),
		input(0),
		output(0),
		isEmptyF(true), 
		description("")
	{
		ID = tiQueueSet::getInstance()->add(this);
		queue = new T[size]; 
		
		std::cout << "Очередь " << description << ", ID: " << ID << " создана!\n";
	}
	
	~tiQueue()
	{
		delete[] queue; 
		tiQueueSet::getInstance()->del(ID); 
		
		std::cout << "Очередь " << description << ", ID: " << ID << " уничтожена!\n";
	}
	
	IDTYPE getID() const
	{
		return ID;
	}
	
	bool isEmpty() const
	{
		return isEmptyF;
	}
	
	bool isFull() const
	{
		return isFullF;
	}
	
	SIZETYPE getSize() const
	{
		return size;
	}
	
	void push(const T data) 
	{
		queue[input] = data; 
		isEmptyF = false; 
		
		std::cout << "Данные " << data << " записаны в Очередь " << description << ", index: " << input << "\n";

		input = (input + 1) % size; 
		
	}
	
	T pop() 
	{
		
		std::cout << "Данные " << queue[output] << " сняты из Очереди " << description << ", index: " << output << "\n";

		T data = queue[output]; 
		output = (output + 1) % size; 
		isFullF = false; 

		return data; 
	}
	
	T peek() const 
	{
		return queue[output]; 
		
		std::cout << "Данные " << queue[output] << " считаны из Очереди " << description << ", index: " << output << "\n";
	}
	
	void setDescription(const std::string description = "") 
	{
		this->description = description;
	}
	
	tiQueue *getPtr(const IDTYPE ID) const
	{
		return tiQueueSet::getInstance()->get(ID);
	}

private:
	
	void print() const
	{
		if(!this)
			return;
		std::cout << "Привет, я Очередь " << description << ", ID: " << ID << ", size: " << size << ", type: " << typeid(T).name() << "\n";
	}

	T *queue = nullptr; 
	SIZETYPE size = 1; 
	SIZETYPE input = 0; 
	SIZETYPE output = 0; 
	bool isEmptyF = true; 
	
	bool isFullF = false; 
	IDTYPE ID = -1; 
	std::string description = ""; 
};

#endif 