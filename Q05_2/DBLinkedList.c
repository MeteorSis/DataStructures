#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	//plist->cur = NULL;	//LFirst 함수가 호출됨과 동시에 초기화 되니 초기화할 필요 없음.
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));

	plist->head->data = 0;
	plist->tail->data = 0;

	plist->head->next = plist->tail;
	plist->tail->next = NULL;

	plist->head->prev = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = plist->tail->prev;
	newNode->next = plist->tail;
	plist->tail->prev->next = newNode;
	plist->tail->prev = newNode;
	++(plist->numOfData);
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head->next->next == NULL)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
	if (plist->cur->prev->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Data retData=plist->cur->data;
	Node * tmpNode = plist->cur;
	if (tmpNode->prev == NULL)
		return;
	tmpNode->prev->next = tmpNode->next;
	tmpNode->next->prev = tmpNode->prev;
	
	plist->cur = tmpNode->prev;
	free(tmpNode);
	
	--(plist->numOfData);
	return retData;
}

int LCount(List * plist)
{
	return plist->numOfData;
}