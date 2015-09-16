
/*预处理1 头文件*/
#include"header_file.h"
/*预处理2 定义常量*/
/*以下是主菜单要显示的字符的声明*/
char menu[] =
"+==============================================================+\n"
"|          通讯录管理系统                                                                                                                        |\n"
"+==============================================================+\n"
"|          1    添加联系人                                                                                                                         |\n"
"|          2    显示所有联系人                                                                                                                         |\n"
"|          3    查找联系人                                                                                                                         |\n"
"|          4    删除联系人                                                                                                                         |\n"
"|          5    更新联系人                                                                                                                         |\n"
"|          6    保存                                                                                                                                   |\n"
"|          7    退出系统                                                                                                                            |\n"
"+==============================================================+\n";
/*预处理3 头文件*/

/*******************************************************显示主菜单界面********************************************************************/
int print_menu()
{
	int selected = 0;
	system("cls");
	printf(menu);
	printf(">请选择[1~7]:");
	scanf("%d", &selected);
	if (selected < 1 || selected>7)
	{
		printf("错误的选择！（请输入1~7）。按任意键结束。。。");
		getchar();
		getchar();
	}
	return selected;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************输入联系人信息********************************************************************/
void input_person(person *p)
{
	printf(">请输入联系人信息\n");
	printf("请输入姓名（最大长度为%d个字符）", MAX_NAME - 1);              
	scanf("%s", p->name);

	printf("请输入性别（最大长度为%d个字符）",MAX_SEX - 1);
	scanf("%s", p->sex);

	printf("请输入出生日期（最大长度为%d个字符）",MAX_BIRTHDAY - 1);
	scanf("%s", p->birthday);

	printf("请输入电话（最大长度为%d个字符）",MAX_TEL - 1);
	scanf("%s", p->tel);

	printf("请输入手机（最大长度为%d个字符）",MAX_MOBILE - 1);
	scanf("%s", p->mobile);

	printf("请输入传真（最大长度为%d个字符）",MAX_FAX - 1);
	scanf("%s", p->fax);

	printf("请输入地址（最大长度为%d个字符）",MAX_ADDRESS - 1);
	scanf("%s", p->address);

	printf("请输入邮编（最大长度为%d个字符）",MAX_POSTAL_CODE - 1);
	scanf("%s", p->postal_code);
}
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************显示联系人信息********************************************************************/
void print_person(person *p)
{
	printf("姓名：%s \t     性别:%s \t    生日:%s\n", p->name, p->sex, p->birthday);
	printf("电话:%s \n", p->tel);
	printf("手机:%s \n", p->mobile);
	printf("传真:%s \n", p->fax);
	printf("地址:%s \n", p->address);
	printf("邮编:%s \n", p->postal_code);
	printf("\n");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*******************************************************取得链表最后一个值********************************************************************/
addr_book *get_last(addr_book *form)
{
	addr_book *p = form;/*参数传过来一个节点form，如果from的下一个节点不为空，顺序找到该链表的最后一个节点；
						如果为空，form就是最后一个节点*/
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

