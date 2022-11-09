#pragma once
#include"Header.h"
#ifndef __SEARCH_H
#define __SEARCH_H
#define MAX_ARR 10
extern int nFind;
extern int position;
student* searchName(student*, int, int*,int*);
student* searchYear(student*, int,int*,int*);
void searchMinGPA(student*, int);
void searchMaxGPA(student*, int, int);
student* searchModule(student*, int, int*);
#endif
