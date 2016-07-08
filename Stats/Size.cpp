#include "Size.h"



Size::Size() : size(0)
{
}

int Size::getSize() const { return size; }

void Size::operator() () { ++size; }


Size::~Size()
{
}
