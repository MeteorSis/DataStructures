#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	//plist->cur = NULL;	//LFirst 함수가 호출됨과 동시에 초기화 되니 초기화할 필요 없음.
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = plist->head;

	if (plist->head != NULL)
		plist->head->prev = newNode;

	plist->head = newNode;
	++(plist->numOfData);
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(List * plist)
{
	return plist->numOfData;
}