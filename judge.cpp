#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define M 2000
#define N 200
struct question {
	int num;//题目序号
	char q[M];//题干
	char a[N];//选项a
	char b[N];//选项b
	char c[N];//选项c
	char d[N];//选项d
	char anwser;//标准答案序号
};
#define size sizeof(struct question)
#define SEEK_END 2
int judge()
{
	FILE *fp;
	int m = 0;
	fp = fopen("database.txt", "a");
	if (fp == NULL)
	{
		return 0;
	}
	fseek(fp, 0, SEEK_END);
	m = ftell(fp) / size;
	fclose(fp);
	return m;
}
