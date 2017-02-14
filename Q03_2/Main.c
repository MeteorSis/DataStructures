#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	ArrayList list;
	NameCard * nameCard;
	ListInit(&list);

	LInsert(&list, MakeNameCard("�ֱ���", "010-7528-3580"));
	LInsert(&list, MakeNameCard("�żֺ�", "010-1234-1234"));
	LInsert(&list, MakeNameCard("������", "010-5678-5678"));

	printf("��ü ��� ���\n");
	if (LFirst(&list, &nameCard))
	{
		ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			ShowNameCardInfo(nameCard);
	}

	printf("Ư�� �̸� �˻� ���\n");
	if (LFirst(&list, &nameCard))
	{
		if (!NameCompare(nameCard, "�żֺ�"))
			ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			if (!NameCompare(nameCard, "�żֺ�"))
				ShowNameCardInfo(nameCard);
	}

	printf("Ư�� �̸� ��ȭ��ȣ ����\n\n");
	if (LFirst(&list, &nameCard))
	{
		if (!NameCompare(nameCard, "������"))
			ChangePhoneNum(nameCard, "010-5588-9988");
		while (LNext(&list, &nameCard))
			if (!NameCompare(nameCard, "������"))
				ChangePhoneNum(nameCard, "010-5588-9988");
	}

	printf("��ü ��� ���\n");
	if (LFirst(&list, &nameCard))
	{
		ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			ShowNameCardInfo(nameCard);
	}

	printf("Ư�� �̸� ���� ����\n\n");
	if (LFirst(&list, &nameCard))
	{
		if (!NameCompare(nameCard, "�ֱ���"))
			LRemove(&list);
		while (LNext(&list, &nameCard))
			if (!NameCompare(nameCard, "�ֱ���"))
				LRemove(&list);
	}

	printf("��ü ��� ���\n");
	if (LFirst(&list, &nameCard))
	{
		ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			ShowNameCardInfo(nameCard);
	}
	return 0;
}