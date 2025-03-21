

#include <string>
#include "tiQueue.hpp"
#include "tiQueueSet.hpp"

#include <iostream>

tiQueue::tiQueue(): tiQueue("Noname") {}

tiQueue::tiQueue(const std::string &name): name(name)
{
	
	ID = tiQueueSet::getInstance()->add(this);

	std::cout << "Очередь " << name << ", ID: " << ID << " создана!\n";
}

tiQueue::~tiQueue()
{
	
	std::cout << "Очередь " << name << ", ID: " << ID << " уничтожена!\n";
}

IDTYPE tiQueue::getID() const
{
	return ID;
}

tiQueue *tiQueue::getPtr(IDTYPE id) const
{
	return tiQueueSet::getInstance()->get(id);
}

void tiQueue::print() const
{
	if(!this)
		return;
	std::cout << "Привет, я Очередь " << name << ", ID: " << ID << "\n";
}
