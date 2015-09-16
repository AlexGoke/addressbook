#include<stdio.h>  
#include<stdlib.h>
/*********************************************************1.��������***********************************************/
#define MAX_NAME 11
#define MAX_SEX 3
#define MAX_BIRTHDAY 11
#define MAX_TEL 21
#define MAX_MOBILE 21
#define MAX_FAX 21
#define MAX_ADDRESS 101
#define MAX_POSTAL_CODE 7


/******************************************************2.�ṹ��**********************************************************/
typedef struct _person
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char birthday[MAX_BIRTHDAY];
	char tel[MAX_TEL];
	char mobile[MAX_MOBILE];
	char fax[MAX_FAX];
	char address[MAX_ADDRESS];
	char postal_code[MAX_POSTAL_CODE];
}person;                    /*����ṹ������_person. ʹ��typedef��䶨��һ��������_person��       _person�ǽṹ������ ��person�ǽڵ�����*/

typedef struct _addr_book
{
	person per;
	struct _addr_book *next;
}addr_book;             /*����ṹ������_addr_book. �ṹ���а�����ϵ����Ϣ�Ľṹ�����per����һ����ϵ�˵�ָ�����*/



 /************************************************3 ��������***********************************************/
/*��Ҫ����������*/
void add();
void show();
void search();
void delete();
void update();
void save();
void quit();

/*������������*/
int print_menu();                                    /*��ӡ���˵�����*/
addr_book *get_last(addr_book *from);/*ȡ���������һ��ֵ*/
void print_person(person *p);                /*��ʾһ����ϵ����Ϣ*/
void input_person(person *p);               /*��ʾ����һ����ϵ�˵ľ�����Ϣ*/


#pragma once
