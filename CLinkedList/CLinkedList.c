#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List * plist)
{
	plist->before = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
	plist->tail = NULL;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL)
	{
		newNode->next = newNode;
		plist->tail = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	++(plist->numOfData);
}

void LInsertFront(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL)
	{
		newNode->next = newNode;
		plist->tail = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	++(plist->numOfData);
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before=plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}


Data LRemove(List * plist)
{
	Node * tmpNode = plist->cur;
	Data retData = tmpNode->data;


	if (plist->tail == tmpNode)
	{
		if (plist->tail->next == plist->tail)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}
	plist->before->next = tmpNode->next;
	plist->cur = plist->before;

	free(tmpNode);
	--(plist->numOfData);
	return retData;
}

int LCount(List * plist)
{
	return plist->numOfData;
}