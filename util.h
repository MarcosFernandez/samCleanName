/*
 * util.h
 *
 *  Created on: 4 Ago, 2016
 *      Author: marcos
 */

#ifndef UTIL_H_
#define UTIL_H_

char ** splitter(const char * line,char * delim,unsigned int * numberElements);
void freeVector(char ** vector,unsigned int numberElements);
void freeString(char * string);
char *readStdin();
char* remove_all_chars(char* str, char c);


#endif /* UTIL_H_ */
