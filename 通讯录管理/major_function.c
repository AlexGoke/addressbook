/*预处理1 头文件*/
#include"header_file.h"
#include<stdio.h>  
#include<stdlib.h>
/*预处理2 定义常量*/

/*预处理3 头节点*/
addr_book *first = NULL;     /*addr_book结构体，链表的头节点，置空*/
/******************************************************1 添加新记录**************************************************************/

void add()
{
	char input = 'N';
	addr_book *last = NULL;

	/*创建一个结构体指针变量new_addr,将其next指针置空，其余信息使用memset函数置0*/
	addr_book *new_addr = (addr_book*)malloc(sizeof(addr_book));
	memset(new_addr, 0, sizeof(addr_book));/*将addr_book中的前addr_book个长度的初值设置为0*/
	new_addr->next = NULL;

	/*判断单链表是否有数据。如果没有，即first==NULL,则置new_addr为头节点；否则调用函数get_last找到单链表中的最后一个节点last，
	将new_addr连接到最后一个节点last的后面*/
	if (first == NULL)
	{
		first = new_addr;
	}
	else
	{
		last = get_last(first);
		last->next = new_addr;
	}

	input_person(&(new_addr->per));/*调用函数input_person完成一个联系人信息的输入*/
	printf(">继续输入？（Y 继续，N 返回菜单）");
	getchar();
	input = getchar();
	if (input == 'Y' || input == 'y')
	{
		add();
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/********************************************************2 显示联系人信息****************************************************************/
void show()
{
	int i = 0;

	/*首先定义一个指针变量指向头节点first*/
	addr_book *p = first;
	while (p != NULL)
	{
		i++;
		printf("****************************************第%d个联系人******************************\n",i);
		print_person(&(p->per));/*调用函数print_person,逐个打印联系人信息*/
		p = p->next;
	}
	if (i == 0)
	{
		printf("没有联系人！");
	}
	printf("按任意键返回菜单。。。");
	getchar();
	getchar();
}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************3 查找联系人信息*****************************************************************/
void search()
{
	int count = 0;
	char input = 'N';
	char name[MAX_NAME] = { 0 };
	/*首先定义一个指针变量指向头节点first*/
	addr_book *p = first;
	printf(">请输入要查找的联系人姓名（最大为%d个字符）：",MAX_NAME - 1);
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->per.name, name) == 0)
		{
			print_person(&(p->per));/*调用print_person函数显示该联系人信息*/
			count++;
		}
		p = p->next;
	}
	if (count == 0)
	{
		printf("没有找到姓名为%s的人。",name);
	}
	printf("继续查找吗？（Y 继续查找，N 返回菜单）");
	getchar();
	input = getchar();
	if (input == ' Y' || input == 'y')
	{
		search();
	}
}
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************4 删除联系人信息*****************************************************************/
void delete()
{
	int count = 0;
	char input = 'N';
	char name[MAX_NAME] = { 0 };
	/*首先定义一个指针变量指向头节点first,定义一个p1，将其置空*/
	addr_book *p = first ;
	addr_book *p1 = NULL ;
	/*输入要删除的联系人姓名，根据姓名在单链表中逐个查找。没找到 给出信息 ，否则进行删除操作*/
	printf(">请输入要删除的联系人姓名（最大%d个字符）", MAX_NAME - 1);
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->per.name, name) == 0)
		{
			print_person(&(p->per));/*调用print_person函数显示该联系人信息*/
			count++;
		}
		p = p->next;
	}
	if (count == 0)
	{
		printf("没有找到姓名为%s的人。", name);
	}
	else
	{
		printf("确定要删除姓名为[%s]的联系人吗？（Y 确认，N 取消）", name);
		getchar();
		input = getchar();
		if (input == ' Y' || input == 'y')
		{
			if (p == first)/*如果要删除的节点p为头节点，将p->next赋值给first,直接删除*/
			{
				first = p->next;
			}
			else/*如果不是头节点，先设置p1指向头节点，然后循环判断p1后续结点是不是p，若是即p1->next=p->next,释放p*/
			{
				p1 = first;
				while (p1 !=  NULL)
				{
					if (p1->next == p)
					{
						p1->next = p->next;
						break;
					}
					p1 = p1->next;
				}
			}
			free(p);
		}
	}
	/*提示用户是否继续删除操作，如果用户输入'Y' 'y'则继续，调用本函数，否则返回主菜单*/
	printf("继续删除其他联系人吗？（Y 继续删除，N 返回菜单）");
	getchar();
	input = getchar();
	if (input == ' Y' || input == 'y')
	{
		delete();
	}
}
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************5 更新联系人信息*****************************************************************/
void update()
{
	int count = 0;
	char input = 'N';
	char name[MAX_NAME] = { 0 };
	/*首先定义一个指针变量指向头节点first,定义一个p1，将其置空*/
	addr_book *p = first;
	printf(">请输入要更新的联系人姓名（最大为%d个字符）：",MAX_NAME - 1);
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->per.name, name) == 0)
		{
			print_person(&(p->per));/*调用print_person函数显示该联系人信息*/
			count++;
			break;
		}
		p = p->next;
	}
	if (count == 0)
	{
		printf("没有找到姓名为%s的人。", name);
	}
	else/*如果找到调用函数input_person更新其基本信息*/
	{
		input_person(&(p->per));
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************6 保存联系人信息*****************************************************************/
void save()
{
	FILE *fp;
	char file[100];
	/*首先定义一个指针变量指向头节点first,定义一个p1，将其置空*/
	addr_book *p = first;
	/*输入文件名，循环利用函数fprintf逐个将单链表中联系人信息保存到文件中*/
	printf("请输入文件名：");
	scanf("%s", file);
	fp = fopen(file, "w");
	/*'w'以只写方式打开一个文件，r 只读，a向文本文件尾增加数据 若文件不存在就创建一个文件（wb，rb，ab针对二进制文件）*/
	while (p != NULL)
	{
		fprintf(fp, "%s, %s, %s, %s, %s, %s, %s, %s\n", p->per.name, p->per.sex, p->per.birthday, p->per.tel, p->per.mobile, p->per.fax,
			p->per.address, p->per.postal_code);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功！\n按任意键返回菜单。。。\n");
	getchar();
	getchar();
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************7 退出系统函数*****************************************************************/
void quit()
{
	addr_book *p1 = first;
	addr_book *p = NULL;
	if (p1 == NULL)
	{
		exit(0);
	}
	/*如果p1的next指针不为空，说明有下一条数据*/
	/*先将p指向p1的下一条数据，然后释放掉p1,将p重新赋值给p1*/
	while (p1->next != NULL)
	{
		p = p1->next;
		free(p1);
		p1 = p;
	}
	free(p1);/*如果p1的next指针为空，说明没有下一条数据，直接删除该节点*/
	exit(0);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
				