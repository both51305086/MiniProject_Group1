#include"Header.h"
#include<ctype.h>
#include"Add.h"
#define NOW	2022
int clean_stdin();

int sizeName = 0;
unsigned short maxName = 0, maxHometown = 0, maxFaculty = 0;
unsigned short maxMajor = 0, maxModule = 0, maxTest = 0;
int nStudent = 0;

void add(student* pStudent, int* nStudent) {
	if (*nStudent == sizeof(pStudent)) pStudent = (student*)realloc(pStudent, 2 * (*nStudent));
	enterString(pStudent[*nStudent].fullName);
	if (maxName < sizeof(pStudent[*nStudent].fullName)) 
		maxName = sizeof(pStudent[*nStudent].fullName);
	strcpy(pStudent[*nStudent].name,getName(pStudent[*nStudent].fullName, strlen(pStudent[*nStudent].fullName) + 1, &sizeName));
	pStudent[*nStudent].birthDay.year = enterInt(Year,0,0);
	pStudent[*nStudent].birthDay.month = enterInt(Month,0,0);
	pStudent[*nStudent].birthDay.day = enterInt(Day, pStudent[*nStudent].birthDay.month, pStudent[*nStudent].birthDay.year);
	enterString(pStudent[*nStudent].hometown);
	if (maxHometown < sizeof(pStudent[*nStudent].hometown)) 
		maxHometown = sizeof(pStudent[*nStudent].hometown);
	enterString(pStudent[*nStudent].faculty);
	if (maxFaculty < sizeof(pStudent[*nStudent].faculty))
		maxFaculty = sizeof(pStudent[*nStudent].faculty);
	enterString(pStudent[*nStudent].major);
	if (maxMajor < sizeof(pStudent[*nStudent].major))
		maxMajor = sizeof(pStudent[*nStudent].major);
	pStudent[*nStudent].entryPoint = enterInt(EntryPoint, 0, 0);
	pStudent[*nStudent].numModules = enterInt(nModules, 0, 0);
	for (int i = 0; i < pStudent[*nStudent].numModules; i++) {
		enterString(pStudent[*nStudent].module[i].moduleName);
		pStudent[*nStudent].module[i].numTests = enterInt(nTests, 0, 0);
		for (int j = 0; j < pStudent[*nStudent].module[i].numTests; j++) {
			enterString(pStudent[*nStudent].module[i].listTest[j].testName);
			if (maxTest < sizeof(pStudent[*nStudent].module[i].listTest[j].testName))
				maxTest = sizeof(pStudent[*nStudent].module[i].listTest[j].testName);
			pStudent[*nStudent].module[i].listTest[j].weight = enterInt(Weight, 0, 0);
			pStudent[*nStudent].module[i].listTest[j].mark = enterInt(Mark, 0, 0);
			pStudent[*nStudent].module[i].gpa += pStudent[*nStudent].module[i].listTest[j].weight * pStudent[*nStudent].module[i].listTest[j].mark;
		}
	}
	(*nStudent)++;
}

int clean_stdin() {
	while (getchar() != '\n') {
	}
	return 1;
}

int enterInt(int NUM, int month, int year) {	
	int input;
	char c;

	while ((scanf("%d%c", &input, &c) != 2 || c != '\n') && clean_stdin()) {
		if (NUM == Year) {
			while ((input < (NOW - 50) || input >(NOW - 15))) {
				printf("enter Year error! Retype: \n");
				break;
			}
		}
		if (NUM == Month) {
			while (input < 1 || input > 12) {
				printf("enter Month error! Retype: \n");
				break;
			}
		}
		if (NUM == Day) {
			if (month == 2 &&(((year % 4 == 0) && (year % 100)) || (year % 400 == 0))) {
				while (input < 1 || input > 28) {
					printf("enter Day error! Retype: \n");
					break;
				}
			}
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				while (input < 1 || input > 31) {
					printf("enter Day error! Retype: \n");
					break;
				}
			}
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				while (input < 1 || input > 30) {
					printf("enter Day error! Retype: \n");
					break;
				}
			}
		}
		if (NUM == EntryPoint) {
			while (input < 0 || input > 1000) {
				printf("enter entryPoint error! Retype: \n");
				break;
			}
		}
		if (NUM == nModules) {
			while (input < 0 || input > MAX_MODULE) {
				printf("enter numModules error! Retype: \n");
				break;
			}
		}
		if (NUM == nTests) {
			while (input < 0 || input > MAX_TEST) {
				printf("enter numTests error! Retype: \n");
				break;
			}
		}
	}
	return input;
}

char* enterString(char* str) {
	char temp[MAX_CHAR];
	do {
		bool notAlpha = 0;
		fgets(temp, MAX_CHAR, stdin);
		if (temp[MAX_CHAR - 1] != '\0') continue;
		for (int i = 0; ; i++) {
			if (temp[i] == '\0') break;
			if (temp[i] == ' ') continue;
			if (isalpha(temp[i] == 0)) {
				notAlpha = 1;
				break;
			}
		}
		if (notAlpha == 0) break;
	} while (1);

	strcpy(str, temp);
	return str;
}

char* getName(char* fullName, int sizeFullName, int* psizeName) {
	static char name[MAX_NAME];
	int lastSpace = sizeFullName;
	while (1) {
		if (fullName[lastSpace] == ' ') break;
		lastSpace--;
	}
	*psizeName = sizeFullName - lastSpace;
	for (int i = 0; i < *psizeName; i++)
		name[i] = fullName[lastSpace + 1 + i];
	return name;
}