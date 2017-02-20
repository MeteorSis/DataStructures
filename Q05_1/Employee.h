#pragma once

typedef struct _Employee
{
	int empNum;
	char name[30];
} Employee;


void ShowEmployeeInfo(Employee * emp);