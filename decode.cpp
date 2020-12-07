#include <cmath>
#include "decode.h"
#include "decrypt.h"
#include "funcs.h"

//function decodes an encryted string using the frequency of each letter in the English alphabet

std::string decodeCaesar(std::string encryptedString) {
	std::string strings [26]; 
	double distance[26] = {0}; 
	double occurences[] = {	8.2, 1.5, 2.8, 4.3, 13,2.2, 2, 6.1, 7, 0.15,0.77, 4, 2.4, 6.7, 7.5,1.9, 0.095, 6, 6.3, 9.1,2.8, 0.98, 2.4, 0.15, 2,0.074}; 
	for (int i = 0; i < 26; i++) 
	{
		strings[i] = decryptCaesar(encryptedString, i);
		std::string& current = strings[i]; 
		int count[26] = {0}; 
		double letterFrequency[26]; 
		double distanceSquared[26]; 
		for (int i = 0; i < current.length(); i++) 
		{
			if (islower(current[i])) 
			{
				count[current[i] - 'a']++;
			}
			else if (isupper(current[i])) 
			{
				count[current[i] - 'A']++;
			}
		}
		for (int i = 0; i < 26; i++) 
		{
			letterFrequency[i] = (double)count[i] / current.length() * 100;
		}
		for (int i = 0; i < 26; i++)
		{
			distanceSquared[i] = pow(letterFrequency[i] - occurences[i], 2);
		}
		for (int distanceIter = 0; distanceIter < 26; distanceIter++)
		{
			distance[i] += distanceSquared[distanceIter];
		}
	}
	int	closestNum = 0; 
	for (int i = 1; i < 26; i++) 
	{
		if (distance[i] < distance[closestNum]) 
		{
			closestNum = i;
		}
	}
	return strings[closestNum];
}

