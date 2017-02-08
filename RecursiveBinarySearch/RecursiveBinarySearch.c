#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	int center = (first + last) / 2;

	if (first > last)
		return -1;
		
	if (ar[center] == target)
		return center;
	else if (target < ar[center])
		return BSearchRecur(ar, first, center - 1, target);
	else
		return BSearchRecur(ar, center + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d\n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d\n", idx);

	return 0;
}