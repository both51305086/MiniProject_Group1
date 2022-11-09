#include"Header.h"
#include"ReadFile.h"
#include"WriteFile.h"
#include"Add.h"
#include"PrintMenu.h"
#include"PrintList.h"
#include"Move.h"
#include"Search.h"
#include"Sort.h"

int main() {
	char pathFile[] = "Student_List.txt";

	student* pStudent = (student*)calloc(MAX_STUDENT, sizeof(student));
	if (pStudent == NULL) {
		printf("not enough memory!");
		return -1;
	}
	readFile(pathFile, pStudent, &nStudent);
	printMenu(pStudent, &nStudent);
	//writeFile(pathFile, pStudent, nStudent);
	free(pStudent);
	return 0;
}