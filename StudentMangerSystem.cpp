#include "FunctionStudent.h"

int main()
{

	while (true)
	{
		menu();

		char ch = _getch();

		switch (ch) {
		case '1'://¼��ѧ����Ϣ
			InputStudent();
			break;
		case '2'://��ӡѧ����Ϣ
			PrintStuden();
			break;
		case '3'://����ѧ����Ϣ
			SaveStudent();
			break;
		case '4'://��ȡѧ����Ϣ
			ReadStudent();
			break;
		case '5'://ͳ������ѧ������
			printf("ѧ����������%d��\n", CountStudent());
			system("pause");
			system("cls");
			break;
		case '6'://����ѧ����Ϣ
		{
			/*Node* p = FindStudent();
			if (p != NULL) {
				printf("����: %s\t����: %d\t�ɼ�: %d\t\n", p->stu.name, p->stu.age, p->stu.result);
			}
			else {
				printf("û���ҵ���ѧ��\n");
			}*/
			system("pause");
			system("cls");
			break;
		}
		case '7'://�޸�ѧ����Ϣ
			ModifyStudent();
			break;
		case '8'://ɾ��ѧ����Ϣ
			DeletStudent();
			break;
		case '0'://�˳�ϵͳ
			printf("��ͬѧ�Ĺ���ϵͳ������ô��(=^��^=)���´μ���ʹ��(*^��^*)Bye~\n\n\n\n\n");
			return 0;
		default:
			printf("����������������������.\n");
			system("pause");
			system("cls");
			break;
		}
	}
	free(InputStudent);

	return 0;
}