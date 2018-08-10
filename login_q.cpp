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
	char str1[50];//用于用户名输入
	char str2[50];//用于密码输入
	struct user p;
	cout << "**************登录************" << endl;
	cout << "----------请输入用户名:";
	scanf("%s", str1);
	cout << "----------请输入密码:";
	scanf("%s", str2);
	fp = fopen("login.txt", "r+");
	if (fp == NULL)
	{
		return;
	}
	bool flag = false;//用一个布尔值来表示用户名与密码是否正确
	while (!feof(fp))
	{
		fread(&p, sizeof(struct user), 1, fp);
		if (strcmp(p.name, str1) == 0 && strcmp(p.password, str2) == 0)
		{
			system("cls");
			strcpy(str, str1);//将用户名储存下来，其他函数要用到，用来打开该用户对应的错题库
			printf("****************欢迎用户%s****************\n", str);
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << ".....登陆失败，请重新输入" << endl;
		login(str);
	}
	fclose(fp);
}