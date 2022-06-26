#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//չʾ���ܲ˵�
void menu();
//¼��ѧ����Ϣ
void InputStudent();
//��ӡѧ����Ϣ
void PrintStuden();
//����ѧ����Ϣ
void SaveStudent();
//��ȡѧ����Ϣ
void ReadStudent();
//ͳ������ѧ������
int CountStudent();
//����ѧ����Ϣ
//Node* FindStudent();
//�޸�ѧ����Ϣ
void ModifyStudent();
//ɾ��ѧ����Ϣ
void DeletStudent();

typedef struct _Student {
	char name[20];	//����
	int age;		//����	
	int result;		//�ɼ�
}Student;

//�ڵ�
typedef struct _Node
{
	Student stu;	//ѧ��
	struct _Node* pNext;

}Node;

Node* pHead = NULL;			//ͷ�ڵ�

//չʾ���ܲ˵�
void menu()
{
	printf("*****************************************************************\n");
	printf("*\t\t��ӭʹ�ò�Уѧ���ɼ�����ϵͳV1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t��ѡ�����б�\t\t\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t1.¼��ѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t2.��ӡѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t3.����ѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t4.��ȡѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t5.ͳ������ѧ������\t\t\t*\n");
	printf("*\t\t\t6.����ѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t7.�޸�ѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t8.ɾ��ѧ����Ϣ\t\t\t\t*\n");
	printf("*\t\t\t0.�˳�ϵͳ\t\t\t\t*\n");
	printf("*****************************************************************\n");

	//�ȴ��ҵ��ַ���
	getchar();
}


//¼��ѧ����Ϣ
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


	printf("������ѧ������:\n");
	scanf_s("%s", pNewNode->stu.name, 20);
	printf("������ѧ������:\n");
	scanf_s("%d", &pNewNode->stu.age);
	printf("������ѧ���ɼ�:\n");
	scanf_s("%d", &pNewNode->stu.result);

	printf("ѧ����Ϣ¼��ɹ�.\n");
	system("pause");
	system("cls");

}

//��ӡѧ����Ϣ
void PrintStuden()
{
	system("cls");
	printf("*****************************************************************\n");
	printf("*\t\t��ӭʹ�ò�Уѧ���ɼ�����ϵͳV1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t����\t*\t����\t*\t�ɼ�\t\t\t*\n");

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

//����ѧ����Ϣ
void SaveStudent()
{
	//���ļ�
	FILE* fp = fopen("E:\\stuinfo.txt", "w");

	if (fp == NULL) {
		printf("���ļ�ʧ��.\n");
		return;
	}

	Node* p = pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}


	//�ر��ļ�
	fclose(fp);
	printf("\n���ݱ���ɹ���\n");
	system("pause");
	system("cls");
}

//��ȡѧ����Ϣ
void ReadStudent()
{
	FILE* fp = fopen("E:\\stuinfo.txt", "r");
	if (fp == NULL) {
		printf("���ļ�ʧ��.\n");
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
	printf("���ݼ��سɹ���\n");
	system("pause");
	system("cls");
}

//ͳ������ѧ������
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

//����ѧ����Ϣ
/*Node* FindStudent()
{
	char NameStudent[20];
	printf("������Ҫ���ҵ�ѧ������:\n");
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


//�޸�ѧ����Ϣ
void ModifyStudent()
{
	char NameStudent[20];
	printf("��������Ҫ�޸ĵ�ѧ������:\n");
	scanf_s("%s", NameStudent, 20);


	Node* p = pHead;
	while (p != NULL) {
		if (0 == strcmp(p->stu.name, NameStudent)) {
			printf("�������޸����������䣬�ɼ�:\n");
			scanf_s("%s", p->stu.name, 20);
			scanf_s("%d %d", &p->stu.age, &p->stu.result);
			printf("�޸ĳɹ�");
			break;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		printf("û���ҵ�ѧ����Ϣ.\n");
	}

	system("pause");
	system("cls");
}

//ɾ��ѧ����Ϣ
void DeletStudent()
{
	char NaStudent[20];
	printf("��������Ҫɾ����ѧ��������:\n");

	scanf_s("%s", NaStudent, 20);

	Node* p = pHead;
	Node* p1;
	Node* p2;
	//pHead->stu.name == NaStudent
	if (0 == strcmp(pHead->stu.name, NaStudent)) {
		p1 = pHead;
		pHead = pHead->pNext;
		printf("ɾ���ɹ���\n");
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
			printf("ɾ���ɹ���\n");
			free(p2);
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;
		if (p->pNext == NULL) {
			printf("û���ҵ���ѧ����ɾ������.\n");
			break;
		}
	}
	system("pause");
	system("cls");
}