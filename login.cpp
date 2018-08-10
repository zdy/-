#include"login.h"
#include<iostream>
using namespace std;
struct user {
	string username;
	string password;
};
int login(string username,string password)//返回0表示账号密码匹配，返回1表示账号或密码错误
{
	user item;
	FILE *fp;
	if ((fp = fopen("user.txt", "r")) == NULL)
	{
		cout << "Can not open file.\n";
		exit(1);
	}

	/*此循环用来匹配用户信息*/
	while (fread(&item, sizeof(struct user), 1, fp) != EOF)
		if (item.username == username)
			if(item.password == password)
				return 0;
			else break;
	return 1;
}