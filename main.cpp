#include"input.h"
//#include"login.h"
#include"PutQuestion.h"
#include"struct_q.h"
#include"test.h"
#include<iostream>
#include"Rand.h"
#include"jugde.h"
#include"RandOfQuesNum.h"
#include"struct_user.h"
#include"login_q.h"
#include"regis_q.h"
using namespace std;
/*void color(short x) //自定义函根据参数改变颜色   
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色  
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //只有一个参数，改变字体颜色   
	else//默认的颜色白色  
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}*/


void main()
{

	/*    */
	//color(2);
	/*    */
	int a;
	char b[50];//主函数中用来储存登陆成功的用户名,生成错题库所用的文件名，已包含.txt
	char c[50];//生成考试记录所用的文件名，比b数组多加了两个||
	cout << "****************@**************" << endl;
	cout << "请选择登录(输入0)/注册(输入1):";
	cin >> a;
	while (a != 0 && a != 1) {
		cout << "输入了非法字符;" << endl;
		cout << "请重新输入:"; cin >> a;
	}
	//防止输入其他数字
	if (a == 0)
		login(b);
	//选择登录不注册
	if (a == 1)
	{
		regis();
		login(b);
	}
	//选择注册并且登录
	strcpy(c, b);
	strcat(b, ".txt");
	strcat(c, "||.txt");




	int num_all=judge();//题库中题目总数
	int test_num;//测试样例数目
	RANK index;//随机获取样例的序号
	int ch;//记录选择
	cout << "* * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t*\n*\t      感谢使用本应用！！  \t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t1.录入题目\t\t*\n*\t\t\t\t\t*\n*\t\t2.进行测试\t\t*\n*\t\t\t\t\t*\n*\t\t0.结束程序\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * *\n\t\t当前题库中题目总数为："<<num_all<<"\n\n\n\n请输入对应序号进行操作：";
	while (cin>>ch&&ch!=0)
	{
		system("cls");
		switch (ch)
		{
		case 1:num_all=input();break;
		case 2:if (num_all == 0) while (cout << "题库中未录入题目，请按0返回\n"&&cin >> ch&&ch != 0) system("cls"); 
			   else { cout << "请输入您想要抽取题目的数目\n";
			   while (cin >> test_num&&test_num > num_all)
			   {
				   system("cls");
				   cout << "您输入的抽取样例数过大，当前题库中全部题目数为 " << num_all << "\n请重新输入\n";
			   }
			   index = RandQuesNum(num_all,test_num);
			   test(index.QuestionNum,test_num);
			   }
		default:
			break;
		}
		system("cls");
		cout << "* * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t*\n*\t      感谢使用本应用！！  \t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t1.录入题目\t\t*\n*\t\t\t\t\t*\n*\t\t2.进行测试\t\t*\n*\t\t\t\t\t*\n*\t\t0.结束程序\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n*\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * *\n\t\t当前题库中题目总数为：" << num_all << "\n\n\n\n请输入对应序号进行操作：";
              	}
	
}