#include <iostream>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
		if(keyword == "") // if the kwyord is empty we return the plaintext because we do not have to shift it at all 
		{
			return plaintext;
		}
		int index = 0; // this is the index of the jkeyword and it will be getting updated accordingly 
		std::string result;
		for(int i = 0; i < plaintext.length(); i++)
		{
			if((int(plaintext[i]) >= 65 && int(plaintext[i]) <= 90) || (int(plaintext[i]) >= 97 && int(plaintext[i]) <= 122)) // if the plaintext character is a letter we continue to shift 
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
			else // if the character is not a letter we just add that character to result
			{
				result += plaintext[i];
			}
		}
		return result;
}