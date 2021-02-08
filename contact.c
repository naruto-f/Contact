#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void check_size(Contact* con);

void LoadCon(Contact* con)
{
	PeoInf tem = { 0 };
	FILE* fr = fopen("contact.txt", "rb");
	if (fr == NULL)
	{
		printf("LoadCon::%s\n", strerror(errno));
		return;
	}
	while (fread(&tem, sizeof(PeoInf), 1, fr))
	{
		check_size(con);
		con->data[con->size] = tem;
		con->size++;
	}
	fclose(fr);
	fr = NULL;
	//printf("����ɹ�");
}

void InitCon(Contact* con)
{
	con->data = (PeoInf*)malloc(START_SIZE*sizeof(PeoInf));
	if (con->data == NULL)
	{
		return;
	}
	con->capacity = START_SIZE;
	con->size = 0;
	//���뱾��ͨѶ¼��¼
	LoadCon(con);
}

void check_size(Contact* con)
{
	if (con->size > (con->capacity / 2))
	{
		PeoInf* p = realloc(con->data, 2 * con->capacity);
		if (p != NULL)
		{
			con->data = p;
			printf("ͨѶ¼���ݳɹ���\n");
		}
		else
		{
			printf("ͨѶ¼����ʧ�ܣ�\n");
			return;
		}
		con->capacity = 2 * con->capacity;
	}
}

void AddCon(Contact* con)
{
	check_size(con);
	printf("������ͨѶ¼����������>");
	scanf("%s", con->data[con->size].name);
	printf("������ͨѶ¼�����Ա�>");
	scanf("%s", con->data[con->size].sex);
	printf("������ͨѶ¼�������䣺>");
	scanf("%d", &(con->data[con->size].age));
	printf("ͨѶ¼����¼��ɹ���������\n");
	con->size++;
}

void ShowCon(const Contact* con)
{
	if (con->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	int i = 0;
	printf("%-20s\t%-10s\t%-5s\t\n", "����", "�Ա�", "����");
	for (i = 0; i < con->size; i++)
	{
		printf("%-20s\t%-10s\t%-5d\t\n", con->data[i].name, con->data[i].sex, con->data[i].age);
	}
}

void DelRow(Contact* con, int pos)
{
	char p[30] = { 0 };
	strcpy(p, con->data[pos].name);
	int i = 0;
	for (i = pos; i < con->size - 1; ++i)
	{
		con->data[i] = con->data[i + 1];
	}
	con->size--;
	printf("ɾ���û�%s�ɹ�\n", p);
}
void DelCon(Contact* con)
{
	printf("����������Ҫɾ�������������>");
	char a[30] = { 0 };
	scanf("%s", a);
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		if(strcmp(a, con->data[i].name) == 0)    //strcmp�ȽϽ��Ϊ0ʱ���ַ�����ͬ
		{
			DelRow(con, i);
			return;
		}
	}
	printf("û���ҵ����û���\n");
}

void SearchCon(Contact* con)
{
	printf("����������Ҫ���Ҷ����������>");
	char a[30] = { 0 };
	scanf("%s", a);
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		if (strcmp(a, con->data[i].name) == 0)    //strcmp�ȽϽ��Ϊ0ʱ���ַ�����ͬ
		{
			printf("��ϲ���ҵ��ˣ�\n");
			printf("%-20s\t%-10s\t%-5s\t\n", "����", "�Ա�", "����");
			printf("%-20s\t%-10s\t%-5d\t\n", con->data[i].name, con->data[i].sex, con->data[i].age);
			return;
		}
	}
	printf("��Ǹ��δ�ҵ���\n");
}

void ModifyCon(const Contact* con)
{
	printf("����������Ҫ�޸Ķ����������>");
	char a[30] = { 0 };
	scanf("%s", a);
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		if (strcmp(a, con->data[i].name) == 0)    //strcmp�ȽϽ��Ϊ0ʱ���ַ�����ͬ
		{
			printf("��ϲ���ҵ��ˣ�������������Ϣ\n");
			printf("������ͨѶ¼����������>");
			scanf("%s", con->data[i].name);
			printf("������ͨѶ¼�����Ա�>");
			scanf("%s", con->data[i].sex);
			printf("������ͨѶ¼�������䣺>");
			scanf("%d", &(con->data[i].age));
			printf("ͨѶ¼�����޸ĳɹ���������\n");
			return;
		}
	}
	printf("��Ǹ��δ�ҵ���\n");
}

void SaveCon(const Contact* con)
{
	FILE* fw = fopen("contact.txt", "wb");
	if (fw == NULL)
	{
		printf("SaveCon::%S\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		fwrite(&(con->data[i]), sizeof(PeoInf), 1, fw);
	}
	fclose(fw);
	fw = NULL;
	printf("����ɹ�\n");
}

//���򲿷�
void swap(char* arr1, char* arr2, int width)
{
	while (width)
	{
		char temp = *arr1;
		*arr1 = *arr2;
		*arr2 = temp;
		arr1++;
		arr2++;
		width--;
	}
}

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInf*)e1)->name, ((PeoInf*)e2)->name);
}

void bubble_sort(void* arr, int size, int width, int(*cmp)(const void*, const void*))
{
	int i = 0;
	int flag = 0;
	for (i = 0; i < size - 1; ++i)
	{
		int j = 0;
		for (j = 0; j < size - 1 - i; ++j)
		{
			if (cmp(((char*)arr + width * j), ((char*)arr + width * (j + 1))) > 0)
			{
				swap((char*)arr + width * j, (char*)arr + width * (j + 1), width);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void SortCon(Contact* con)
{
	bubble_sort(con->data, con->size, sizeof(PeoInf), cmp_by_name);
	printf("�������\n");
}
//���򲿷ֽ���


void ExitCon(Contact* con)
{
	free(con->data);
	con->data = NULL;
	printf("�����˳���\n");
}