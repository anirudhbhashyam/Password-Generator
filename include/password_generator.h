#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_LETTERS 26 + 26
#define N_DIGITS 10
#define N_SYMBOLS 28

char MASTER_CHARACTERS[N_LETTERS + N_DIGITS + N_SYMBOLS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '[', ']', '{', '}', '|', ';', '\'', ':', ',', '.', '/', '<', '>', '?'};

void shuffle(char* character_array, const size_t length)
{
	int i, j;
	for (i = length - 1; i >= 0; i--)
	{
		j = rand() % (i + 1);
		// Perform the swap.
		char temp = character_array[i];
		character_array[i] = character_array[j];
		character_array[j] = temp;
	}
}

char* generate_password(const size_t length)
{
	int i;
	// Account for the null terminating character.
	char* password = (char*) malloc(sizeof(char) * (length + 1));
	for (i = 0; i < length + 1; i++)
	{
		// Shuffle the character array.
		shuffle(MASTER_CHARACTERS, (N_LETTERS + N_DIGITS + N_SYMBOLS));
		*(password + i) = MASTER_CHARACTERS[rand() % (N_LETTERS + N_DIGITS + N_SYMBOLS)];
	}
	return password;
}



