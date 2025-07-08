#include "object_id.hpp"

object_id::object_id(): oID(counter++) {}

object_id::~object_id() {}

unsigned long int object_id::getID() { return oID; }

unsigned long int object_id::counter = 0;
