#pragma once
#include"Header.h"
#include"Search.h"
#ifndef __ADD_H
#define __ADD_H
void add(student*, int*);
extern char* getName(char*, int, int*);
extern int enterInt(int NUM, int, int);
extern char* enterString(char*); 
extern enum NUM { Day, Month, Year, EntryPoint, Weight, Mark, nModules, nTests };
extern int sizeName;
extern unsigned short maxName, maxHometown, maxFaculty;
extern unsigned short maxMajor, maxModule, maxTest;
#endif
