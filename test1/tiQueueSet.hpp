#pragma once
#ifndef tiQueueSet_hpp
#define tiQueueSet_hpp

// File: tiQueueSet.hpp
// 
// Created: 10.03.2025
// 
// Updated: 11.03.2025 07:02
// 
// Description: Заголовок для класса Хранилища массива Очередей
// File is part of the "TechInterface" project
// 
// 2025, TechInterface

#pragma warning(push)
#pragma warning(disable : 4996) // выключение предупреждений о макросе тестового вывода в режиме отладки

#include <iostream>
#include <__msvc_ostream.hpp>

//#include "tiInterface.hpp"

#include "tiQueue.hpp"

//! Класс служебный - пользователь к нему доступа не имеет

#define IDTYPE unsigned int // Тип для индекса (ID Очереди) и т.п. (может быть long и т.п. - если нужно будет очень много Очередей)
#define SSIZE 2 // длина сегмента
#define NSEG 256 // max количество сегментов

// Класс - Массив для хранения указателей на Очереди - синглтон
//template <typename IDTYPE>
class tiQueueSet final
{
public:
	// Синглтон-конструктор - Статический метод для получения указателя на объект-Массив
	// @return указатель на объект-Массив
	static tiQueueSet *getInstance()
	{
		//! По идее, каждый раз надо вызывать в конструкторе Очереди

		//! тестовый вывод в режиме отладки
		#if defined(_DEBUG) && !defined(NDEBUG)
			std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
		#endif

		// Динамика, не потокобезопасная
		// static tiQueueSet *instance = nullptr;
		//if(!instance)
		//{
		//	instance = new tiQueueSet();
		//}
		//return instance;

		static tiQueueSet instance; // Синглтон Мейера с ленивой инициализацией (потокобезопасен)

		return &instance;
	}

	// Получить указатель на Очередь по ID - ШТАТНАЯ пользовательская функция (при наличии прав доступа)
	// @param ID - ID Очереди
	// @return указатель на Очередь
	tiQueue *get(IDTYPE ID) const;

	// Проверить наличия живой(!= nullptr) Очереди в Массиве по ID  - ???ШТАТНАЯ пользовательская функция (при наличии прав доступа)
	// @param ID - ID Очереди
	// @return true - если Очередь живая, false - если нет
	bool isExist(IDTYPE ID) const;

	// Добавить Очередь в Массив - ШТАТНАЯ (для очереди - из конструктора - при наличии прав доступа)
	// @param QueuePtr - указатель на Очередь
	// @return ID - ID добавляемой Очереди
	IDTYPE add(tiQueue *QueuePtr);

	// Удалить Очередь из Массива - ШТАТНАЯ (для очереди - из деструктора - при наличии прав доступа)
	// @param ID - ID Очереди
	//! @return 0 - успешно, -1 - ошибка - ????
	int del(IDTYPE ID);

	// Проверить переполнение Массива Очередей
	// @return true - количество Очередей = допустимому (NSegMAX * SegSize), false - количество Очередей < допустимого
	bool isFull() const;

	// Оператор [] -  для чтения

private:
	// Конструктор скрыт
	tiQueueSet();
	tiQueueSet(const tiQueueSet &) = delete; // Запрещаем копирование
	tiQueueSet(tiQueueSet &&) = delete; // Запрещаем перенос
	~tiQueueSet() = default; // Деструктор скрыт - Массив не удаляется никогда
	tiQueueSet &operator=(const tiQueueSet &) = delete; // Запрещаем присваивание копированием
	tiQueueSet &operator=(tiQueueSet &&) = delete; // Запрещаем присваивание переносом

	//! Выделяем память для нового сегмента
	// @return 0 - успешно, -1 - ошибка
	int newSeg();

	// Динамика, не потокобезопасная
	//static tiQueueSet *instance; // указатель на себя

	// Длина сегмента
	const IDTYPE SegSize = SSIZE;
	// max количество сегментов
	const IDTYPE NSegMAX = NSEG;
	// Максимально возможный ID
	const IDTYPE maxID = (SegSize * NSegMAX) - 1;
	// Текущий сегмент (куда идет добваление Объектов)
	IDTYPE Seg = 0;
	// Текущий индекс в последнем сегменте, указывает на еще не заполненный элемент
	IDTYPE SegI = 0;
	// Текущий индекс в массиве, указывает на еще не заполненный элемент (Текущий ID = ArrI-1)
	IDTYPE ArrI = 0;
	// Массив указателей на Очереди (на сегменты Массива указателей на Очереди)
	tiQueue ***SegArr = nullptr;
};
// Динамика - не потокобезопасная
//tiQueueSet *tiQueueSet::instance = nullptr; // инициализация указателя

////___________________________________________________________________________________




	//! Записать указатель на Очередь по её индексу (ID)
	// @param ID - ID Очереди
	// @param QueuePtr - указатель на Очередь
	//! @return 0 - успешно, -1 - ошибка - ????
	// int set(IDTYPE ID, tiQueue *QueuePtr);
	//! при такой записи надо проверять, есть ли права на такую запись (это - служебная операция!)
	//! есть ли на этом месте данные
	// Проверка выхода за границы Массива!
	// Что если QueuePtr = nullptr???

	// Оператор [] - для записи присваиванием

//? Альтернатива - односвязный список сегментов или deque, но он медленнее и объемнее
// или можно использовть связный список на третьем - самом верхнем уровне, когда необходимо расширение еще больше
// Тогда ID будет уже не int a long

////_________________________________________________________________________
#pragma warning(pop)

#endif // - tiQueueSet_hpp