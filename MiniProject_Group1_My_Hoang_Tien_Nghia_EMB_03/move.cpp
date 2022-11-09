#include"Header.h"
#include"Move.h"
#include"Search.h"
void move(student* pStudent, int *nStudent, int nFind, int position){
	student* arrStudent = searchName(pStudent, *nStudent, &nFind, &position);
	if (arrStudent != NULL) {
		if (nFind == 1) {
			for (int i = position; i < *nStudent; i++) {
				pStudent[i] = pStudent[i + 1];
			}
		}
		else
		{
			int find = 0;
			int pos = 0;
			student* arrStudent1 = searchYear(arrStudent, nFind, &find, &pos);
			if (find == 1) {
				for (int i = position + pos; i < *nStudent && pos < nFind; i++) {
					pStudent[i] = pStudent[i + 1];
				}
			}
		}
		pStudent[*nStudent - 1] = { '\0' };
		nStudent -= 1;
	}
}
