#include <iostream>
#include "funcs.h"

void test_ascii(std::string input)
{
	for(int i = 0; i < input.length(); i++)
	{
		std::cout << input[i] << " " << (int) input[i] << "\n";
	}
	std::cout << "\n";
}
