//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

//#define p1
/*
double表示的精度不够 
*/
#ifdef p1 

int main(){
	double A,B,C;
	int T;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lf %lf %lf",&A,&B,&C);
		printf("\n%lf %lf %lf\n",A,B,C);	//由输出可见，double表示的精读不够 
		if(A+B > C)
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}//9223372036854775807

	return 0;
}
#endif

//#define p2
/*
p2的思路是这样的，输入的A,B,C中假设不含有2的63次方，则long long 的范围是（-pow(2,63)到pow(2,63)-1）
	由组成原理知识得知，同类型的正数加上一个负数是一定不会溢出的
	所以有如下的思路：
	A>0,B>0  if C<0 则为true
	         if C>0 A+B>C 与判断 A>C-B等价，而后者C-B是一个正数加上一个负数，结果一定不会溢出
	A>0,B<0  A+B可以直接运算，不会溢出
	A<0,B>0  同上
	A<0,B<0  if C>0 则为false
			 if C<0 A+B>C 与判断 A>C-B等价，而后者C-B是一个正数加上一个负数，结果一定不会溢出
但是要注意，A,B,C中为0的情况，这是一个类似于“剪枝” 的思想 


但是错误如下：	long long型数据不能表示2的63次方。 但是以下代码提交的测试都是通过的，说明题目可能写错了！  
*/ 1

#ifdef p2
int main(){
	int T;	
	scanf("%d",&T);
	
	long long A,B,C;
	for(int i=0;i<T;i++){
		scanf("%lld %lld %lld",&A,&B,&C);
		//printf("\n%lf %lf %lf\n",A,B,C);	//由输出可见，double表示的精读不够 
		if(A>0 && B>0 && C<=0)
			printf("Case #%d: true\n",i+1);
		else if(A>0 && B>0 && C>0 && A > (C-B))
			printf("Case #%d: true\n",i+1);
		else if(A>=0 && B<=0 && (A+B)>C)
			printf("Case #%d: true\n",i+1);
		else if(A<=0 && B>=0 && (A+B)>C)
			printf("Case #%d: true\n",i+1);
		else if(A<0 && B<0 && C<0 && A>(C-B))
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}//9223372036854775807
	return 0;
}

#endif 

#define p3
#ifdef p3

int main(){
	
	
	return 0;
} 

#endif 
