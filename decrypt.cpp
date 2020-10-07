#include <iostream>
#include "decrypt.h"
#include "caesar.h"

std::string decryptCaesar(std::string ciphertext, int rshift)
{
	return encryptCaesar(ciphertext, (rshift * -1)); // calling encrypt caesar with hthe negative value of rshift to decrypt the ciphertext
}

std::string decryptVigenere(std::string ciphertext,std::string keyword)
{
	if(keyword == "")
		{
			return ciphertext;
		}
		int index = 0;
		std::string result;
		for(int i = 0; i < ciphertext.length(); i++)
		{
			if((int(ciphertext[i]) >= 65 && int(ciphertext[i]) <= 90) || (int(ciphertext[i]) >= 97 && int(ciphertext[i]) <= 122))
			{
			if((int(keyword[index]) >= 65 && int(keyword[index]) <= 90))
			{
				result += shiftChar(ciphertext[i], (((int) keyword[index]) - 65) * -1);
				index++;
				if(index == keyword.length())
				{
					index = 0;
				}
			}
			else if((int(keyword[index]) >= 97 && int(keyword[index]) <= 122))
			{
				result += shiftChar(ciphertext[i], ((((int) keyword[index]) - 97) * -1));
				index++;
				if(index == keyword.length())
				{
					index = 0;
				}
			}
			}
			else
			{
				result += ciphertext[i];
			}
		}
		return result;
}