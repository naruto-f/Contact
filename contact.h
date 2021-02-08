#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define MAX_NAME 30
#define MAX_SEX 10
#define START_SIZE 3


enum fnc
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

typedef struct PeoInf
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
}PeoInf;

typedef struct Contact
{
	 PeoInf* data;
	 int capacity;
     int size;
}Contact;

//初始化通讯录
void InitCon(Contact* con);

//添加通讯录成员
void AddCon(Contact* con);

//检查通讯录容量，不足则动态扩展
void check_size(Contact* con);

//展示通讯录
void ShowCon(const Contact* con);

//删除指定姓名通讯录成员
void DelCon(Contact* con);

//删除匹配到的成员
void DelRow(Contact* con, int pos);

//查找指定姓名通讯录成员
void SearchCon(const Contact* con);

//修改指定姓名通讯录成员信息
void ModifyCon(Contact* con);

//保存通讯录信息到本地文本文件
void SaveCon(Contact* con);

//载入本地通讯录
void LoadCon(const Contact* con);

//按通讯录成员姓名排序
void SortCon(Contact* con);

//退出通讯录
void ExitCon(Contact* con);


