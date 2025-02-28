#include "moduleb.h"

#include "modulec.h"

int getModuleBValue()
{
	return 16 + getModuleCValue();
}