#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "mylib.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	bool quit = false;
 	std::cout << "This is a test app." << std::endl;
	std::cout << "mylib version:" << MyLib::getVersion() << std::endl;
	
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

	}
	
	return 0;
}
