#include"Header.h"
#include"Modify.h"
#include"Search.h"
#include"Add.h"
void modify(student* pStudent, int nStudent, int nFind, int position) {
	student* arrStudent = searchName(pStudent, nStudent, &nFind, &position);
	int find = 0, pos = 0,numFind = 0;
	student* aStudent = searchYear(arrStudent, nFind, &find, &pos);

	searchModule(aStudent, find, &numFind);
	for (int i = 0; i < pStudent[nFind + find - 1].module[numFind].numTests; i++) {
		pStudent[nFind + find - 1].module[numFind].listTest[i].mark = enterInt(Mark, 0, 0);
	}
}