#include "diary_coder.h"

void encode(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		 str[i] = str[i] ^ 20;
	}
}

void decode(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = str[i] ^ 20;
	}
}

void xor_calculate(int *year, int *month, int *day, char *weather, char *title, char *contents)
{
	*year = *year ^ 20;
	*month = *month ^ 20;
	*day = *day ^ 20;

	encode(weather);
	encode(title);
	encode(contents);
}
