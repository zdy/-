#include"login.h"
#include<iostream>
using namespace std;
struct user {
	string username;
	string password;
};
int login(string username,string password)//����0��ʾ�˺�����ƥ�䣬����1��ʾ�˺Ż��������
{
	user item;
	FILE *fp;
	if ((fp = fopen("user.txt", "r")) == NULL)
	{
		cout << "Can not open file.\n";
		exit(1);
	}

	/*��ѭ������ƥ���û���Ϣ*/
	while (fread(&item, sizeof(struct user), 1, fp) != EOF)
		if (item.username == username)
			if(item.password == password)
				return 0;
			else break;
	return 1;
}