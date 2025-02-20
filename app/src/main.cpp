#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "mylib.h"
#include "tools.h"

#include "myheaderlib.h"

void printCar(const CarModel& carmodel)
{
	std::cout << "Car Model" << std::endl;
	std::cout << "=========" << std::endl;
	std::cout << "Make: " << carmodel.make << std::endl;
	std::cout << "Model: " << carmodel.model << std::endl;
	std::cout << "Year: " << carmodel.year << std::endl;
}

int main(int argc, char* argv[])
{
	bool quit = false;
 	std::cout << "This is a test app." << std::endl;
	std::cout << "mylib version:" << MyLib::getVersion() << std::endl;
	
	CarModel carmodel;
	
	while(!quit)
	{
		std::vector<std::string> words;
		std::string buf;
		std::cout << ">";
		
		std::getline(std::cin, buf);

		words = split(buf, ' ', false);

		if (words.empty())
		{
			continue;
		}

		if (words[0] == "quit")
		{
			quit = true;
		}
		else if(words[0] == "car")
		{
			printCar(carmodel);
		}

	}
	
	return 0;
}
