#include"Header.h"
#include"PrintMenu.h"
#include"Search.h"
void sortName(student* pStudent, int nStudent) {
	int i, j;
	while (1) {
		bool haveSwap = false;
		for (i = 0; i < nStudent - 1; i++) {
			for (j = nStudent - 1; j > i; j--) {
				if (strcmp(pStudent[j].name, pStudent[j - 1].name) < 0 ||
					(strcmp(pStudent[j].name, pStudent[j - 1].name) == 0 && (pStudent[j].birthDay.year > pStudent[j - 1].birthDay.year
						||(pStudent[j].birthDay.year == pStudent[j - 1].birthDay.year && pStudent[j].birthDay.month > pStudent[j - 1].birthDay.month)
						||(pStudent[j].birthDay.year == pStudent[j - 1].birthDay.year && pStudent[j].birthDay.month == pStudent[j - 1].birthDay.month && pStudent[j].birthDay.day > pStudent[j - 1].birthDay.day)))){
					student temp = pStudent[j];
					pStudent[j] = pStudent[j - 1];
					pStudent[j - 1] = temp;
					haveSwap = true;
				}
			}
		}
		if (haveSwap == false) {
			break;
		}
	}
}
student* sortGPA(student* pStudent, int nStudent, int nFind) {
	static student* arrStudent = searchModule(pStudent, nStudent, &nFind);
	while (1) {
		bool haveSwap = false;
		for (int i = 0; i < nFind - 1; i++) {
			for (int j = nFind - 1; j > i; j--) {
				if (arrStudent[j].module[0].gpa < arrStudent[j - 1].module[0].gpa) {
					student temp = arrStudent[j];
					arrStudent[j] = arrStudent[j - 1];
					arrStudent[j - 1] = temp;
					haveSwap = true;

				}
			}
		}
		if (haveSwap == false) {
			break;
		}
	}
	return arrStudent;
}