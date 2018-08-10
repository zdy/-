#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include"Rand.h"
#include"RandOfQuesNum.h"
using namespace std;
RANK RandQuesNum(int NumberOfQuestions,int n) {

	
	int t;//随机数
	int i;
	int j;
	RANK QuestionNum;//题号


	
	srand((unsigned)time(NULL)); //用时间做种，每次产生随机数不一样


	//输出n个题号
	for (i = 0; i < n;) {
		//产生题号的随机数
		t= rand() % NumberOfQuestions + 1;

		//判断是否重复

		for (j = 0; j < i; j++) {
			
			if (t == QuestionNum.QuestionNum[j])
				break;
		}
		if(j==i)
			QuestionNum.QuestionNum[i++] = t;
	}

	return QuestionNum;

}


/*int main() {
	int i;//题数
	int n;
	RANK randnum;
	printf("请输入需要的题数：");
	scanf("%d", &n);
	randnum = RandQuesNum(20, n);
	for (i = 0; i < n; i++)
		printf("%d\n", randnum.QuestionNum[i]);

}*/