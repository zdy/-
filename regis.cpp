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
	struct user p;//注册时的所用的结构体变量储存
	cout << "----------请输入用户名:";
	scanf("%s", p.name);
	cout << "----------请输入密码:";
	scanf("%s", p.password);
	cout << "----------请再次输入密码:";
	scanf("%s", str1);
	while (strcmp(p.password, str1) != 0)//用来判断两次输入密码与用户名是否相同
	{
		cout << "----------两次密码不同" << endl;
		cout << "----------请输入用户名:";
		scanf("%s", p.name);
		cout << "----------请输入密码:";
		scanf("%s", p.password);
		cout << "----------请再次输入密码:";
		scanf("%s", str1);
	}
	struct user q;//用来判断该用户名是否被注册过
	bool flag = true;
	fread(&q, sizeof(struct user), 1, fp);
	while (!feof(fp))
	{
		if (strcmp(q.name, p.name) == 0)
		{
			cout << "该用户名已存在" << endl;
			flag = false;
			break;
		}
		fread(&q, sizeof(struct user), 1, fp);
	}
	fclose(fp);
	if (flag == true)//用户注册成功
	{
		fp = fopen("login.txt", "a+");
		if (fp == NULL)
		{
			return;
		}
		fwrite(&p, sizeof(struct user), 1, fp);
		cout << "注册成功" << endl;
		fclose(fp);
		strcat(p.name, ".txt");//每注册一个用户，就生成一个错题库
		fp = fopen(p.name, "w+");
		if (fp == NULL)
		{
			return;
		}
		fclose(fp);
		system("pause");
		system("cls");
	}
	if (flag == false)//用户已存在，需重新输入
		regis();
}
