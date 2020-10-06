#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift)
{
	if(rshift > 25)
	{
		rshift = (rshift % 25) - 1;
	}
	else if(rshift < -25)
	{
		rshift = (rshift % -25) + 1;
	}
	if(rshift < 0)
	{
		if((((int) c) >= 65 && ((int) c <= 90)))
	{
			if((int) c + rshift < 65)
			{
				int num = rshift + ((int) c - 65);
				return char (90 + num + 1);
			}
			return char ((int) c + rshift);
	}
	else if((((int) c) >= 97 && ((int) c <= 122)))
	{
		if((int) c + rshift < 97)
			{
				int num = rshift + ((int) c - 97);
				return char (122 + num + 1);
			}
			return char ((int) c + rshift);
	}
	}
	if((((int) c) >= 65 && ((int) c <= 90)))
	{
			if((int) c + rshift > 90)
			{
				int num = rshift - (90 - (int) c);
				return char (65 + num - 1);
			}
			return char ((int) c + rshift);
	}
	else if((((int) c) >= 97 && ((int) c <= 122)))
	{
		if((int) c + rshift > 122)
			{
				int num = rshift - (122 - (int) c);
				return char (97 + num - 1);
			}
			return char ((int) c + rshift);
	}
		return c;
}

std::string encryptCaesar(std::string plaintext, int rshift)
{
	if(rshift == 0)
	{
		return plaintext;
	}
	std::string result;
	for(int i = 0; i < plaintext.length(); i++)
	{
		result = result + shiftChar(char(plaintext[i]), rshift);
	}
	return result;
}

