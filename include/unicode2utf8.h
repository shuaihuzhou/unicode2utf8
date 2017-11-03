#ifndef _unicode2utf8_h
#define _unicode2utf8_h

#include "varray.h"
#include<string>

#ifdef __cplusplus
extern "C"{
#endif

std::string unicode2utf8(const char* str);

#ifdef __cplusplus
}
#endif

#endif
