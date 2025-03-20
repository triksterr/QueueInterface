#pragma once
#ifndef tiQueueSet_hpp
#define tiQueueSet_hpp

#pragma warning(push)

#include <iostream>
#include <__msvc_ostream.hpp>

#include "tiQueue.hpp"

class tiQueueSet final
{
public:
	static tiQueueSet *getInstance()
	{

		#if defined(_DEBUG) && !defined(NDEBUG)
			std::cout << "L: " << __LINE__ << " " << __FUNCTION__ << std::endl;
		#endif

		return &instance;
	}

	tiQueue *get(IDTYPE ID) const;

	bool isExist(IDTYPE ID) const;

	IDTYPE add(tiQueue *QueuePtr);

	int del(IDTYPE ID);

	bool isFull() const;

private:
	tiQueueSet();

	int newSeg();

	const IDTYPE SegSize = SSIZE;
	const IDTYPE NSegMAX = NSEG;
	const IDTYPE maxID = (SegSize * NSegMAX) - 1;
	IDTYPE Seg = 0;
	IDTYPE SegI = 0;
	IDTYPE ArrI = 0;
	tiQueue ***SegArr = nullptr;
};

#pragma warning(pop)

