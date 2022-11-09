#include"Header.h"
#include"Search.h"
#include"Add.h"
#include"Sort.h"

int nFind = 0;
int position = 0;

student* searchName(student* pStudent, int nStudent, int* pFind, int* pPosition)
{
	static student arrStudent[MAX_ARR] ={};
	char tempStr[MAX_NAME];
	enterString(tempStr);
	for (int i = 0, j = 0; i < nStudent && j < MAX_ARR; i++) {
		if (strcmp(_strupr(tempStr), _strupr(pStudent[i].name)) == 0) {
			arrStudent[j] = pStudent[i];
			*pPosition = i;
			j++;
			(*pFind)++;
		}
	}
	if (*pFind == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", tempStr);
		return NULL;
	}
	return arrStudent;
}

student* searchYear(student* pStudent, int nStudent, int* pFind, int* pPosition) {
	unsigned short temp = enterInt(Year, 0, 0);
	static student arrStudent[MAX_ARR] = {};
	for (int i = 0, j = 0; i < nStudent && j < MAX_ARR; i++) {
		if (pStudent[i].birthDay.year == temp) {
			arrStudent[j] = pStudent[i];
			*pPosition = i;
			j++;
			(*pFind)++;
		}
	}
	if (*pFind == 0) {
		printf("Khong co sinh vien sinh nam %d trong danh sach!\n",temp);
		return NULL;
	}
	return arrStudent;
}

void searchMinGPA(student* pStudent, int nStudent) {
	student *arrStudent = sortGPA(pStudent, nStudent, nFind);
	printf("Max GPA: %.2f\n", (float)arrStudent[0].module[0].gpa * 1.0f / 10000);
	
}

void searchMaxGPA(student* pStudent, int nStudent, int nFind) {
	student* arrStudent = sortGPA(pStudent, nStudent, nFind);
	printf("Max GPA: %.2f\n", (float)arrStudent[nFind - 1].module[0].gpa*1.0f/10000);
}

student* searchModule(student* pStudent, int nStudent, int* nFind) {
	static student arrStudent[MAX_STUDENT] = {};
	char tempStr[MAX_CHAR];
	enterString(tempStr);
	for (int i = 0, j = 0; i < nStudent && j < MAX_STUDENT; i++) {
		for (int k = 0; k < pStudent[i].numModules; k++) {
			if (strcmp(_strupr(tempStr), _strupr(pStudent[i].module[k].moduleName)) == 0) {
				arrStudent[j] = pStudent[i];
				arrStudent[j].numModules = 1;
				memcpy(arrStudent[j].module,pStudent[i].module+k,sizeof(module));
				(*nFind)++;
				j++;
			}
		}
	}
	if (*nFind == 0) {
		printf("Khong co sinh vien trong mon hoc %s!\n", tempStr);
		return NULL;
	}
	return arrStudent;
}

