#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	int i;
	int sum = 0;

	ListInit(&list);

	
	for (i = 1; i <= 9; ++i)
		LInsert(&list, i);

	printf("���� �������� �� : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("�������� ���� : %d\n", sum);
	printf("\n\n");

	sum = 0;
	if (LFirst(&list, &data))
	{
		if ((data % 2 == 0) || (data % 3 == 0))
			LRemove(&list);

		while (LNext(&list, &data))
			if ((data % 2 == 0) || (data % 3 == 0))
				LRemove(&list);
	}

	printf("���� �������� �� : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}

	printf("\n�������� ���� : %d\n", sum);
	printf("\n\n");
	return 0;
}