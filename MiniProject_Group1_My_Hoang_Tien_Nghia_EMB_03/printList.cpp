#include"Header.h"
#include"Add.h"
#include"PrintList.h"
void printList(student* pStudent, int iStudent) {
	student* arrStudent = searchModule(pStudent, nStudent, &nFind);
	printCrossBar(arrStudent);
	
	//print Header table
	printf("|");
	printf("%-maxModules", arrStudent[0].module[0].moduleName);
	printf("|");
	printf("%-maxNames", "NAME");
	printf("|");
	printf(" BIRTHDAY ");
	printf("|");
	printf("%-maxHometowns", "HOMETOWN");
	printf("|");
	printf("%-maxFacultys", "FACULTY");
	printf("|");
	printf("%-maxMajors", "MAJOR");

	for (int i = 0; i < arrStudent[0].module[0].numTests; i++)
	{
		printf("|");
		printf("%(sizeof(arrStudent[0].module[0].listTest[i].testName)+4)s(%4.2f)", arrStudent[0].module[0].listTest[i].testName,(float) arrStudent[0].module[0].listTest[i].weight*1.0f/100);
	}
	printf("| GPA |\n");

	printCrossBar(arrStudent);
	for (int i = 0; i < nFind; i++) {
		printf("|");
		printf("%-maxModules", arrStudent[0].module[0].moduleName);
		printf("|");
		printf("%-maxNames", arrStudent[i].fullName);
		printf("|");
		printf(" BIRTHDAY ");
		printf("|");
		printf("%-2d/%-2d%-4d", arrStudent[i].birthDay.day, arrStudent[i].birthDay.month, arrStudent[i].birthDay.year);
		printf("%-maxHometowns", arrStudent[i].hometown);
		printf("|");
		printf("%-maxFacultys", arrStudent[i].faculty);
		printf("|");
		printf("%-maxMajors", arrStudent[i].major);

		for (int j = 0; j < arrStudent[0].module[0].numTests; j++)
		{
			printf("|");
			printf("%-sizeof(arrStudent[0].module[0].listTest[j].testName).2f", (float)arrStudent[0].module[0].listTest[j].mark*1.0f/100);
			
		}
		printf("|");
		int k = sizeof(" GPA ");
		printf("%-k.2f", (float)arrStudent[i].module[0].gpa * 1.0f / 10000);
		printf("|\n");
	}
	printCrossBar(arrStudent);

}

void printDash(int wide) {
	char* str = (char*)calloc(wide, sizeof(char));
	for (int i = 0; i < wide; i++) {
		str[i] = '-';
	}
	printf("%s", str);
	free(str);
}

void printCrossBar(student* arrStudent) {
	printf("+");//moduleName
	if (sizeof("MODULE") > sizeof(arrStudent[0].module[0].moduleName))
		maxModule = sizeof("MODULE");
	else maxModule = sizeof(arrStudent[0].module[0].moduleName);
	printDash(maxModule);

	printf("+");//fullName
	if (sizeof("FULL NAME") > maxName) maxName = sizeof("FULL NAME");
	printDash(maxName);

	printf("+");//DateOfBirth
	printDash(sizeof("DateOfBirth"));

	printf("+");//hometown
	if (sizeof("HOMETOWN") > maxHometown) maxHometown = sizeof("HOMETOWN");
	printDash(maxHometown);

	printf("+");//faculty
	if (sizeof("FACULTY") > maxFaculty) maxFaculty = sizeof("FACULTY");
	printDash(maxFaculty);

	printf("+");//major
	if (sizeof("MAJOR") > maxMajor) maxMajor = sizeof("MAJOR");
	printDash(maxMajor);

	for (int i = 0; i < arrStudent[0].module[0].numTests; i++)
	{
		printf("+");//test
		printDash(sizeof(arrStudent[0].module[0].listTest[i].testName));
	}
	printf("+");
	printDash(sizeof(" GPA "));
	printf("+\n");
}