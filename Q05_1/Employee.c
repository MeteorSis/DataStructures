#include "Employee.h"
#include <stdio.h>

void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee name : %s\n", emp->name);
	printf("Employee number : %d\n", emp->empNum);
}