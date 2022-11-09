#include"Header.h"

int writeFile(char* fileName, student* pStudent, int nStudent) {
	FILE* fp = NULL;
	fp = fopen(pathFile, "w+");
	if (NULL == fp) return 0;
	else printf("Open successfully!\n");
	for (int i = 0; i < nStudent; i++) {
		fprintf(fp,"%s,%hhd,%hhd,%hd,%s,%s,%s,%f,%hhd,%hhd\n", pStudent[i].fullName, &pStudent[i].birthDay.day, &pStudent[i].birthDay.month,
			&pStudent[i].birthDay.year, pStudent[i].hometown, pStudent[i].faculty, pStudent[i].major, &pStudent[i].entryPoint, &pStudent[i].numModules, &pStudent[i].numTests);
		for (int j = 0; j < pStudent[i].numModules; j++) {
			for (int k = 0; k < pStudent[i].numTests; k++) {
				fprintf(fp,"%s,%s,%f,%f,%s,%f,%f,%s,%f,%f,%s,%f,%f,%s,%f,%f,%s,%f,%f,%s,%f,%f,%f\n", pStudent[i].module[j].moduleName,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark,
					pStudent[i].module[j].listTest[k].testName, &pStudent[i].module[j].listTest[k].weight, &pStudent[i].module[j].listTest[k].mark, &pStudent[i].module[j].gpa);
			}
		}
	}
	fclose(fp);
	return 1;
}