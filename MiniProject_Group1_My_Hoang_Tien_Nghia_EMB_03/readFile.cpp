#include"Header.h"
#include"ReadFile.h"

int  readFile(const char* fileName, student* pStudent, int* nStudent) {
	FILE* fp = NULL;
	fp = fopen(pathFile, "r");

	if (NULL == fp) return 0;
	else printf("Open successfully!\n");
	char line[MAX_CHAR_IN_LINE];
	rewind(fp);//move fp to start file
	int iStudent = 0, numLines = 0, linesOfStudent = 0;
	int iModule = 0, iTest = 0;

	for (; fgets(line, MAX_CHAR_IN_LINE, fp) != NULL; numLines++) {
		if (linesOfStudent == 0) {
			sscanf(line, "%[^,],%hhd%*c%hhd%*c%hd,%[^,],%[^,],%[^,],%f,%hhd", pStudent[iStudent].fullName, &pStudent[iStudent].birthDay.day, &pStudent[iStudent].birthDay.month,
				&pStudent[iStudent].birthDay.year, pStudent[iStudent].hometown, pStudent[iStudent].faculty, pStudent[iStudent].major, &pStudent[iStudent].entryPoint, &pStudent[iStudent].numModules);
			iStudent++;
			linesOfStudent++;
			numLines++;
		}
		else {
			sscanf(line, "%[^,],%hhd,%[^,],%f,%f,%[^,],%f,%f,%[^,],%f,%f,%[^,],%f,%f,%[^,],%f,%f,%[^,],%f,%f,%[^,],%f,%f,%f", pStudent[iStudent - 1].module[iModule].moduleName, &pStudent[iStudent].module[iModule].numTests,
				pStudent[iStudent - 1].module[iModule].listTest[iTest].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest].mark,
				pStudent[iStudent - 1].module[iModule].listTest[iTest + 1].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 1].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 1].mark,
				pStudent[iStudent - 1].module[iModule].listTest[iTest + 2].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 2].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 2].mark,
				pStudent[iStudent - 1].module[iModule].listTest[iTest + 3].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 3].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 3].mark,
				pStudent[iStudent - 1].module[iModule].listTest[iTest + 4].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 4].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 4].mark,
				pStudent[iStudent - 1].module[iModule].listTest[iTest + 5].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 5].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 5].mark,
				pStudent[iStudent - 1].module[iModule].listTest[iTest + 6].testName, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 6].weight, &pStudent[iStudent - 1].module[iModule].listTest[iTest + 6].mark, &pStudent[iStudent - 1].module[iModule].gpa);
			iModule++;
			linesOfStudent++;
			numLines++;
			if (iModule == pStudent[iStudent - 1].numModules) linesOfStudent = 0;
		}
	}
	*nStudent = iStudent;
	fclose(fp);
	return 1;
}