#define _CRT_SECURE_NO_WARNINGS

#include "tools.h"


struct account_number
{
	long long ID;
	char name[21];
};

int regtister(long long account)//账号分析
{
	if (account == 24368464)
	{
		int user;
		user = 1;
		return user;
	}
	else
	{
		struct account_number id_number;
		FILE* fp = fopen("account_ID.dat", "r");
		int num;
		long offset;
		if (NULL == fp)
		{
			printf("文件打开失败\n");
			getch();
			exit(1);
		}

		int i;
		for (i = 0;i < 100;i++)
		{
			fread(&id_number, sizeof(struct account_number), 1, fp);
			if (id_number.ID == account)
			{
				printf("欢迎%s同学回来\n", id_number.name);
				return 2;
				break;
				if (i == 99)
				{
					printf("登录失败！\n");
					printf("<请检查您的ID是否输入错误>\n");
				}
			}
		}
		fclose(fp);
	}
}

void Enroll()//注册
{
	struct account_number account = {0};
	FILE* fp = fopen("account_ID.dat", "a");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		getch();
		exit(-1);
	}
	
	printf("请输入：\nID	用户名\n");
	scanf("%lld %s", &account.ID,account.name);
	fwrite(&account, sizeof(struct account_number), 1, fp);
	fclose(fp);
}


void Read_id()//查看用户
{
	struct account_number lookuser[30] = { 0 };
	FILE* fp = fopen("account_ID.dat", "r");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		getch();
		exit(-1);
	}
	int k = 0;
	printf("ID\t用户名\n");
	for(k=0;k<30;k++)
	{
		fread(&lookuser[k], sizeof(struct account_number), 1, fp);
		printf("%lld %s", lookuser[k].ID, lookuser[k].name);
		printf("\n");
	}
	
	fclose(fp);
}






struct simple_choice//单选结构体
{
	int simple_number;//题号
	char simple_answer;//答案
	char simple_topic[1024];//题目
	//char simple_grop[1024];//选项
	char simpleA[1024];
	char simpleB[1024];
	char simpleC[1024];
	char simpleD[1024];
};



void Write_simple()//录入单选
{
	
	
	struct simple_choice project1[100];
	FILE* fp = fopen("simple_exam.dat", "a");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		getch();
		exit(-1);
	}
	printf("File opened successfully\n");
	int num = 0;
	printf("请输入新增题数>");
	scanf("%d", &num);
	printf("*****************************************************\n");
	printf("*    正确答案请录入大写的“A”“B”“C”“D”       *\n");
	printf("*****************************************************\n");
	printf("￥*录入顺序：题号 答案 题 选项A-B-C-D*￥\n");
	int i;
	printf("请录入题目：\n");
	for (i = 0;i < num;i++)
	{
		scanf("%d %c %s", &project1[i].simple_number, &project1[i].simple_answer, project1[i].simple_topic);
		scanf("%s %s %s %s", project1[i].simpleA, project1[i].simpleB, project1[i].simpleC, project1[i].simpleD);
		fwrite(&project1[i], sizeof(struct simple_choice), 1, fp);
	}
	
	fclose(fp);
}

void Findsimple()//查看单选
{
	struct simple_choice find_project1[100] = {0};
	FILE* fp = fopen("simple_exam.dat", "r");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		getch();
		exit(1);
	}
	printf("File opened successfully\n");
	int i;
	
	for (i = 0;i < 31;i++)
	{
		fread(&find_project1[i], sizeof(struct simple_choice), 1, fp);
		printf("%d %c\n", find_project1[i].simple_number, find_project1[i].simple_answer);
		printf("%s\n", find_project1[i].simple_topic);
		printf("%s\n%s\n%s\n%s\n", find_project1[i].simpleA, find_project1[i].simpleB, find_project1[i].simpleC, find_project1[i].simpleD);
		printf("\n");
	}
	
	fclose(fp);
}


