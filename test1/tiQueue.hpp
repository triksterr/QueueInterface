#pragma once
#ifndef tiQueue_hpp
#define tiQueue_hpp

#include <string>

//#include "tiQueueSet.hpp"

using namespace std;

// Константы и типы
#define IDTYPE unsigned int // Тип для индекса, ID Очереди и т.п. - Только целые типы!
// (может быть long и т.п. - если нужно будет очень много Очередей) - перейти к шаблонам - ????

// Тестовый класс Очереди
//template <typename IDTYPE>
class tiQueue
{
public:
	// Конструктор по умолчанию
	tiQueue();
	// Конструктор с именем Очереди
	// @param name - имя Очереди
	tiQueue(const string &name);
	// Деструктор
	~tiQueue();
	// Получить ID Очереди
	IDTYPE getID() const;
    //! Получить указатель любой очереди по её ID
	tiQueue *getPtr(IDTYPE ID) const;
	// Вывод информации об Очереди
	void print() const;

private:
	string name = "";
	IDTYPE ID = 0;
};

#endif // - tiQueue_hpp