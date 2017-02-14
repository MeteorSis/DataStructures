#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	ArrayList list;
	NameCard * nameCard;
	ListInit(&list);

	LInsert(&list, MakeNameCard("최기재", "010-7528-3580"));
	LInsert(&list, MakeNameCard("신솔비", "010-1234-1234"));
	LInsert(&list, MakeNameCard("송현영", "010-5678-5678"));

	printf("전체 목록 출력\n");
	if (LFirst(&list, &nameCard))
	{
		ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			ShowNameCardInfo(nameCard);
	}

	printf("특정 이름 검색 출력\n");
	if (LFirst(&list, &nameCard))
	{
		if (!NameCompare(nameCard, "신솔비"))
			ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			if (!NameCompare(nameCard, "신솔비"))
				ShowNameCardInfo(nameCard);
	}

	printf("특정 이름 전화번호 변경\n\n");
	if (LFirst(&list, &nameCard))
	{
		if (!NameCompare(nameCard, "송현영"))
			ChangePhoneNum(nameCard, "010-5588-9988");
		while (LNext(&list, &nameCard))
			if (!NameCompare(nameCard, "송현영"))
				ChangePhoneNum(nameCard, "010-5588-9988");
	}

	printf("전체 목록 출력\n");
	if (LFirst(&list, &nameCard))
	{
		ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			ShowNameCardInfo(nameCard);
	}

	printf("특정 이름 정보 삭제\n\n");
	if (LFirst(&list, &nameCard))
	{
		if (!NameCompare(nameCard, "최기재"))
			LRemove(&list);
		while (LNext(&list, &nameCard))
			if (!NameCompare(nameCard, "최기재"))
				LRemove(&list);
	}

	printf("전체 목록 출력\n");
	if (LFirst(&list, &nameCard))
	{
		ShowNameCardInfo(nameCard);
		while (LNext(&list, &nameCard))
			ShowNameCardInfo(nameCard);
	}
	return 0;
}