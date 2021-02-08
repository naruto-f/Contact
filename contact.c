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
	//printf("载入成功");
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
	//载入本地通讯录记录
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
			printf("通讯录扩容成功！\n");
		}
		else
		{
			printf("通讯录扩容失败！\n");
			return;
		}
		con->capacity = 2 * con->capacity;
	}
}

void AddCon(Contact* con)
{
	check_size(con);
	printf("请输入通讯录对象姓名：>");
	scanf("%s", con->data[con->size].name);
	printf("请输入通讯录对象性别：>");
	scanf("%s", con->data[con->size].sex);
	printf("请输入通讯录对象年龄：>");
	scanf("%d", &(con->data[con->size].age));
	printf("通讯录对象录入成功！！！！\n");
	con->size++;
}

void ShowCon(const Contact* con)
{
	if (con->size == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	int i = 0;
	printf("%-20s\t%-10s\t%-5s\t\n", "姓名", "性别", "年龄");
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
	printf("删除用户%s成功\n", p);
}
void DelCon(Contact* con)
{
	printf("请您输入想要删除对象的姓名：>");
	char a[30] = { 0 };
	scanf("%s", a);
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		if(strcmp(a, con->data[i].name) == 0)    //strcmp比较结果为0时两字符串相同
		{
			DelRow(con, i);
			return;
		}
	}
	printf("没有找到该用户！\n");
}

void SearchCon(Contact* con)
{
	printf("请您输入想要查找对象的姓名：>");
	char a[30] = { 0 };
	scanf("%s", a);
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		if (strcmp(a, con->data[i].name) == 0)    //strcmp比较结果为0时两字符串相同
		{
			printf("恭喜您找到了！\n");
			printf("%-20s\t%-10s\t%-5s\t\n", "姓名", "性别", "年龄");
			printf("%-20s\t%-10s\t%-5d\t\n", con->data[i].name, con->data[i].sex, con->data[i].age);
			return;
		}
	}
	printf("抱歉，未找到！\n");
}

void ModifyCon(const Contact* con)
{
	printf("请您输入想要修改对象的姓名：>");
	char a[30] = { 0 };
	scanf("%s", a);
	int i = 0;
	for (i = 0; i < con->size; ++i)
	{
		if (strcmp(a, con->data[i].name) == 0)    //strcmp比较结果为0时两字符串相同
		{
			printf("恭喜您找到了，请重新输入信息\n");
			printf("请输入通讯录对象姓名：>");
			scanf("%s", con->data[i].name);
			printf("请输入通讯录对象性别：>");
			scanf("%s", con->data[i].sex);
			printf("请输入通讯录对象年龄：>");
			scanf("%d", &(con->data[i].age));
			printf("通讯录对象修改成功！！！！\n");
			return;
		}
	}
	printf("抱歉，未找到！\n");
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
	printf("保存成功\n");
}

//排序部分
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
	printf("排序完成\n");
}
//排序部分结束


void ExitCon(Contact* con)
{
	free(con->data);
	con->data = NULL;
	printf("正在退出！\n");
}