#include "mylib.h"

#include "mymath.h"
#include "modulea.h"

using namespace MyLib;

const char* MyLib::getVersion()
{
	return "0.0.1";
}

int MyLib::getMagic()
{
	return multiply_int(5, 5);
}

int MyLib::getTotalAccounts()
{
	return getModuleAValue();
}