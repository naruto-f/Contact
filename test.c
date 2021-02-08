#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("***1.ADD      ************2.DEL     ***********\n");
	printf("***3.SEARCH   ************4.MODIFY  ***********\n");
	printf("***5.SHOW     ************6.SORT    ***********\n");
	printf("***7.SAVE     ************0.EXIT    ***********\n");
	printf("***********************************************\n");
}

     
int main()
{
	Contact con;
	InitCon(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ������ʹ�õĹ���:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddCon(&con);
			break;
		case DEL:
			DelCon(&con);
			break;
		case SEARCH:
			SearchCon(&con);
			break;
		case MODIFY:
			ModifyCon(&con);
			break;
		case SHOW:
			ShowCon(&con);
			break;
		case SORT:
			SortCon(&con);
			break;
		case SAVE:
			SaveCon(&con);
			break;
		case EXIT:
			ExitCon(&con);
			break;
		default:
			printf("����ѡ��Ϸ�������������\n");
		    break;
		}
	} while (input);
	return 0;
}











