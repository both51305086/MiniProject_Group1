#include"Header.h"
#include"PrintMenu.h"
#include"PrintList.h"
#include"Sort.h"
#include"Add.h"
#include"WriteFile.h"
#include"Move.h"
#include"Modify.h"
#include"Search.h"

void printMenu(student* pStudent, int* iStudent) {
	printf("-----------------------------------WELCOME----------------------------------------\n");
	printf("0. ADD----------------------------------------------------------------------------\n");
	printf("1. MOVE---------------------------------------------------------------------------\n");
	printf("2. MODIFY-------------------------------------------------------------------------\n");
	printf("3. SEARCH_BY_NAME-----------------------------------------------------------------\n");
	printf("4. SEARCH_MIN_GPA-----------------------------------------------------------------\n");
	printf("5. SEARCH_MAX_GPA-----------------------------------------------------------------\n");
	printf("6. SORT_BY_NAME-------------------------------------------------------------------\n");
	printf("7. SORT_BY_GPA--------------------------------------------------------------------\n");
	printf("8. EXIT---------------------------------------------------------------------------\n");
	char choice;

	while (1) {
		printf("Please enter your choice: ");
		scanf(" %c", &choice);
		if (choice == 'e' || choice == 'E') {
			printf("EXIT");
			break;
		}
		else {
			switch (choice) {
			case '0': printf("PRINT_STUDENT_LIST\n");
				printList(pStudent, nStudent);
				break;
			case '1': printf("ADD\n");
				add(pStudent, &nStudent);
				sortName(pStudent, nStudent);
				//writeFile(pathFile, pStudent, nStudent);
				break;
			case '2': printf("MOVE\n");
				move(pStudent, &nStudent);
				//writeFile(pathFile, pStudent, nStudent);
				break;
			case '3': printf("MODIFY\n");
				modify(pStudent, nStudent, nFind, position);
				//writeFile(pathFile, pStudent, nStudent);
				break;
			case '4': printf("SEARCH_BY_NAME\n");
				searchName(pStudent, nStudent, &nFind, &position);
				break;
			case '5': printf("SEARCH_MIN_GPA\n");
				searchMinGPA(pStudent, nStudent);
				break;
			case '6': printf("SEARCH_MAX_GPA\n");
				searchMaxGPA(pStudent, nStudent, nFind);
				break;
			case '7': printf("SORT_BY_NAME\n");
				sortName(pStudent, nStudent);
				break;
			case '8': printf("SORT_BY_GPA\n");
				sortGPA(pStudent, nStudent, nFind);
				break;
			default: printf("Your choice is invalid.\n");
				break;
			}
		}
	}
}
