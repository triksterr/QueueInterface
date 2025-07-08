#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include "..\tiTypes.hpp"
#include "tiQueueBase.hpp"
#include "..\tiQueueSet\tiQueueSet.hpp"
#include <string>

#include <iostream> 
#include <typeinfo> 
#include "..\idbg.hpp"

struct tiQueueInfo
{	
	IDTYPE ID; 
	tiQueueBase *QueuePtr; 
	std::string description; 
	std::string type; 
	SIZETYPE size; 
	SIZETYPE dataSize; 
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
		dataSize(0),
		input(0),
		output(0),
		isEmptyF(true), 
		isFullF(false), 
		description(""),
		ID(tiQueueSet::getInstance()->add(this)),
		queue(new T[size])
	{
		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "Создана ID:", ID, this); 
	}
	
	~tiQueue()
	{
		tiQueueSet::getInstance()->del(ID); 
		IDTYPE id_temp = ID; 
		ID = -1;
		delete[] queue; 
		queue = nullptr;
		
		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "Уничтожена ID:", id_temp, this); 
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
	
	SIZETYPE getDataSize() const
	{
		return dataSize;
	}
	
	void setSize(SIZETYPE size)
	{

		this->size = size;

		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "Размер ID:", ID, this, "изменен на", size); 
	}
	
	void push(const T data) 
	{
		if(isFullF) 
		{
			
			idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "ID:", ID, this, "Данные", data, "не записаны"); 
			return; 
		}
		
		queue[input] = data; 
		dataSize++; 
		isEmptyF = false; 

		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "ID:", ID, this, "Данные", data, "записаны по индексу", input); 

		input = (input + 1) % size; 

		if(input == output) 
			isFullF = true; 

	}
	
	void pushOver(const T data)
	{
		if(!isFullF) 
		{
			push(data); 
			return; 
		}
		
		queue[input] = data; 
		
		input = (input + 1) % size; 
		output = (output + 1) % size; 
		
	}
	
	T pop() 
	{

		if(isEmptyF == true) 
		{
			
			return T{}; 
		}

		if(isEmptyF == false && input == output) 
			;

		T data = queue[output]; 

		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "ID:", ID, this, "Данные", queue[output], "сняты по индексу", output); 

		dataSize--; 

		output = (output + 1) % size; 
		isFullF = false; 

		if(output == input) 
			isEmptyF = true; 

		return data; 
	}
	
	T peek() const 
	{
		if(isEmptyF == true) 
		{
			
			return T {}; 
		}
		
		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "ID:", ID, this, "Данные", queue[output], "считаны по индексу", output); 
		
		return queue[output]; 
	}
	
	T read(const SIZETYPE index) const
	{
		if(isEmptyF == true) 
		{
			
			return T {}; 
		}
		
		idbg(__FILE__, "L:", __LINE__, __FUNCTION__, "ID:", ID, this, "Данные", queue[index], "считаны по индексу", index); 
		
		return queue[index]; 
	}
	
	void erase(SIZETYPE quantity)
	{
		
		for(SIZETYPE i = 0; i < quantity; i++)
			pop();
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
	
	static tiQueueBase *getPtr(const IDTYPE ID)
	{
		return tiQueueSet::getInstance()->get(ID);
	}

private:
	
	void print() const
	{
		if(!this)
			return;
		std::cout << "Привет, я Очередь ID: " << ID << ", ptr: " << this << ", size: " << size << ", type: " << typeid(T).name() << "\n";
	}
	
	void printData() const
	{
		std::cout << "Данные Очереди ID " << ID << " :";
		for(SIZETYPE i = 0; i < size; i++) 
			std::cout << " " << queue[i];

		std::cout << "\n";
	}

	T *queue = nullptr; 
	SIZETYPE size = 1; 
	SIZETYPE dataSize = 0; 
	SIZETYPE input = 0; 
	SIZETYPE output = 0; 
	bool isEmptyF = true; 
	
	bool isFullF = false; 
	IDTYPE ID = -1; 
	std::string description = ""; 
};

#endif 