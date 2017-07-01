#ifndef __ZBLIB_TEST__
#define __ZBLIB_TEST__

#include <stdio.h>
#include <stdlib.h>

#define assert(condition, msg) zassert(condition, msg, __LINE__, __FILE__)
#define finish() zfinish(0, __FILE__)

void fail(const char* msg, int line, char* file);
void zassert(int condition, char* msg, int line, char* file);
void zfinish(int e_code, char* file);

#endif