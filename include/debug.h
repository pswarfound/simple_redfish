#ifndef __DBG_H__
#define __DBG_H__
#include <stdio.h>


#define DBG(fmt, ...) printf("%s %d: "fmt"\n", __func__, __LINE__, ##__VA_ARGS__);printf("\n");

#endif