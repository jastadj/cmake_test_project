#include "mylib.h"

#include "mymath.h"

using namespace MyLib;

const char* MyLib::getVersion()
{
	return "0.0.1";
}

int MyLib::getMagic()
{
	return multiply_int(5, 5);
}
