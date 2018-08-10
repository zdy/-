#include"test.h"
#include"PutQuestion.h"
#include"struct_q.h"
#include<iostream>
using namespace std;
void test(int index[], int question_num)
{
	int choose;//记录用户测试完毕后选择查看成绩还是返回主界面
	int correct_num = 0;//初始化正确题目数
    //ture记录每道题的正确答案,anwser记录用户输入答案
	char ture;
	int judge;//
	char anwser;
	
	//做题中
	
	
	for (int i = 0; i < question_num; i++)//开始做题，做题次数等于需做题题目总数（question_num)
	{
		system("cls");
		cout << "———————————————当前第 " << i + 1 << " / " << question_num << " 道题\n\n\n";//提示用户当前第几题
		ture=PutQuestion(index[i]);//输出提干，记录正确选项
		
		//判断用户是否输入格式正确
		cin >> anwser;
		while (anwser<'A' || anwser>'D'&&anwser<'a' || anwser>'d')
		{
			system("cls");
			cout << "请输入正确的格式！！！\n\n";
			cout << "———————————————当前第 " << i + 1 << " / " << question_num << " 道题\n\n\n";//提示用户当前第几题
			ture = PutQuestion(index[i]);//输出提干，记录正确选项
			cin >> anwser;
		}
		if (anwser > 90)
			anwser -= 32;
		//判断用户答案是否正确
		if (ture == anwser)
		{
			correct_num++;
			cout << "\n\n回答正确！！\n\n(/≧▽≦)/~┴┴好厉害呢~~，继续加油哦~~\n\n\n请输入1继续:\n";
			while (cin >> judge&&judge != 1);
		}
		else {
			cout << "\n\n答案错误！！\n\n   o(TヘTo)敲遗憾呢~不要气馁，继续加油哦！！ˋ( ° ▽、° )\n\n正确答案为： " << ture << endl << "\n\n请输入1继续\n";
			while (cin >> judge&&judge != 1);
		}
	}
	
	
	
	
	
	
	//做题完成
	
	system("cls");//清空页面
	printf("\t\t恭喜您，测试完毕啦~~！！！\n\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t\t\t*\n*\t\t您本次测试的正确率为： %.2f\t\t*\n*\t\t\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n\n输入0返回主界面：", correct_num*1.0 / question_num);
	cin >> choose;
	while (choose != 0)
	{
		system("cls");//清空页面
		printf("\t\t恭喜您，测试完毕啦~~！！！\n\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n*\t\t\t\t\t\t\t*\n*\t\t您本次测试的正确率为： %.2f\t\t*\n*\t\t\t\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n\n输入0返回主界面：", correct_num*1.0 / question_num);
		cin >> choose;
	}
	system("cls");//清空页面
}