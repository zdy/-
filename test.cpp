#include"test.h"
#include"PutQuestion.h"
#include"struct_q.h"
#include<iostream>
using namespace std;
void test(int index[], int question_num)
{
	int choose;//��¼�û�������Ϻ�ѡ��鿴�ɼ����Ƿ���������
	int correct_num = 0;//��ʼ����ȷ��Ŀ��
    //ture��¼ÿ�������ȷ��,anwser��¼�û������
	char ture;
	int judge;//
	char anwser;
	
	//������
	
	
	for (int i = 0; i < question_num; i++)//��ʼ���⣬�������������������Ŀ������question_num)
	{
		system("cls");
		cout << "��������������������������������ǰ�� " << i + 1 << " / " << question_num << " ����\n\n\n";//��ʾ�û���ǰ�ڼ���
		ture=PutQuestion(index[i]);//�����ɣ���¼��ȷѡ��
		
		//�ж��û��Ƿ������ʽ��ȷ
		cin >> anwser;
		while (anwser<'A' || anwser>'D'&&anwser<'a' || anwser>'d')
		{
			system("cls");
			cout << "��������ȷ�ĸ�ʽ������\n\n";
			cout << "��������������������������������ǰ�� " << i + 1 << " / " << question_num << " ����\n\n\n";//��ʾ�û���ǰ�ڼ���
			ture = PutQuestion(index[i]);//�����ɣ���¼��ȷѡ��
			cin >> anwser;
		}
		if (anwser > 90)
			anwser -= 32;
		//�ж��û����Ƿ���ȷ
		if (ture == anwser)
		{
			correct_num++;
			cout << "\n\n�ش���ȷ����\n\n(/�R���Q)/~�ةغ�������~~����������Ŷ~~\n\n\n������1����:\n";
			while (cin >> judge&&judge != 1);
		}
		else {
			cout << "\n\n�𰸴��󣡣�\n\n   o(T��To)���ź���~��Ҫ���٣���������Ŷ�����A( �� ������ )\n\n��ȷ��Ϊ�� " << ture << endl << "\n\n������1����\n";
			while (cin >> judge&&judge != 1);
		}
	}
	
	
	
	
	
	
	//�������
	
	system("cls");//���ҳ��
	printf("\t\t��ϲ�������������~~������\n\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t\t\t*\n*\t\t�����β��Ե���ȷ��Ϊ�� %.2f\t\t*\n*\t\t\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n\n����0���������棺", correct_num*1.0 / question_num);
	cin >> choose;
	while (choose != 0)
	{
		system("cls");//���ҳ��
		printf("\t\t��ϲ�������������~~������\n\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t\t\t*\n*\t\t�����β��Ե���ȷ��Ϊ�� %.2f\t\t*\n*\t\t\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n\n����0���������棺", correct_num*1.0 / question_num);
		cin >> choose;
	}
	system("cls");//���ҳ��
}