void Change_simple()//更改单选
{
	struct simple_choice Change_project1;
	FILE* fp = fopen("simple_exam.dat", "r+");
	int num;
	long offset;
	if (NULL == fp)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	printf("请输入所要修改的题目所居位置编号：");
	scanf("%d", &num);
	offset = (num - 1) * sizeof(struct simple_choice);
	rewind(fp);
	if (fseek(fp, offset, SEEK_SET) != 0)
	{
		printf("\nCan't move there!\n");
		exit(1);
	}
	fread(&Change_project1, sizeof(struct simple_choice), 1, fp);
	printf("%d %c\n", Change_project1.simple_number, Change_project1.simple_answer);
	printf("%s\n", Change_project1.simple_topic);
	printf("%s\n%s\n%s\n%s\n", Change_project1.simpleA, Change_project1.simpleB, Change_project1.simpleC, Change_project1.simpleD);
	printf("\n");
	fseek(fp, offset, SEEK_SET);
	printf("请输入新的题目\n");
	scanf("%d %c %s", &Change_project1.simple_number, &Change_project1.simple_answer, Change_project1.simple_topic);
	scanf("%s %s %s %s", Change_project1.simpleA, Change_project1.simpleB, Change_project1.simpleC, Change_project1.simpleD);
	fwrite(&Change_project1, sizeof(struct simple_choice), 1, fp);
	fflush(fp);
	fclose(fp);
}



void Delite_simple()//删除单选题
{
	FILE* file;
	struct simple_choice* simple;
	int numPeople = 0;
	int i, j;
	int targetId;
	int found = 0;

	// 打开文件
	file = fopen("simple_exam.dat", "r+");
	if (file == NULL) 
	{
		printf("Error opening file");
		getch();
		exit(1);
	}

	// 先统计文件中结构体的数量
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	numPeople = fileSize / sizeof(struct simple_choice);
	rewind(file);

	// 分配内存存储结构体
	simple = (struct simple_choice*)malloc(numPeople * sizeof(struct simple_choice));
	if (simple == NULL) {
		perror("Error allocating memory");
		fclose(file);
		return 1;
	}

	// 读取文件内容
	fread(simple, sizeof(struct simple_choice), numPeople, file);

	// 输入要删除的结构体的 id
	printf("请输入所要删除员工工号: ");
	scanf("%d", &targetId);

	// 查找要删除的结构体
	for (i = 0; i < numPeople; i++)
	{
		if (simple[i].simple_number == targetId)
		{
			printf("%d %c\n", simple[i].simple_number, simple[i].simple_answer);
			printf("%s\n", simple[i].simple_topic);
			printf("%s\n%s\n%s\n%s\n", simple[i].simpleA, simple[i].simpleB, simple[i].simpleC, simple[i].simpleD);
			printf("\n");
			found = 1;
			// 从数组中删除该结构体，将后面的元素向前移动
			for (j = i; j < numPeople - 1; j++)
			{
				simple[j] = simple[j + 1];
			}
			numPeople--;
			break;
		}
	}

	if (!found)
	{
		printf("Person with id %d not found.\n", targetId);
	}
	else
	{
		// 将文件指针移动到文件开始位置
		fseek(file, 0, SEEK_SET);
		// 将修改后的结构体数组写回文件
		fwrite(simple, sizeof(struct simple_choice), numPeople, file);
		// 调整文件大小
		fseek(file, numPeople * sizeof(struct simple_choice), SEEK_SET);
		fwrite("", 1, 0, file);
	}

	// 释放内存
	free(simple);
	// 关闭文件
	fclose(file);

	return 0;
}






struct multiple_choice//多选结构体
{
	int multiple_number;//题号
	char multiple_answer[21];//答案
	char multiple_topic[1024];//题目
	//选项
	char multipleA[1024];
	char multipleB[1024];
	char multipleC[1024];
	char multipleD[1024];
};

void Write_multiple()//录入多选
{


	struct multiple_choice project2[100];
	FILE* fp = fopen("multiple_exam.dat", "a");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		getch();
		exit(-1);
	}
	printf("File opened successfully\n");
	int num = 0;
	printf("请输入新增题数>");
	scanf("%d", &num);
	printf("*****************************************************\n");
	printf("*    正确答案请录入大写的“A”“B”“C”“D”       *\n");
	printf("*****************************************************\n");
	printf("￥*录入顺序：题号 答案 题 选项A-B-C-D*￥\n");
	int i;
	printf("请录入题目：\n");
	for (i = 0;i < num;i++)
	{
		scanf("%d %s %s", &project2[i].multiple_number, project2[i].multiple_answer, project2[i].multiple_topic);
		scanf("%s %s %s %s", project2[i].multipleA, project2[i].multipleB, project2[i].multipleC, project2[i].multipleD);
		fwrite(&project2[i], sizeof(struct multiple_choice), 1, fp);
	}

	fclose(fp);
}

