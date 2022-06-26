#include "FunctionStudent.h"

int main()
{

	while (true)
	{
		menu();

		char ch = _getch();

		switch (ch) {
		case '1'://录入学生信息
			InputStudent();
			break;
		case '2'://打印学生信息
			PrintStuden();
			break;
		case '3'://保存学生信息
			SaveStudent();
			break;
		case '4'://读取学生信息
			ReadStudent();
			break;
		case '5'://统计所有学生人数
			printf("学生总人数：%d人\n", CountStudent());
			system("pause");
			system("cls");
			break;
		case '6'://查找学生信息
		{
			/*Node* p = FindStudent();
			if (p != NULL) {
				printf("姓名: %s\t年龄: %d\t成绩: %d\t\n", p->stu.name, p->stu.age, p->stu.result);
			}
			else {
				printf("没有找到该学生\n");
			}*/
			system("pause");
			system("cls");
			break;
		}
		case '7'://修改学生信息
			ModifyStudent();
			break;
		case '8'://删除学生信息
			DeletStudent();
			break;
		case '0'://退出系统
			printf("陶同学的管理系统做的这么好(=^▽^=)！下次继续使用(*^ω^*)Bye~\n\n\n\n\n");
			return 0;
		default:
			printf("您的输入有误，请重新输入.\n");
			system("pause");
			system("cls");
			break;
		}
	}
	free(InputStudent);

	return 0;
}