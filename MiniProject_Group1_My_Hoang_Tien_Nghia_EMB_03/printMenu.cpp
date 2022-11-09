#include"Header.h"

void printMenu(student* pStudent, int iStudent) {
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
				//printConsole(pStudent, numStudent);
				break;
			case '1': printf("ADD\n");
				break;
			case '2': printf("MOVE\n");
				break;
			case '3': printf("MODIFY\n");
				break;
			case '4': printf("SEARCH_BY_NAME\n");
				break;
			case '5': printf("SEARCH_MIN_GPA\n");
				break;
			case '6': printf("SEARCH_MAX_GPA\n");
				break;
			case '7': printf("SORT_BY_NAME\n");
				break;
			case '8': printf("SORT_BY_GPA\n");
				break;
			default: printf("Your choice is invalid.\n");
				break;
			}
		}
	}
}
