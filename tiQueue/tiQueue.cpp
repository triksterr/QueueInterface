

#include <string>
#include "..\tiTypes.hpp"
#include "tiQueue.hpp"
#include "..\tiQueueSet\tiQueueSet.hpp"

#include <iostream> 

template <typename T>
tiQueue<T>::tiQueue(): tiQueue("No info") {}

template <typename T>
tiQueue<T>::tiQueue(const std::string &name): description(name)
{
	
	ID = tiQueueSet::getInstance()->add(this);

	std::cout << "Очередь " << name << ", ID: " << ID << " создана!\n";
}

template <typename T>
tiQueue<T>::~tiQueue()
{
	
	std::cout << "Очередь " << description << ", ID: " << ID << " уничтожена!\n";
}

template <typename T>
IDTYPE tiQueue<T>::getID() const
{
	return ID;
}

template <typename T>
void tiQueue<T>::print() const
{
	if(!this)
		return;
	std::cout << "Привет, я Очередь " << description << ", ID: " << ID << "\n";
}
