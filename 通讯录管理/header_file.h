#include<stdio.h>  
#include<stdlib.h>
/*********************************************************1.常量定义***********************************************/
#define MAX_NAME 11
#define MAX_SEX 3
#define MAX_BIRTHDAY 11
#define MAX_TEL 21
#define MAX_MOBILE 21
#define MAX_FAX 21
#define MAX_ADDRESS 101
#define MAX_POSTAL_CODE 7


/******************************************************2.结构体**********************************************************/
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
}person;                    /*定义结构体类型_person. 使用typedef语句定义一个新类型_person；       _person是结构体类型 ，person是节点类型*/

typedef struct _addr_book
{
	person per;
	struct _addr_book *next;
}addr_book;             /*定义结构体类型_addr_book. 结构体中包含联系人信息的结构体变量per和下一个联系人的指针变量*/



 /************************************************3 函数声明***********************************************/
/*主要处理函数声明*/
void add();
void show();
void search();
void delete();
void update();
void save();
void quit();

/*辅助函数声明*/
int print_menu();                                    /*打印主菜单界面*/
addr_book *get_last(addr_book *from);/*取得链表最后一个值*/
void print_person(person *p);                /*显示一个联系人信息*/
void input_person(person *p);               /*提示输入一个联系人的具体信息*/


#pragma once
