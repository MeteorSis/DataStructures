#include <stdio.h>
#include <string.h>
#include "CLinkedList.h"


Employee * WhosNightDuty(List * plist, char * name, int day)
{
	Employee *empPtr;
	if (LFirst(plist, &empPtr))
	{
		if (strcmp(empPtr->name, name) == 0)
	}
		strcmp(empPtr
}

int main(void)
{
	List list;
	int i;
	Employee * empPtr;

	ListInit(&list);
		
	empPtr = (Employee *)malloc(sizeof(Employee));
	empPtr->empNum = 11111;
	strcpy(empPtr->name, "A");
	LInsert(&list, empPtr);

	empPtr = (Employee *)malloc(sizeof(Employee));
	empPtr->empNum = 22222;
	strcpy(empPtr->name, "B");
	LInsert(&list, empPtr);
	
	empPtr = (Employee *)malloc(sizeof(Employee));
	empPtr->empNum = 33333;
	strcpy(empPtr->name, "C");
	LInsert(&list, empPtr);

	empPtr = (Employee *)malloc(sizeof(Employee));
	empPtr->empNum = 44444;
	strcpy(empPtr->name, "D");
	LInsert(&list, empPtr);

	empPtr = WhosNightDuty(&list, "A", 3);
	ShowEmployeeInfo(empPtr);

	empPtr = WhosNightDuty(&list, "D", 15);
	ShowEmployeeInfo(empPtr);


	if (LFirst(&list, &empPtr))
	{
		free(empPtr);
		for (i = 0; i < LCount(&list) - 1; ++i)
		{
			if(LNext(&list, &empPtr))
				free(empPtr);
		}
	}
	return 0;
}