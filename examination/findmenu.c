#include"tools.h"




void enter()//登录
{
	long long input_enter = 10;
	do
	{

		printf("请输入账号：");
		scanf("%lld", &input_enter);
		int back_num = regtister(input_enter);
		switch (back_num)
		{
		case 1:
			main_project();//管理员登录
			break;
		case 2:
			main_student();//学生登录
			break;
		case 0:
			printf("退出");
			break;
		default:
			printf("输入格式错误，请重新输入\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input_enter);
}


void Find_Exam()//II题库查看菜单
{
	int x = 10;
	do
	{
		menu3iii();
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			Findsimple();//查看单选
			break;
		case 2:
			Findmultiple();//查看多选
			break;
		case 3:
			Read_judge();//查看判断
			break;
		case 0:
			printf("返回上一级\n");
			break;
		default:
			printf("< 选择错误！！! >");
			break;
		}
		system("pause");
		system("cls");
	} while (x);
}

void Change_Exam()//II题库更改菜单
{
	int c = 10;
	do
	{
		menu3ii();
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			Change_simple();//更改单选
			break;
		case 2:
			Change_multiple();//更改多选
			break;
		case 3:
			Change_judge();//更改判断
			break;
		case 0:
			printf("返回上一级\n");
			break;
		default:
			printf("< 选择错误！！! >");
			break;
		}
		system("pause");
		system("cls");
	} while (c);
}

void Write_Exam()//II题库录入菜单
{
	int w = 10;
	do
	{
		menu3i();
		scanf("%d", &w);
		switch (w)
		{
		case 1:
			Write_simple();//录入单选
			break;
		case 2:
			Write_multiple();//录入多选
			break;
		case 3:
			Write_judge();//录入判断题
			break;
		case 0:
			printf("返回上一级\n");
			break;
		default:
			printf("< 选择错误！！! >");
			break;
		}
		system("pause");
		system("cls");
	} while (w);
}

void Delite_Exam()
{
	int a = 10;
	do
	{
		menu3iiii();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Delite_simple();//删除单选
			break;
		case 2:
			Delite_multiple();//删除多选
			break;
		case 3:
			Delite_judge();//删除判断题
			break;
		case 0:
			printf("返回上一级\n");
			break;
		default:
			printf("< 选择错误！！! >");
			break;
		}
		system("pause");
		system("cls");
	} while (a);
}

void Item_bank()//I试题库管理菜单操作
{
	int y = 10;
	do
	{
		menu2();
		scanf("%d", &y);
		switch (y)
		{
		case 1:
			Write_Exam();//写入界面
			break;
		case 2:
			Change_Exam();//更改界面
			break;
		case 3:
			Find_Exam();//查找界面
			break;
		case 4:
			Delite_Exam();//删除界面
			break;
		case 0:
			printf("已退出系统\n");
			break;
		default:
			printf("< 选择错误！！! >");
			break;
		}
		system("pause");
		system("cls");
	} while (y);
}


void Exam_time()
{
	int t = 10;
	do
	{
		exam_menu();
		scanf("%d", &t);
		switch (t)
		{
		case 1:
			Exam_formal();//开始考试
			break;
		case 0:
			printf("已退出考试\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
		system("pause");
		system("cls");
	} while (t);
}