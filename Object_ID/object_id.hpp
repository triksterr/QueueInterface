#pragma once
Базовый класс для генерации уникальных идентификаторов объектов для производных классов. 
Каждый объект содержит свой личный ID: unsigned long int от 0 до + 4 294 967 295

class object_id
{
public:
	object_id();
	~object_id();
	Получение уникального идентификатора данного объекта
	unsigned long int getID();
private:
	Уникальный идентификатор объекта производного класса
	const unsigned long int oID;
	Счетчик для генерации идентификаторов
	static unsigned long int counter;
};

