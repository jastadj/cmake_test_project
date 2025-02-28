#include "modulea.h"

#include "account.h"

#include "moduleb.h"

int getModuleAValue()
{
	return getTotalAccounts() * getModuleBValue();
}

int getCounter()
{
	static int counter = 0;
	
	return counter++;
}