#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include"struct_user.h"
#include"login_q.h"
using namespace std;
void login(char(&str)[50])
{
	FILE *fp;
	char str1[50];//�����û�������
	char str2[50];//������������
	struct user p;
	cout << "**************��¼************" << endl;
	cout << "----------�������û���:";
	scanf("%s", str1);
	cout << "----------����������:";
	scanf("%s", str2);
	fp = fopen("login.txt", "r+");
	if (fp == NULL)
	{
		return;
	}
	bool flag = false;//��һ������ֵ����ʾ�û����������Ƿ���ȷ
	while (!feof(fp))
	{
		fread(&p, sizeof(struct user), 1, fp);
		if (strcmp(p.name, str1) == 0 && strcmp(p.password, str2) == 0)
		{
			system("cls");
			strcpy(str, str1);//���û���������������������Ҫ�õ��������򿪸��û���Ӧ�Ĵ����
			printf("****************��ӭ�û�%s****************\n", str);
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << ".....��½ʧ�ܣ�����������" << endl;
		login(str);
	}
	fclose(fp);
}