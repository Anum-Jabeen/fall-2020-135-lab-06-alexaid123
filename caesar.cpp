#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift)
{
	if(rshift > 25)
	{
		rshift = (rshift % 25) - 1; // if rshift is more than the letters of the alphabet alphabet then we only need to take into account the remaining shifts after rshift % 25 - 1
	}
	else if(rshift < -25)
	{
		rshift = (rshift % -25) + 1; // // if rshift is negative and more than the letters of the alphabet then we only need to take into account the remaining shifts after rshift % 25 - 1
	}
	if(rshift < 0) // if rshift is negative we have to check if it goes under the limit of 65 to make sure we loop around the alphabet 
	{
		if((((int) c) >= 65 && ((int) c <= 90))) // If the integer number of the character c is in this range that means it is a capital letter and we need to shift it
	{
			if((int) c + rshift < 65) // If the shift results in the character not being a letter anymore we need to make it loop around the alphabet
			{
				int num = rshift + ((int) c - 65);
				return char (90 + num + 1);
			}
			return char ((int) c + rshift);
	}
	else if((((int) c) >= 97 && ((int) c <= 122))) // If the integer number of the character c is in this range that means it is a lower case letter and we need to shift it
	{
		if((int) c + rshift < 97) // if the shifted character goes over 97 that means it is not a letter anymore and we need to loop it around the alphabet
			{
				int num = rshift + ((int) c - 97);
				return char (122 + num + 1);
			}
			return char ((int) c + rshift);
	}
	}
	if((((int) c) >= 65 && ((int) c <= 90))) // if rshift is positive we check if it is within the range of 65 to 90 which would mean it is a Capital letter 
	{
			if((int) c + rshift > 90) // if rshift makes the character go over 90 we need to loop it around the alphabet so that we stay with letters  
			{
				int num = rshift - (90 - (int) c);
				return char (65 + num - 1);
			}
			return char ((int) c + rshift);
	}
	else if((((int) c) >= 97 && ((int) c <= 122))) // if rshift is between 97 and 122 it means that it is a lowercase letter 
	{
		if((int) c + rshift > 122) // if rshift makes the character go over 122 we need to loop it around the alphabet so that we stay with letters
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

