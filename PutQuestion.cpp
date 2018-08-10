#include"PutQuestion.h"
#include"test.h"
#include"struct_q.h"
#include<iostream>
using namespace std;
char PutQuestion(int index)
{
	question item;
	FILE *fp;
	if ((fp = fopen("database.txt", "r")) == NULL)
	{
		printf("Can not open file.\n");
		exit(1);
	}
	do
		fread(&item , sizeof(struct question), 1, fp);
	while (item.num != index);
	printf("%s\n\nA:%s\n\B:%s\nC:%s\nD:%s\n\n«Î ‰»Î¥∞∏£∫\n",item.q,item.a,item.b,item.c,item.d );
	fclose(fp);
	return item.anwser;
}