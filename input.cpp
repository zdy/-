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
int input()//录入题目
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
	m = ftell(fp) / size;//ftell（fp）文件开头到文件指针所在位置所移动的字节数
	for (int i = 0;;++i)
	{
		data.num = ++m;
		printf("* * * * * * * * * * * * * * 当前已输入%d题 * * * * * * * * * * * * * *\n\n\n", i);
		cout<<"请输入题目题干(停止请输入false):";//输入题干
		cin >> data.q;
		if (strcmp(data.q, "false") == 0) {
			m--;
			break; 
		}
		cout << "请输入a选项:";//输入选项
		cin >> data.a;
		cout << "请输入b选项:";
		cin >> data.b;
		cout << "请输入c选项:";
		cin >> data.c;
		cout << "请输入d选项:";
		cin >> data.d;
		cout << "请输入正确选项:";
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
