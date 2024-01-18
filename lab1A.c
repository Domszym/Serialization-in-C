#define _CRT_SECURE_NO_WARNINGS
#include "lab1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void saveEmployees(Employees arrEmployees[NUM_EMP], int c, char filename[SIZE])
{
	FILE* file = fopen(filename, "w");
	if (file == NULL)
	{
		return 1;
	}

	for (int i = 0; i < c; i++)
	{
		fprintf(file, "%s, %s, %d, ", arrEmployees[i].fname, arrEmployees[i].lname, arrEmployees[i].id);
		for (int j = 0; j < 3; j++) 
		{
			fprintf(file, "%s, ", arrEmployees[i].dependents[j]);
		}
		fprintf(file, "\n"); //adding new newline after each employee's data has been entered
	}

	fclose(file);
	printf("Succesfully Written to File!\n");
}

int loadEmployees(Employees arrEmployees[NUM_EMP], char filename[SIZE]) {
    memset(arrEmployees, 0, sizeof(Employees) * NUM_EMP);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[200]; 
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < NUM_EMP) {
        int read = sscanf(line, "%19[^,], %19[^,], %d, %19[^,], %19[^,], %19[^,],",
            arrEmployees[count].fname,
            arrEmployees[count].lname,
            &arrEmployees[count].id,
            arrEmployees[count].dependents[0],
            arrEmployees[count].dependents[1],
            arrEmployees[count].dependents[2]);

        if (read == 6) { // 6 items (fname, lname, id, 3 dependents) should be read
            count++;
        }
        else {
            printf("File format is incorrect\n");
            fclose(file);
            return 1;
        }
    }

    if (ferror(file)) {
        printf("File Error\n");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("Loaded %d employees.\n", count);
    return count;
}

void setEmpInfo(Employees *emp)
{
	printf("Enter First Name ");
	scanf(" %s", emp->fname);
	
	printf("\nEnter Last name ");
	scanf(" %s", emp->lname);
	
	printf("\nEnter Emp ID ");
	scanf(" %d", &emp->id);

	for (int i = 0; i < 3; i++) {
		printf("\nEnter Dependents: ");
		scanf(" %s", &emp->dependents[i]);
	}

}

void printAnEmployee(Employees *employee) 
{
    printf("First Name: %s\n", employee->fname);
    printf("Last Name: %s\n", employee->lname);
    printf("Employee ID: %d\n", employee->id);
    for (int i = 0; i < 3; i++) {
        printf(" %s\n", employee->dependents[i]);
    }
}



void swapEmployees(Employees* p1, Employees* p2)
{
	Employees temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
