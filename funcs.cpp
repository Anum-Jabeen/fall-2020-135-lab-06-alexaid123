#include <iostream>
#include "funcs.h"

void test_ascii(std::string input)
{
	for(int i = 0; i < input.length(); i++)
	{
		std::cout << input[i] << " " << (int) input[i] << "\n"; // Prints out the integer value of the character at each index of the word
	}
	std::cout << "\n";
}
