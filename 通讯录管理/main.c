#include<stdio.h>  
#include<stdlib.h>  /*��׼������*/
#include"header_file.h"

/******************************************************������*******************************************************/
int main()
{
	int flg = 1;
	while (flg)
	{
		switch (print_menu())		
		{
		case 1:
			add();
			break;
		case 2:
			show();
			break;
		case 3:
			search();
			break;
		case 4:
			delete();
			break;
		case 5:
			update();
			break;
		case 6:
			save();
			break;
		case 7:
			quit();
			break;
		}
	}
}