void Findmultiple()//查看多选
{
	struct multiple_choice find_project2[100] = { 0 };
	
	FILE* fp = fopen("multiple_exam.dat", "r");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		_getch();
		exit(-1);
	}
	printf("File opened successfully\n");
	int i;

	for (i = 0;i < 31;i++)
	{
		fread(&find_project2[i], sizeof(struct multiple_choice), 1, fp);
		printf("%d %s\n", find_project2[i].multiple_number, find_project2[i].multiple_answer);
		printf("%s\n", find_project2[i].multiple_topic);
		printf("%s\n%s\n%s\n%s\n", find_project2[i].multipleA, find_project2[i].multipleB, find_project2[i].multipleC, find_project2[i].multipleD);
		printf("\n");
	}

	fclose(fp);
}

void Change_multiple()//更改多选
{
	struct multiple_choice Change_project2;
	FILE* fp = fopen("multiple_exam.dat", "r+");
	int num;
	long offset;
	if (NULL == fp)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	printf("请输入所要修改的题目所居位置编号：");
	scanf("%d", &num);
	offset = (num - 1) * sizeof(struct multiple_choice);
	rewind(fp);
	if (fseek(fp, offset, SEEK_SET) != 0)
	{
		printf("\nCan't move there!\n");
		exit(1);
	}
	fread(&Change_project2, sizeof(struct multiple_choice), 1, fp);
	printf("%d %s\n", Change_project2.multiple_number, Change_project2.multiple_answer);
	printf("%s\n", Change_project2.multiple_topic);
	printf("%s\n%s\n%s\n%s\n", Change_project2.multipleA, Change_project2.multipleB, Change_project2.multipleC, Change_project2.multipleD);
	printf("\n");
	fseek(fp, offset, SEEK_SET);
	printf("请输入新的题目\n");
	scanf("%d %s %s", &Change_project2.multiple_number, &Change_project2.multiple_answer, Change_project2.multiple_topic);
	scanf("%s %s %s %s", Change_project2.multipleA, Change_project2.multipleB, Change_project2.multipleC, Change_project2.multipleD);
	fwrite(&Change_project2, sizeof(struct multiple_choice), 1, fp);
	fflush(fp);
	fclose(fp);
}



void Delite_multiple()
{
	FILE* file;
	struct multiple_choice* multiple;
	int numPeople = 0;
	int i, j;
	int targetId;
	int found = 0;

	// 打开文件
	file = fopen("multiple_exam.dat", "r+");
	if (file == NULL)
	{
		printf("Error opening file");
		getch();
		exit(1);
	}

	// 先统计文件中结构体的数量
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	numPeople = fileSize / sizeof(struct multiple_choice);
	rewind(file);

	// 分配内存存储结构体
	multiple = (struct multiple_choice*)malloc(numPeople * sizeof(struct multiple_choice));
	if (multiple == NULL) {
		perror("Error allocating memory");
		fclose(file);
		return 1;
	}

	// 读取文件内容
	fread(multiple, sizeof(struct multiple_choice), numPeople, file);

	// 输入要删除的结构体的 id
	printf("请输入所要删除员工工号: ");
	scanf("%d", &targetId);

	// 查找要删除的结构体
	for (i = 0; i < numPeople; i++)
	{
		if (multiple[i].multiple_number == targetId)
		{
			printf("%d %s\n", multiple[i].multiple_number, multiple[i].multiple_answer);
			printf("%s\n", multiple[i].multiple_topic);
			printf("%s\n%s\n%s\n%s\n", multiple[i].multipleA, multiple[i].multipleB, multiple[i].multipleC, multiple[i].multipleD);
			printf("\n");
			found = 1;
			// 从数组中删除该结构体，将后面的元素向前移动
			for (j = i; j < numPeople - 1; j++)
			{
				multiple[j] = multiple[j + 1];
			}
			numPeople--;
			break;
		}
	}

	if (!found)
	{
		printf("Person with id %d not found.\n", targetId);
	}
	else
	{
		// 将文件指针移动到文件开始位置
		fseek(file, 0, SEEK_SET);
		// 将修改后的结构体数组写回文件
		fwrite(multiple, sizeof(struct multiple_choice), numPeople, file);
		// 调整文件大小
		fseek(file, numPeople * sizeof(struct multiple_choice), SEEK_SET);
		fwrite("", 1, 0, file);
	}

	// 释放内存
	free(multiple);
	// 关闭文件
	fclose(file);

	return 0;
}
















