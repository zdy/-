#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include"Rand.h"
#include"RandOfQuesNum.h"
using namespace std;
RANK RandQuesNum(int NumberOfQuestions,int n) {

	
	int t;//�����
	int i;
	int j;
	RANK QuestionNum;//���


	
	srand((unsigned)time(NULL)); //��ʱ�����֣�ÿ�β����������һ��


	//���n�����
	for (i = 0; i < n;) {
		//������ŵ������
		t= rand() % NumberOfQuestions + 1;

		//�ж��Ƿ��ظ�

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
	int i;//����
	int n;
	RANK randnum;
	printf("��������Ҫ��������");
	scanf("%d", &n);
	randnum = RandQuesNum(20, n);
	for (i = 0; i < n; i++)
		printf("%d\n", randnum.QuestionNum[i]);

}*/