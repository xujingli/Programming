//******************************p2介绍C++中的sort函数******************************************
#define p2
#ifdef p2
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm> 
using namespace std;

struct node{
	int x,y;
}ssd[10];

bool cmpn1(node a,node b){			//结构体按照x从大到小排序 
	return a.x>b.x;
}

bool cmpn2(node a,node b){			//结构体按照x从大到小排序，在x相等的情况下，按照y从大到小排序 
	if(a.x!=b.x)	return a.x>b.x;
	else	return a.y>b.y;
} 

bool cmpi(int a,int b){				
	return a>b;
} 

bool cmpd(double a,double b){
	return a>b;
}

bool cmpc(char a,char b){
	return a>b;
}

bool cmpv(int a,int b){			//因为vector中的元素为int型，因此仍然是int的比较 
	return a>b; 
} 

bool cmps(string str1,string str2){
	return str1.length() < str2.length();		//按照string的长度大小从小到大排列 
}

int main(){
	/*************************如何使用sort排序***********************************************/
	printf("对int型数组排序：\n");
	int a[6]={9,4,2,5,6,-1};
	//将a[0]~a[3]从小到大排序
	sort(a,a+4);			//注意理解尾元素地址的下一个地址 
	printf("将a[0]--a[3]从小到大排序: ");
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	//将a[0]~a[5]从小到大排序
	sort(a,a+6);
	printf("将a[0]--a[5]从小到大排序: ");
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	
	printf("对double型数组排序：\n");
	double b[]={1.4,-2.1,9};
	sort(b,b+3);
	printf("将b[0]--b[2]从小到大排序： ");
	for(int i=0;i<3;i++){
		printf("%.1lf ",b[i]);
	}
	printf("\n");
	
	printf("对char型数组排序（默认为字典序）：\n");
	char c[]={'T','W','A','K'};
	sort(c,c+4);
	printf("将c[0]到c[3]按照字典序排序： ");
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
	printf("\n*************************************************************************\n");
	/*************************如何使用sort排序***********************************************/
	
	/*************************如何实现比较函数cmp********************************************/ 
	//sort的第三个可选参数用来实现“认为制定的比较规则”。
		//1.基本数据类型数组的排序
		//如果想要从大到小排序，就必须使用cmp函数告诉sort何时要交换元素 
	printf("对int型数组排序：\n");
	sort(a,a+6,cmpi);
	printf("将a[0]--a[5]从大到小排序: ");
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	
	printf("对double型数组排序：\n");
	sort(b,b+3,cmpd);
	printf("将b[0]--b[2]从大到小排序： ");
	for(int i=0;i<3;i++){
		printf("%.1lf ",b[i]);
	}
	printf("\n");
	
	printf("对char型数组排序：\n");
	sort(c,c+4,cmpc);
	printf("将c[0]到c[3]按照字典倒序排序： ");
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
	printf("\n*************************************************************************\n");
	
		 //2.结构体数组的排序 
		 //定义了两个排序规则，cmpn1,cmpn2;
	printf("对结构体进行排序： \n");
	ssd[0].x=2;	ssd[0].y=2; 	//{2,2}
	ssd[1].x=4;	ssd[1].y=1; 	//{4,1} 
	ssd[2].x=3;	ssd[2].y=4; 	//{3,4} 
	ssd[3].x=3;	ssd[3].y=5; 	//{3,5} 
	ssd[4].x=1;	ssd[4].y=3; 	//{1,3} 
	
	sort(ssd,ssd+5,cmpn1);
	printf("将ssd[0]--ssd[4]按照x从大到小排序：\n\tx   y \n");
	for(int i=0;i<5;i++){
		printf("\t%d   %d\n",ssd[i].x,ssd[i].y);
	} 
	
	sort(ssd,ssd+5,cmpn2);
	printf("将ssd[0]--ssd[4]按照x从大到小排序，x相同时，按照y从大到小排序：\n\tx   y \n");
	for(int i=0;i<5;i++){
		printf("\t%d   %d\n",ssd[i].x,ssd[i].y);
	} 
	printf("\n*************************************************************************\n");
			//3.容器的排序
			//在STL标准容器中，只有vector/string/deque是可以使用sort的。像set/map这种容器是用红黑树实现的，元素本身有序，故不允许使用sort排序
	printf("对容器进行排序： \n");	
	vector<int> vi;
	vi.push_back(3);
	vi.push_back(2);
	vi.push_back(1);
	vi.push_back(6);
	vi.push_back(4);
	sort(vi.begin(),vi.end(),cmpv);		//对vector升序排列
	printf("对vector数组vi 0-5从大到小排列：");
	for(int i=0;i<5;i++)
		printf("%d ",vi[i]);
	printf("\n"); 
	
	string str[3] = {"bbbb","cc","aaa"}; 
	sort(str,str+3);		//string型数组按照 字典序列从小到大排列
	printf("string型数组按照字典序列从小到大排列: \n");
	for(int i=0;i<3;i++)
		cout << "\t" << str[i] <<endl; 
	
	sort(str,str+3,cmps);		//按照字符长度从小到大排序
	printf("string型数组按照字符长度从小到大排列: \n");
	for(int i=0;i<3;i++)
		cout << "\t" << str[i] <<endl; 
	
	printf("\n*************************************************************************\n");
	 
	/*************************如何实现比较函数cmp********************************************/ 
	
	return 0;
} 

#endif

/********************************p1是各种排序算法的实现 ******************************************/
//#define p1	
#ifdef p1 
//SelectSort、InsertSort 
#include <stdio.h>
#include <stdlib.h> 

void Print(int A[],int n){
	//此函数用于输出一个数组			
	for(int p=0;p<n;p++)		//输出数组元素 
		printf("%d ",A[p]);
	printf("\n"); 
}

void SelectSort(int A[],int n){
	//算法思想：每次从数组剩余元素中选择一个最小的元素，令其与待排序部分的第一个元素交换 
	for(int i=0;i<n;i++){
		int k=i;		//下标k用来存放最小元素的下标，初试时用于存放“待排序部分的第一个元素” 
		for(int j=i;j<n;j++){//从“待排序部分”的第一个元素开始 
			if(A[j]<A[k])
				k=j;
		}					
		int temp=A[i];			//交换 
		A[i]=A[k];
		A[k]=temp;
	}
	
	Print(A,n); 		//输出数组元素 
}

void InsertSort(int A[],int n){
	//算法思想：每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中，直到全部记录插入完成 
	int i,j;
	for(int i=1;i<=n;i++){
		if(A[i]<A[i-1]){
			
		}
	} 
}

int main(){
	int num[10]={54,35,132,13245,112,212,212,123,111,256};
	SelectSort(num,10);

	return 0;
}

#endif 
