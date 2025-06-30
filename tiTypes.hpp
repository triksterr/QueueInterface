#pragma once
#ifndef tiTypes_hpp
#define tiTypes_hpp

Константы и типы

#define IDTYPE long long Тип для индекса (ID Очереди) и т.п.
#define SIZETYPE long long Тип для размера очереди и индексов
может быть int, long, long long - в зависимости от необходимости
отрицательные значения - для диагностики ошибок

#define SSIZE 128 длина сегмента (256/128)
#define NSEG 256 количество сегментов - ????

#endif 
