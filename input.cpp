#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"input.h"
#include"struct_q.h"
using namespace std;
#define M 2000
#define N 200
#define size sizeof(struct question)
#define SEEK_END 2
int input()//¼����Ŀ
{
	int n;
	FILE *fp;
	int m = 0;
	struct question data;
	fp = fopen("database.txt", "a");
	if (fp == NULL)
	{
		return 0;
	}
	fseek(fp, 0, SEEK_END);
	m = ftell(fp) / size;//ftell��fp���ļ���ͷ���ļ�ָ������λ�����ƶ����ֽ���
	for (int i = 0;;++i)
	{
		data.num = ++m;
		printf("* * * * * * * * * * * * * * ��ǰ������%d�� * * * * * * * * * * * * * *\n\n\n", i);
		cout<<"��������Ŀ���(ֹͣ������false):";//�������
		cin >> data.q;
		if (strcmp(data.q, "false") == 0) {
			m--;
			break; 
		}
		cout << "������aѡ��:";//����ѡ��
		cin >> data.a;
		cout << "������bѡ��:";
		cin >> data.b;
		cout << "������cѡ��:";
		cin >> data.c;
		cout << "������dѡ��:";
		cin >> data.d;
		cout << "��������ȷѡ��:";
		cin >> data.anwser;
		if (data.anwser >= 97 && data.anwser <= 122)
		{
			data.anwser = data.anwser - 32;
		}
		fwrite(&data, size, 1, fp);
		system("cls");
	}
	fclose(fp);
	return m;
}
