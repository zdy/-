#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define M 2000
#define N 200
struct question {
	int num;//��Ŀ���
	char q[M];//���
	char a[N];//ѡ��a
	char b[N];//ѡ��b
	char c[N];//ѡ��c
	char d[N];//ѡ��d
	char anwser;//��׼�����
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
