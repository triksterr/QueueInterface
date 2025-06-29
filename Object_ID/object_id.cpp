#include "object_id.hpp"
Базовый класс для генерации уникальных идентификаторов объектов для производных классов
Каждый объект содержит свой личный ID: unsigned long int от 0 до + 4 294 967 295

object_id::object_id(): oID(counter++) {}

object_id::~object_id() {}

unsigned long int object_id::getID() { return oID; }

unsigned long int object_id::counter = 0;