struct Judge
{
	int number;
	char judge_answer;
	char judge_topic[1024];
};

void Write_judge()//录入判断
{
	struct Judge questions[100];
	FILE* fp;
	fp = fopen("judge_exam.dat", "a");
	if (NULL == fp)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	printf("File opened successfully\n");
	int num = 0;
	printf("请输入新增题数>");
	scanf("%d", &num);
	printf("*****************************************************\n");
	printf("*    正确答案请录入大写的“F”(错)、“T”（对）      *\n");
	printf("*****************************************************\n");
	printf("￥*录入顺序：题号 答案 题目*￥\n");
	int i;
	printf("请录入题目：\n");
	for (i = 0;i < num;i++)
	{
		scanf("%d %c %s",&questions[i].number, &questions[i].judge_answer, questions[i].judge_topic);
		fwrite(&questions[i], sizeof(struct Judge), 1, fp);
	}

	fclose(fp);
}

void Read_judge()//查看判断
{
	struct Judge read_judge[100] = {0};
	FILE* fp;
	fp = fopen("judge_exam.dat", "r");
	if (NULL == fp)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	printf("File opened successfully\n");
	int i;

	for (i = 0;i < 31;i++)
	{
		fread(&read_judge[i], sizeof(struct Judge), 1, fp);
		printf("%d\t%c\t", read_judge[i].number, read_judge[i].judge_answer);
		printf("%s\n", read_judge[i].judge_topic);
		printf("\n");
	}

	fclose(fp);
}

void Change_judge()//更改判断
{
	struct Judge change_topic;
	FILE* fp;
	fp = fopen("judge_exam.dat", "r+");
	
	int num;
	long offset;
	if (NULL == fp)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	printf("请输入所要修改的题目所居位置编号：");
	scanf("%d", &num);
	offset = (num - 1) * sizeof(struct Judge);
	rewind(fp);
	if (fseek(fp, offset, SEEK_SET) != 0)
	{
		printf("\nCan't move there!\n");
		exit(1);
	}
	fread(&change_topic, sizeof(struct Judge), 1, fp);
	printf("%d\t%c\t", change_topic.number, change_topic.judge_answer);
	printf("%s\n", change_topic.judge_topic);
	printf("\n");;
	fseek(fp, offset, SEEK_SET);
	printf("请输入新的题目\n");
	scanf("%d %c %s", &change_topic.number, &change_topic.judge_answer, change_topic.judge_topic);
	fwrite(&change_topic, sizeof(struct Judge), 1, fp);
	fflush(fp);
	fclose(fp);
}



void Delite_judge()//删除判断
{
	FILE* file;
	struct Judge* judge;
	int numPeople = 0;
	int i, j;
	int targetId;
	int found = 0;

	// 打开文件
	file = fopen("judge_exam.dat", "r+");
	if (file == NULL)
	{
		printf("Error opening file");
		getch();
		exit(1);
	}

	// 先统计文件中结构体的数量
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	numPeople = fileSize / sizeof(struct Judge);
	rewind(file);

	// 分配内存存储结构体
	judge = (struct Judge*)malloc(numPeople * sizeof(struct Judge));
	if (judge == NULL) {
		perror("Error allocating memory");
		fclose(file);
		return 1;
	}

	// 读取文件内容
	fread(judge, sizeof(struct Judge), numPeople, file);

	// 输入要删除的结构体的 id
	printf("请输入所要删除员工工号: ");
	scanf("%d", &targetId);

	// 查找要删除的结构体
	for (i = 0; i < numPeople; i++)
	{
		if (judge[i].number == targetId)
		{
			printf("%d\t%c\t", judge[i].number, judge[i].judge_answer);
			printf("%s\n", judge[i].judge_topic);
			printf("\n");
			found = 1;
			// 从数组中删除该结构体，将后面的元素向前移动
			for (j = i; j < numPeople - 1; j++)
			{
				judge[j] = judge[j + 1];
			}
			numPeople--;
			break;
		}
	}

	if (!found)
	{
		printf("Person with id %d not found.\n", targetId);
	}
	else
	{
		// 将文件指针移动到文件开始位置
		fseek(file, 0, SEEK_SET);
		// 将修改后的结构体数组写回文件
		fwrite(judge, sizeof(struct Judge), numPeople, file);
		// 调整文件大小
		fseek(file, numPeople * sizeof(struct Judge), SEEK_SET);
		fwrite("", 1, 0, file);
	}

	// 释放内存
	free(judge);
	// 关闭文件
	fclose(file);

	return 0;
}










