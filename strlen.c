//------------------------------------------------------------------------
// NAME: Stefan Angelov
// CLASS: XIa
// NUMBER: 24
// PROBLEM: #1
// FILE NAME: strlen.c (unix file name)
// FILE PURPOSE:
// Returns the length of a string
// 
// 
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int strlen(char*);

int main()
{
	char *k;
	k = malloc(sizeof(char)*10);
	fgets(k,10,stdin);
	printf("%d\n",strlen(k));
	free(k);
	return 0;
}

int strlen(char* string)
{
	//------------------------------------------------------------------------
	// FUNCTION: strlen (име на функцията)
	// returns length of a string
	// PARAMETERS: char* string => that is the string
	//------------------------------------------------------------------------

	int i=0;
	char zero = '\0';
	while(*(string+i)!=zero)
	{
		i++;
	}
	return i;
}
