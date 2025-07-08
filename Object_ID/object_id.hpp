#pragma once

class object_id
{
public:
	object_id();
	~object_id();
	
	unsigned long int getID();
private:
	
	const unsigned long int oID;
	
	static unsigned long int counter;
};

