#define _CRT_SECURE_NO_WARNINGS

#include"tools.h"



void main_project()
{
	int m = 10;
	do
	{
		menu();
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			Item_bank();//试题库管理
			break;
		case 2:
			Exam_time();//在线测试
			break;
		case 3:
			find_score();//查看历史成绩
			break;
		case 4:
			Read_id();//查看用户信息
			break;
		case 0:
			printf("退出思政知识学习测试系统\n");
			break;
		default:
			printf("< 选择错误！！! >");
			break;

		}
		system("pause");
		system("cls");
	} while (m);

}

void main_student()
{
	int choice_project = 11;
	do
	{
		Students_menu();
		printf("请选择功能：");
		scanf("%d", &choice_project);

		switch (choice_project)
		{
		case 1:
			Exam_time();//在线测试
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
	} while (choice_project);
}



int main()
{
	int select = 10;
	do
	{
		enter_menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			enter();//登录
			break;
		case 2:
			Enroll();//注册
			break;
		case 0:
			break;
		default:
			printf("输入格式错误，请重新输入\n");
			break;
		}
		system("pause");
		system("cls");
	} while (select);
}