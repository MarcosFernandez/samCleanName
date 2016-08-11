/*
 * main.c
 *
 *  Created on: 3 Ago, 2016
 *      Author: marcos
 */
#include "util.h"
#include <string.h>
#include <stdio.h>


/**
 * \brief main function
 * \brief Reads sam files and cleans from read name @ character
 */
int main(int argc, char *argv[])
{
	char *samLine; /*Sam Line*/
    unsigned int i = 0;

	samLine = readStdin();

	/*1. Read Sam File from Standard Input and process its header repairing*/
	while (strcmp(samLine, "") != 0)
	{
        /*1.1 Get fields*/
		unsigned int n_elements = 0;
		char ** fields = splitter(samLine,"\t",&n_elements);
		char * newHeader;

		if (fields[0][0] != '@')
		{
			//remove all char modify new header per reference
			newHeader = remove_all_chars(fields[0], '@');
		}
		else
		{
			newHeader = malloc(sizeof(fields[0]) + 1);
			strcpy(newHeader,fields[0]);
		}


		/*1.2 Print Clean file to Standard output */
		for(i=0; i < n_elements; i++)
		{
			if (fields[i] == NULL) break;

			if (i == 0) fputs(newHeader,stdout);
			else fputs(fields[i],stdout);

			if(i != n_elements-1 ) fputs("\t",stdout);
			if(i == n_elements-1) fputs("\n",stdout);
		}

		/*1.5 Free pointers*/
		freeVector(fields,n_elements);
		freeString(newHeader);
		freeString(samLine);

		samLine = readStdin();
	}

	/*2 Free samline pointers*/
	freeString(samLine);

	return 0;
}
