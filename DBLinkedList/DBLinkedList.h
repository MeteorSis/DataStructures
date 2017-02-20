#pragma once

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	struct _node * prev;
	Data data;
	struct _node * next;
} Node;

typedef struct _DLinkedList
{
	Node * head;
	Node * cur;
	int numOfData;
} DLinkedList;

typedef DLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);
int LCount(List * plist);