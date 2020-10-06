#include <iostream>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
		if(keyword == "")
		{
			return plaintext;
		}
		int index = 0;
		std::string result;
		for(int i = 0; i < plaintext.length(); i++)
		{
			if((int(plaintext[i]) >= 65 && int(plaintext[i]) <= 90) || (int(plaintext[i]) >= 97 && int(plaintext[i]) <= 122))
			{
			if((int(keyword[index]) >= 65 && int(keyword[index]) <= 90))
			{
				result += shiftChar(plaintext[i], (((int) keyword[index]) - 65));
				index++;
				if(index == keyword.length())
				{
					index = 0;
				}
			}
			else if((int(keyword[index]) >= 97 && int(keyword[index]) <= 122))
			{
				result += shiftChar(plaintext[i], ((((int) keyword[index]) - 97)));
				index++;
				if(index == keyword.length())
				{
					index = 0;
				}
			}
			}
			else
			{
				result += plaintext[i];
			}
		}
		return result;
}