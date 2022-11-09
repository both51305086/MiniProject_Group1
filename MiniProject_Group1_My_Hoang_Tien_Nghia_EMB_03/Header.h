#ifndef __HEADER_H
#define __HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 10
#define MAX_CHAR 50
#define MAX_STUDENT 100
#define MAX_TEST 10
#define MAX_MODULE 5
#define MAX_CHAR_IN_LINE 250
extern char pathFile[];
extern int nStudent;

typedef struct {
	unsigned char day;
	unsigned char month;
	unsigned short year;
}dateOfBirth;

typedef struct {
	char testName[MAX_CHAR];
	unsigned short weight;
	unsigned short mark;
}typeTest;

typedef struct {
	char moduleName[MAX_CHAR];
	typeTest listTest[MAX_TEST];
	unsigned short gpa;
	unsigned char numTests;
}module;

typedef struct {
	char fullName[MAX_CHAR];
	char name[MAX_NAME];
	dateOfBirth birthDay;
	char hometown[MAX_CHAR];
	char faculty[MAX_CHAR];
	char major[MAX_CHAR];
	unsigned short entryPoint;
	unsigned char numModules;
	module module[MAX_MODULE];
}student;

#endif
