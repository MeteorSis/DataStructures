#include "ArrayList.h"

void ListInit(List * plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}
	plist->arr[plist->numOfData++] = data;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;
	else
	{
		plist->curPosition = 0;
		*pdata = plist->arr[plist->curPosition];
		return TRUE;
	}
}

int LNext(List * plist, LData * pdata)
{

	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;
	else
	{
		plist->curPosition++;
		*pdata = plist->arr[plist->curPosition];
		return TRUE;
	}
}

LData LRemove(List * plist)
{
	LData retData;
	int i;
	retData = plist->arr[plist->curPosition];
	for (i = plist->curPosition; i < plist->numOfData - 1; ++i)
		plist->arr[i] = plist->arr[i + 1];

	--(plist->numOfData);
	--(plist->curPosition);
	return retData;
}

int LCount(List * plist)
{
	return plist->numOfData;
}