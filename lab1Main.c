#define _CRT_SECURE_NO_WARNINGS
#include "lab1.h"
//Written by Dominic Szymanski on Sunday January 14th 
/* This program allows the user to input values for an employee into an array of structs, They can at most enter three employees
Once the user has inputted the values for employee they can then write and read to a .txt file that they name using command line arguments*/

int main(int argc, char *argv[])
{
	if (argc < 2) { // More than two arguments return
		return 1;
	}
	
	char* filename = argv[1]; // Setting filename to second command line argument
    int empCount = 0; // variable for number of times they can enter an employee 
	Employees employee[NUM_EMP]; // array of structs declaration 
    Employees emp = { "Dominic", "Szymanski", 12 , {"Adrian", "Luke", "Paul"} };
    int i1, i2;
    while (1) {
        printf("1. Add Employee\n2. Write to File\n3. Load from File\n4. Print Employees\n5. Swap Employees\n0. Exit\n"); 
        printf("Enter your choice: ");
        int input;                                                      // infinite while loop with swicth case statemnts
        scanf("%d", &input);

        if (input == 0) {
            break; // Exit the loop
        }

        switch (input) {
        case 1:
            if (empCount < NUM_EMP) {
                setEmpInfo(&employee[empCount]); // if loop for limiting number of employees that can be entered
                empCount++;
            }
            else {
                printf("Employee limit reached.\n");
            }
            break;
        case 2:
            saveEmployees(employee, empCount, filename);
            break;
        case 3:
            loadEmployees(employee, filename);
            break;
        case 4:
            printAnEmployee(&emp);
            break;
        case 5:
            printf("What Indices would you like to swap?(0-2)");
            scanf("%d %d", &i1, &i2); 
            
            while (i1 < 0 || i1 > 2 || i2 < 0 || i2 > 2) {
                printf("Invalid input. Please enter indices between 0 and 2.\n");
                scanf("%d %d", &i1, &i2);
            }
            swapEmployees(&employee[i1], &employee[i2]);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

		
