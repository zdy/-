#include"input.h"
//#include"login.h"
#include"PutQuestion.h"
#include"struct_q.h"
#include"test.h"
#include<iostream>
#include"Rand.h"
#include"jugde.h"
#include"RandOfQuesNum.h"
#include"struct_user.h"
#include"login_q.h"
#include"regis_q.h"
using namespace std;
/*void color(short x) //�Զ��庯���ݲ����ı���ɫ   
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ  
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //ֻ��һ���������ı�������ɫ   
	else//Ĭ�ϵ���ɫ��ɫ  
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}*/


void main()
{

	/*    */
	//color(2);
	/*    */
	int a;
	char b[50];//�����������������½�ɹ����û���,���ɴ�������õ��ļ������Ѱ���.txt
	char c[50];//���ɿ��Լ�¼���õ��ļ�������b������������||
	cout << "****************@**************" << endl;
	cout << "��ѡ���¼(����0)/ע��(����1):";
	cin >> a;
	while (a != 0 && a != 1) {
		cout << "�����˷Ƿ��ַ�;" << endl;
		cout << "����������:"; cin >> a;
	}
	//��ֹ������������
	if (a == 0)
		login(b);
	//ѡ���¼��ע��
	if (a == 1)
	{
		regis();
		login(b);
	}
	//ѡ��ע�Ტ�ҵ�¼
	strcpy(c, b);
	strcat(b, ".txt");
	strcat(c, "||.txt");




	int num_all=judge();//�������Ŀ����
	int test_num;//����������Ŀ
	RANK index;//�����ȡ���������
	int ch;//��¼ѡ��
	cout << "* * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t*\n*\t      ��лʹ�ñ�Ӧ�ã���  \t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t1.¼����Ŀ\t\t*\n*\t\t\t\t\t*\n*\t\t2.���в���\t\t*\n*\t\t\t\t\t*\n*\t\t0.��������\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * *\n\t\t��ǰ�������Ŀ����Ϊ��"<<num_all<<"\n\n\n\n�������Ӧ��Ž��в�����";
	while (cin>>ch&&ch!=0)
	{
		system("cls");
		switch (ch)
		{
		case 1:num_all=input();break;
		case 2:if (num_all == 0) while (cout << "�����δ¼����Ŀ���밴0����\n"&&cin >> ch&&ch != 0) system("cls"); 
			   else { cout << "����������Ҫ��ȡ��Ŀ����Ŀ\n";
			   while (cin >> test_num&&test_num > num_all)
			   {
				   system("cls");
				   cout << "������ĳ�ȡ���������󣬵�ǰ�����ȫ����Ŀ��Ϊ " << num_all << "\n����������\n";
			   }
			   index = RandQuesNum(num_all,test_num);
			   test(index.QuestionNum,test_num);
			   }
		default:
			break;
		}
		system("cls");
		cout << "* * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t*\n*\t      ��лʹ�ñ�Ӧ�ã���  \t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t1.¼����Ŀ\t\t*\n*\t\t\t\t\t*\n*\t\t2.���в���\t\t*\n*\t\t\t\t\t*\n*\t\t0.��������\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * *\n\t\t��ǰ�������Ŀ����Ϊ��" << num_all << "\n\n\n\n�������Ӧ��Ž��в�����";
              	}
	
}