#pragma once
#ifndef tiQueueBase_hpp
#define tiQueueBase_hpp

#include "..\tiTypes.hpp"

class tiQueueBase
{
public:
	
	virtual ~tiQueueBase() = default;
	virtual IDTYPE getID() const = 0;
private:
	
};
#endif 