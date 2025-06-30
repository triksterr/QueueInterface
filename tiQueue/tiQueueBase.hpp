#pragma once
#ifndef tiQueueBase_hpp
#define tiQueueBase_hpp

Виртуальный нешаблонный базовый класс для шаблонного класса Очереди (интерфейс)

#include "..\tiTypes.hpp"

Предварительное объявление шаблонного класса Obj

class tiQueueBase
{
public:
	
	virtual ~tiQueueBase() = default;
	virtual IDTYPE getID() const = 0;
private:
	
};
#endif 