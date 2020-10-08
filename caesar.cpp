#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift)
{
		if (int(c) > 64 && int(c) < 91) //if rshift is positive we check if it is within the range of 65 to 90 which would mean it is a Capital letter
		{
			int num = (int(c) - 65 + rshift) % 26 + 65; //if rshift makes the character go over 90 we need to loop it around the alphabet so that we stay with letters
			if (num < 65)
			{	
			  return char(26 + num);
			}
			return char(num);
		}
	  if (int(c) > 96 && int(c) < 123) //if rshift is between 97 and 122 it means that it is a lowercase letter 
	  {
		int num = (int(c) - 96 + rshift) % 26 + 96; //if rshift makes the character go over 122 we need to loop it around the alphabet so that we stay with letters
		if (num < 97)
		{
		  return char(26 + num);
		}
		return char(num);
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

