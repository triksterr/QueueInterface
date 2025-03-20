
#include "tiQueueSet.hpp"

tiQueueSet *tiQueueSet::getInstance()
{
	static tiQueueSet instance;
	return &instance;
}


