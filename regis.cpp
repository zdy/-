#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include"struct_user.h"
#include"login_q.h"
#include"regis_q.h"
using namespace std;
void regis()
{
	FILE *fp;
	fp = fopen("login.txt", "r+");
	if (fp == NULL)
	{
		return;
	}
	char str1[50] = { 0 };
	struct user p;//ע��ʱ�����õĽṹ���������
	cout << "----------�������û���:";
	scanf("%s", p.name);
	cout << "----------����������:";
	scanf("%s", p.password);
	cout << "----------���ٴ���������:";
	scanf("%s", str1);
	while (strcmp(p.password, str1) != 0)//�����ж����������������û����Ƿ���ͬ
	{
		cout << "----------�������벻ͬ" << endl;
		cout << "----------�������û���:";
		scanf("%s", p.name);
		cout << "----------����������:";
		scanf("%s", p.password);
		cout << "----------���ٴ���������:";
		scanf("%s", str1);
	}
	struct user q;//�����жϸ��û����Ƿ�ע���
	bool flag = true;
	fread(&q, sizeof(struct user), 1, fp);
	while (!feof(fp))
	{
		if (strcmp(q.name, p.name) == 0)
		{
			cout << "���û����Ѵ���" << endl;
			flag = false;
			break;
		}
		fread(&q, sizeof(struct user), 1, fp);
	}
	fclose(fp);
	if (flag == true)//�û�ע��ɹ�
	{
		fp = fopen("login.txt", "a+");
		if (fp == NULL)
		{
			return;
		}
		fwrite(&p, sizeof(struct user), 1, fp);
		cout << "ע��ɹ�" << endl;
		fclose(fp);
		strcat(p.name, ".txt");//ÿע��һ���û���������һ�������
		fp = fopen(p.name, "w+");
		if (fp == NULL)
		{
			return;
		}
		fclose(fp);
		system("pause");
		system("cls");
	}
	if (flag == false)//�û��Ѵ��ڣ�����������
		regis();
}
