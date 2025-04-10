#ifndef UTILS
#define UTILS

#include <stdio.h>

void printerr(const char* text)
{
	printf("\033[31;1m"); //console red color
	printf(text);
	printf("\033[0m"); //console reset color
}

#endif /* UTILS */
