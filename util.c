/*
 * util.c
 *
 *  Created on: 4 Ago, 2016
 *      Author: marcos
 */
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * \brief Split a string according to a given delimit character http://stackoverflow.com/questions/11198604/c-split-string-into-an-array-of-strings
 * \param line Line to be splitted
 * \param delim Character Delimitator
 * \param numberElements Number of elements per reference
 * \returns array of strings
 */
char ** splitter(const char * line,char * delim,unsigned int * numberElements)
{
	/*1.Define vector to return*/
	char ** fields  = NULL;

	*numberElements = 0;

	/*2. Char tokenize */
    char * token = strtok(line, delim);

	/*2.1 Split line and append tokens to fields */
	while (token)
	{
		*numberElements = *numberElements + 1;
		fields = realloc (fields, sizeof (char*) * *numberElements);

		if (fields == NULL)
		{
			exit (-1); /* memory allocation failed */
		}


		fields[*numberElements-1] = malloc(strlen(token) + 1);
		strcpy(fields[*numberElements-1], token);

		/*fields[nDelimitator-1] = token;*/

		token = strtok(NULL, delim);
	}

	/*2.2 realloc one extra element for the last NULL */
	fields = realloc (fields, sizeof (char*) * (*numberElements+1));
	fields[*numberElements] = '\0';

	return fields;
}


/**
 * \brief Frees memory allocated to a given string vector
 * \param vector vector of strings
 * \param numberElements Number of Elements
 */
void freeVector(char ** vector,unsigned int numberElements)
{
	unsigned int i;

	for(i = 0; i < numberElements; i++)
	{
		freeString(vector[i]);
	}

	if (vector != NULL)
	{
		free(vector);
		vector = NULL;
	}
}

/**
 * \brief Frees memory allocated to a given string
 * \param char * string
 */
void freeString(char * string)
{
	if (string != NULL)
	{
		free(string);
		string = NULL;
	}
}

/**
 * \brief Remove all occurrences of a given char
 * \param char str String to treat
 * \param c characters to remove
 * \return char free of c chars  http://www.c4learn.com/c-programs/c-program-to-delete-all-occurrences-of-character-from-the-string.html
 */
char* remove_all_chars(char* str, char c)
{
	/*int i, j = 0;
	int size;
	char ch1;
	char * newStr;

	size = strlen(str);
	char str1[size +1];

	for (i = 0; i < size; i++) {
	  if (str[i] != c) {
	     ch1 = str[i];
	     str1[j] = ch1;
	     j++;
	  }
	}
	str1[j] = '\0';

	newStr = malloc((sizeof(char*)*j)+1);
	strcpy(newStr,str1);
	return newStr;*/

	unsigned int i,j = 0;
	unsigned int size = strlen(str);
	char * newStr = malloc ((sizeof(char*)*size) + 1);

	for (i = 0; i < size; i++)
	{
		if (str[i] != c)
		{
			newStr[j] = str[i];
		    j++;
		}
	}
	newStr[j] = '\0';

	return newStr;
}

/**
 * \brief Read from Standard Input  http://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
 * \return Line read
 */
char *readStdin()
{
    //The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t size = 10;
    size_t len = 0;

    str = realloc(NULL, sizeof(char)*size);//size is start size

    if(!str)
    {
    	return str;
    }

    while(EOF!=(ch=fgetc(stdin)) && ch != '\n')
    {
    	str[len++] = ch;
        if(len==size)
        {
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