struct Score
{
	int simple_grade;
	int multiple_grade;
	int judge_grade;
	int all_grade;
};


// 检查随机数是否已经生成过
int isGenerated(int num, int* arr, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] == num) 
		{
			return 1;
		}
	}
	return 0;
}


void Exam_formal()
{
	int score = 0;
	int score1 = 0;
	FILE* fp1;
	struct simple_choice answer_simple;
	int count1;
	int randomNums1[5];
	int i, j, randNum1;
	
	// 打开文件
	if ((fp1 = fopen("simple_exam.dat", "r")) == NULL) 
	{
		printf("\n打开文件失败！\n");
		exit(1);
	}

	// 获取文件大小和结构体数量
	fseek(fp1, 0, SEEK_END);
	long fileSize1 = ftell(fp1);
	count1 = fileSize1 / sizeof(struct simple_choice);
	fseek(fp1, 0, SEEK_SET);

	// 初始化随机数种子
	srand(time(NULL));

	// 生成 5 个不重复的随机数
	for (i = 0; i < 5; i++) 
	{
		do 
		{
			randNum1 = rand() % count1;
		} while (isGenerated(randNum1, randomNums1, i));
		randomNums1[i] = randNum1;
	}

	// 读取并打印随机抽取的结构体信息

	printf("*****************************************************\n");
	printf("*    请在正确的地方填入大写的“A”“B”“C”“D”  * \n");
	printf("*****************************************************\n");
	for (i = 0; i < 5; i++) 
	{
		fseek(fp1, randomNums1[i] * sizeof(struct simple_choice), SEEK_SET);
		fread(&answer_simple, sizeof(struct simple_choice), 1, fp1);
		printf("%c\n", answer_simple.simple_answer);
		printf("%s\n", answer_simple.simple_topic);
		printf("%s\n%s\n%s\n%s\n", answer_simple.simpleA, answer_simple.simpleB, answer_simple.simpleC, answer_simple.simpleD);
		char x;
		printf("请输入你的答案>");
		getchar();
		scanf("%c", &x);
		if (answer_simple.simple_answer == x)
		{
			printf("答案正确\n");
			score+=2;
			score1+=2;
		}
		else
		{
			printf("答案错误\n");
		}
		printf("\n");
	}
	printf("simple score:>%d\n", score1);
	fclose(fp1);
	//单选--------------------------------------------------------


	int score2 = 0;
	FILE* fp2;
	struct multiple_choice answer_multiple;
	int count2;
	int randomNums2[5];
	int randNum2;
	
	// 打开文件
	if ((fp2 = fopen("multiple_exam.dat", "r")) == NULL)
	{
		printf("\n打开文件失败！\n");
		exit(1);
	}

	// 获取文件大小和结构体数量
	fseek(fp2, 0, SEEK_END);
	long fileSize2 = ftell(fp2);
	count2 = fileSize2 / sizeof(struct multiple_choice);
	fseek(fp2, 0, SEEK_SET);

	// 初始化随机数种子
	srand(time(NULL));

	// 生成 5 个不重复的随机数
	for (i = 0; i < 5; i++)
	{
		do
		{
			randNum2 = rand() % count2;
		} while (isGenerated(randNum2, randomNums2, i));
		randomNums2[i] = randNum2;
	}
	// 读取并打印随机抽取的结构体信息

	printf("*****************************************************\n");
	printf("*    请在正确的地方填入大写的“A”“B”“C”“D”  * \n");
	printf("*****************************************************\n");
	for (i = 0; i < 5; i++)
	{
		fseek(fp2, randomNums2[i] * sizeof(struct multiple_choice), SEEK_SET);
		fread(&answer_multiple, sizeof(struct multiple_choice), 1, fp2);
		printf("%s\n", answer_multiple.multiple_answer);
		printf("%s\n", answer_multiple.multiple_topic);
		printf("%s\n%s\n%s\n%s\n", answer_multiple.multipleA, answer_multiple.multipleB, answer_multiple.multipleC, answer_multiple.multipleD);
		printf("请输入你的答案>");
		getchar();
		char answer_y[3];
		fgets(answer_y, sizeof(answer_y), stdin);
		/*scanf("%3s", answer_y);*///不安全
		int p = 0;
		for(p=0;p<3;p++)
		{
			if (answer_multiple.multiple_answer[p] == answer_y[p])
			{
				score2 += 1;
				score += 1;
			}
			
			else
			{
				printf("答案错误\n");
				break;
				
			}
		}
		printf("答案正确\n");
		printf("\n");
	}
	printf("multiple score:>%d\n", score2);
	fclose(fp2);
	//多选--------------------------------------------------

	int score3 = 0;
	FILE* fp3;
	struct Judge answer_judge;
	int count3;
	int randomNums3[5];
	int randNum3;
	
	// 打开文件
	if ((fp3 = fopen("judge_exam.dat", "r")) == NULL)
	{
		printf("\n打开文件失败！\n");
		exit(1);
	}

	// 获取文件大小和结构体数量
	fseek(fp3, 0, SEEK_END);
	long fileSize3 = ftell(fp3);
	count3 = fileSize3 / sizeof(struct Judge);
	fseek(fp3, 0, SEEK_SET);

	// 初始化随机数种子
	srand(time(NULL));

	// 生成 5 个不重复的随机数
	for (i = 0; i < 5; i++)
	{
		do
		{
			randNum3 = rand() % count3;
		} while (isGenerated(randNum3, randomNums3, i));
		randomNums3[i] = randNum3;
	}
	// 读取并打印随机抽取的结构体信息

	printf("*****************************************************\n");
	printf("*     !!!注意：正确请回答“T”、错误回答“F”!!!    * \n");
	printf("*****************************************************\n");
	for (i = 0; i < 5; i++)
	{
		fseek(fp3, randomNums3[i] * sizeof(struct Judge), SEEK_SET);
		fread(&answer_judge, sizeof(struct Judge), 1, fp3);
		printf("%c\t", answer_judge.judge_answer);
		printf("%s\n", answer_judge.judge_topic);
		printf("\n");
		char answerJudge;
		printf("请输入你的答案>");
		getchar();
		scanf("%s", &answerJudge);
		if (answer_judge.judge_answer == answerJudge)
		{
			printf("答案正确\n");
			score+=2;
			score3+=2;
		}
		else
		{
			printf("答案错误\n");
		}
		printf("\n");
	}
	printf("judge score:>%d\n", score3);
	printf("Finally score:>%d\n", score);
	fclose(fp3);
	//判断-------------------------------------------------------
	printf("正在录入成绩\n");
	struct Score muchscore = { 0 };
	FILE* fi = fopen("finally_score.dat", "a");
	if (fi == NULL)
	{
		printf("打开文件失败\n");
		getch();
		exit(1);
	}
	printf("成功打开成绩录入dat文件\n");
	muchscore.simple_grade = score1;
	muchscore.multiple_grade = score2;
	muchscore.judge_grade = score3;
	muchscore.all_grade = score;
	printf("单选题得分：%d\n", muchscore.simple_grade);
	printf("多选题得分：%d\n", muchscore.multiple_grade);
	printf("判断题得分：%d\n", muchscore.judge_grade);
	printf("总得分：%d\n", muchscore.all_grade);
	fwrite(&muchscore, sizeof(struct Score), 1, fi);
	fclose(fi);
}


void find_score()//查看历史成绩
{
	struct Score find_score[100] = { 0 };

	FILE* fp = fopen("finally_score.dat", "r");
	if (NULL == fp)
	{
		printf("File opening failure!\n");
		_getch();
		exit(-1);
	}
	printf("File opened successfully\n");
	int i;
	printf("单选成绩	多选成绩	判断题成绩	总成绩\n");
	for (i = 0;i < 31;i++)
	{
		fread(&find_score[i], sizeof(struct Score), 1, fp);
		printf("%d\t	%d\t	%d\t	%d\n",find_score[i].simple_grade, find_score[i].multiple_grade, find_score[i].judge_grade, find_score[i].all_grade);
		printf("\n");
	}

	fclose(fp);
}