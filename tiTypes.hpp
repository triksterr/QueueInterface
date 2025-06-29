#pragma once
#ifndef tiTypes_hpp
#define tiTypes_hpp

Константы и типы

#define IDTYPE long long Тип для индекса (ID Очереди) и т.п.
#define SIZETYPE long long Тип для размера очереди и индексов
может быть int, long, long long - в зависимости от необходимости
отрицательные значения - для диагностики ошибок

#define SSIZE 256 длина сегмента (128)
#define NSEG 256 количество сегментов - ????

#endif 
