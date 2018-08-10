#ifndef STRUCT_Q //题目存储结构体
#define STRUCT_Q
#define M 2000
#define N 200
struct question {
	int num;//题目序号
	char q[M];//题干
	int index1;//分隔作用
	char a[N];//选项a
	int index2;
	char b[N];//选项b
	int index3;
	char c[N];//选项c
	int index4;
	char d[N];//选项d
	int index0;
	char anwser;//标准答案序号
};
#endif // !STRUCT_Q
