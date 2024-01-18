#pragma once
#define NUM_EMP 3
#define SIZE 25
/* definition of an employee record*/

typedef struct employee
{
	char fname[20];
	char lname[20];
	int id;
	char dependents[3][20];     // assume no emp can have more than 3 registered dependents
}Employees;



// add function prototypes here
void saveEmployees(Employees arrEmployees[NUM_EMP], int c, char filename[SIZE]);
int loadEmployees(Employees arrEmployees[NUM_EMP], char filename[SIZE]);
void setEmpInfo(Employees* emp);
void printAnEmployee(Employees arrEmployees[NUM_EMP]);
void swapEmployees(Employees* p1, Employees* p2);
	