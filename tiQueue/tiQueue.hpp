#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include "..\tiTypes.hpp"
#include "tiQueueBase.hpp"
#include "..\tiQueueSet\tiQueueSet.hpp"
#include <string>

#include <iostream> 
#include <typeinfo> 

struct tiQueueInfo
{	
	IDTYPE ID; 
	tiQueueBase *QueuePtr; 
	std::string description; 
	std::string type; 
	SIZETYPE size; 
	SIZETYPE input; 
	SIZETYPE output; 
	bool isEmpty; 
	bool isFull; 
};

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
		isFullF(false), 
		description("")
	{
		ID = tiQueueSet::getInstance()->add(this); 
		queue = new T[size]; 
		
		std::cout << "Очередь " << description << ", ID: " << ID << " создана!\n";
	}
	
	~tiQueue()
	{
		tiQueueSet::getInstance()->del(ID); 
		delete[] queue; 
		
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
	
	void setSize(SIZETYPE size)
	{

		this->size = size;
		
		std::cout << "Размер очереди " << description << " изменен на " << size << "\n";
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
		
		std::cout << "Данные " << queue[output] << " сняты из Очереди ID " << ID << ", index: " << output << "\n";

		if(isEmptyF == true)
			;

		if(isEmptyF == false && input == output) 
			;

		T data = queue[output]; 
		output = (output + 1) % size; 
		isFullF = false; 

		return data; 
	}
	
	T peek() const 
	{
		
		std::cout << "Данные " << queue[output] << " считаны из Очереди " << description << ", index: " << output << "\n";		
		
		return queue[output]; 
	}
	
	void setDescription(const std::string description = "") 
	{
		this->description = description;
	}
	
	std::string getDescription() const
	{
		return description;
	}
	
	std::string getType() const
	{
		return typeid(T).name();
	}
	
	static tiQueue *getPtr(const IDTYPE ID)
	{
		return tiQueueSet::getInstance()->get(ID);
	}

private:
	
	void print() const
	{
		if(!this)
			return;
		std::cout << "Привет, я Очередь ID: " << ID << ", size: " << size << ", type: " << typeid(T).name() << "\n";
	}
	
	void printData() const
	{
		std::cout << "Данные Очереди ID " << ID << " :";
		
		for(SIZETYPE i = 0; i < size; ++i) 
			std::cout << " " << queue[i];

		std::cout << "\n";
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