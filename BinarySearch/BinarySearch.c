#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int center;
	
	while (first <= last)
	{
		center=(first + last) / 2;
		if (target == ar[center])
			return center;
		else if (target < ar[center])
			last = center - 1;
		else
			first = center + 1;
	}
	return -1;
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	return 0;
}