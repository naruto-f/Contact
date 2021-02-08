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

//��ʼ��ͨѶ¼
void InitCon(Contact* con);

//���ͨѶ¼��Ա
void AddCon(Contact* con);

//���ͨѶ¼������������̬��չ
void check_size(Contact* con);

//չʾͨѶ¼
void ShowCon(const Contact* con);

//ɾ��ָ������ͨѶ¼��Ա
void DelCon(Contact* con);

//ɾ��ƥ�䵽�ĳ�Ա
void DelRow(Contact* con, int pos);

//����ָ������ͨѶ¼��Ա
void SearchCon(const Contact* con);

//�޸�ָ������ͨѶ¼��Ա��Ϣ
void ModifyCon(Contact* con);

//����ͨѶ¼��Ϣ�������ı��ļ�
void SaveCon(Contact* con);

//���뱾��ͨѶ¼
void LoadCon(const Contact* con);

//��ͨѶ¼��Ա��������
void SortCon(Contact* con);

//�˳�ͨѶ¼
void ExitCon(Contact* con);


