#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//展示功能菜单
void menu();
//录入学生信息
void InputStudent();
//打印学生信息
void PrintStuden();
//保存学生信息
void SaveStudent();
//读取学生信息
void ReadStudent();
//统计所有学生人数
int CountStudent();
//查找学生信息
//Node* FindStudent();
//修改学生信息
void ModifyStudent();
//删除学生信息
void DeletStudent();

typedef struct _Student {
	char name[20];	//姓名
	int age;		//年龄	
	int result;		//成绩
}Student;

//节点
typedef struct _Node
{
	Student stu;	//学生
	struct _Node* pNext;

}Node;

Node* pHead = NULL;			//头节点

//展示功能菜单
void menu()
{
	printf("*****************************************************************\n");
	printf("*\t\t欢迎使用财校学生成绩管理系统V1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t请选择功能列表\t\t\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t1.录入学生信息\t\t\t\t*\n");
	printf("*\t\t\t2.打印学生信息\t\t\t\t*\n");
	printf("*\t\t\t3.保存学生信息\t\t\t\t*\n");
	printf("*\t\t\t4.读取学生信息\t\t\t\t*\n");
	printf("*\t\t\t5.统计所有学生人数\t\t\t*\n");
	printf("*\t\t\t6.查找学生信息\t\t\t\t*\n");
	printf("*\t\t\t7.修改学生信息\t\t\t\t*\n");
	printf("*\t\t\t8.删除学生信息\t\t\t\t*\n");
	printf("*\t\t\t0.退出系统\t\t\t\t*\n");
	printf("*****************************************************************\n");

	//等待我的字符！
	getchar();
}


//录入学生信息
void InputStudent()
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	if (pHead == NULL) {
		pHead = pNewNode;
	}
	else {
		pNewNode->pNext = pHead;
		pHead = pNewNode;
	}


	printf("请输入学生姓名:\n");
	scanf_s("%s", pNewNode->stu.name, 20);
	printf("请输入学生年龄:\n");
	scanf_s("%d", &pNewNode->stu.age);
	printf("请输入学生成绩:\n");
	scanf_s("%d", &pNewNode->stu.result);

	printf("学生信息录入成功.\n");
	system("pause");
	system("cls");

}

//打印学生信息
void PrintStuden()
{
	system("cls");
	printf("*****************************************************************\n");
	printf("*\t\t欢迎使用财校学生成绩管理系统V1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t姓名\t*\t年龄\t*\t成绩\t\t\t*\n");

	Node* p = pHead;
	while (p != NULL)
	{
		printf("*\t%s\t*\t%d\t*\t%d\t\t\t*\n",
			p->stu.name,
			p->stu.age,
			p->stu.result);

		p = p->pNext;
	}
	printf("*****************************************************************\n");
	system("pause");
	system("cls");
}

//保存学生信息
void SaveStudent()
{
	//打开文件
	FILE* fp = fopen("E:\\stuinfo.txt", "w");

	if (fp == NULL) {
		printf("打开文件失败.\n");
		return;
	}

	Node* p = pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}


	//关闭文件
	fclose(fp);
	printf("\n数据保存成功！\n");
	system("pause");
	system("cls");
}

//读取学生信息
void ReadStudent()
{
	FILE* fp = fopen("E:\\stuinfo.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败.\n");
		return;
	}

	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp)) {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student));

		if (pHead == NULL) {
			pHead = pNewNode;
		}
		else {
			pNewNode->pNext = pHead;
			pHead = pNewNode;
		}
	}

	fclose(fp);
	printf("数据加载成功！\n");
	system("pause");
	system("cls");
}

//统计所有学生人数
int CountStudent()
{
	int count = 0;

	Node* p = pHead;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}

	return count;
}

//查找学生信息
/*Node* FindStudent()
{
	char NameStudent[20];
	printf("请输入要查找的学生姓名:\n");
	scanf_s("%s",NameStudent);

	Node* p = pHead;
	while (p != NULL) {
		if (0 == strcmp(p->stu.name,NameStudent) {
			return p;
		}
		p = p->pNext;
	}

	return NULL;
}*/


//修改学生信息
void ModifyStudent()
{
	char NameStudent[20];
	printf("请输入需要修改的学生姓名:\n");
	scanf_s("%s", NameStudent, 20);


	Node* p = pHead;
	while (p != NULL) {
		if (0 == strcmp(p->stu.name, NameStudent)) {
			printf("请输入修改姓名，年龄，成绩:\n");
			scanf_s("%s", p->stu.name, 20);
			scanf_s("%d %d", &p->stu.age, &p->stu.result);
			printf("修改成功");
			break;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		printf("没有找到学生信息.\n");
	}

	system("pause");
	system("cls");
}

//删除学生信息
void DeletStudent()
{
	char NaStudent[20];
	printf("请输入需要删除的学生的姓名:\n");

	scanf_s("%s", NaStudent, 20);

	Node* p = pHead;
	Node* p1;
	Node* p2;
	//pHead->stu.name == NaStudent
	if (0 == strcmp(pHead->stu.name, NaStudent)) {
		p1 = pHead;
		pHead = pHead->pNext;
		printf("删除成功！\n");
		free(p1);
		system("pause");
		system("cls");
		return;
	}


	while (p->pNext != NULL) {
		//p->pNext->stu.name == NaStudent
		if (0 == strcmp(p->pNext->stu.name, NaStudent)) {
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			printf("删除成功！\n");
			free(p2);
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;
		if (p->pNext == NULL) {
			printf("没有找到该学生，删除错误.\n");
			break;
		}
	}
	system("pause");
	system("cls");
}