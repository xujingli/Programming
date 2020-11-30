//******************************p2����C++�е�sort����******************************************
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

bool cmpn1(node a,node b){			//�ṹ�尴��x�Ӵ�С���� 
	return a.x>b.x;
}

bool cmpn2(node a,node b){			//�ṹ�尴��x�Ӵ�С������x��ȵ�����£�����y�Ӵ�С���� 
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

bool cmpv(int a,int b){			//��Ϊvector�е�Ԫ��Ϊint�ͣ������Ȼ��int�ıȽ� 
	return a>b; 
} 

bool cmps(string str1,string str2){
	return str1.length() < str2.length();		//����string�ĳ��ȴ�С��С�������� 
}

int main(){
	/*************************���ʹ��sort����***********************************************/
	printf("��int����������\n");
	int a[6]={9,4,2,5,6,-1};
	//��a[0]~a[3]��С��������
	sort(a,a+4);			//ע�����βԪ�ص�ַ����һ����ַ 
	printf("��a[0]--a[3]��С��������: ");
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	//��a[0]~a[5]��С��������
	sort(a,a+6);
	printf("��a[0]--a[5]��С��������: ");
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	
	printf("��double����������\n");
	double b[]={1.4,-2.1,9};
	sort(b,b+3);
	printf("��b[0]--b[2]��С�������� ");
	for(int i=0;i<3;i++){
		printf("%.1lf ",b[i]);
	}
	printf("\n");
	
	printf("��char����������Ĭ��Ϊ�ֵ��򣩣�\n");
	char c[]={'T','W','A','K'};
	sort(c,c+4);
	printf("��c[0]��c[3]�����ֵ������� ");
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
	printf("\n*************************************************************************\n");
	/*************************���ʹ��sort����***********************************************/
	
	/*************************���ʵ�ֱȽϺ���cmp********************************************/ 
	//sort�ĵ�������ѡ��������ʵ�֡���Ϊ�ƶ��ıȽϹ��򡱡�
		//1.���������������������
		//�����Ҫ�Ӵ�С���򣬾ͱ���ʹ��cmp��������sort��ʱҪ����Ԫ�� 
	printf("��int����������\n");
	sort(a,a+6,cmpi);
	printf("��a[0]--a[5]�Ӵ�С����: ");
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	
	printf("��double����������\n");
	sort(b,b+3,cmpd);
	printf("��b[0]--b[2]�Ӵ�С���� ");
	for(int i=0;i<3;i++){
		printf("%.1lf ",b[i]);
	}
	printf("\n");
	
	printf("��char����������\n");
	sort(c,c+4,cmpc);
	printf("��c[0]��c[3]�����ֵ䵹������ ");
	for(int i=0;i<4;i++)
		printf("%c ",c[i]);
	printf("\n*************************************************************************\n");
	
		 //2.�ṹ����������� 
		 //�����������������cmpn1,cmpn2;
	printf("�Խṹ��������� \n");
	ssd[0].x=2;	ssd[0].y=2; 	//{2,2}
	ssd[1].x=4;	ssd[1].y=1; 	//{4,1} 
	ssd[2].x=3;	ssd[2].y=4; 	//{3,4} 
	ssd[3].x=3;	ssd[3].y=5; 	//{3,5} 
	ssd[4].x=1;	ssd[4].y=3; 	//{1,3} 
	
	sort(ssd,ssd+5,cmpn1);
	printf("��ssd[0]--ssd[4]����x�Ӵ�С����\n\tx   y \n");
	for(int i=0;i<5;i++){
		printf("\t%d   %d\n",ssd[i].x,ssd[i].y);
	} 
	
	sort(ssd,ssd+5,cmpn2);
	printf("��ssd[0]--ssd[4]����x�Ӵ�С����x��ͬʱ������y�Ӵ�С����\n\tx   y \n");
	for(int i=0;i<5;i++){
		printf("\t%d   %d\n",ssd[i].x,ssd[i].y);
	} 
	printf("\n*************************************************************************\n");
			//3.����������
			//��STL��׼�����У�ֻ��vector/string/deque�ǿ���ʹ��sort�ġ���set/map�����������ú����ʵ�ֵģ�Ԫ�ر������򣬹ʲ�����ʹ��sort����
	printf("�������������� \n");	
	vector<int> vi;
	vi.push_back(3);
	vi.push_back(2);
	vi.push_back(1);
	vi.push_back(6);
	vi.push_back(4);
	sort(vi.begin(),vi.end(),cmpv);		//��vector��������
	printf("��vector����vi 0-5�Ӵ�С���У�");
	for(int i=0;i<5;i++)
		printf("%d ",vi[i]);
	printf("\n"); 
	
	string str[3] = {"bbbb","cc","aaa"}; 
	sort(str,str+3);		//string�����鰴�� �ֵ����д�С��������
	printf("string�����鰴���ֵ����д�С��������: \n");
	for(int i=0;i<3;i++)
		cout << "\t" << str[i] <<endl; 
	
	sort(str,str+3,cmps);		//�����ַ����ȴ�С��������
	printf("string�����鰴���ַ����ȴ�С��������: \n");
	for(int i=0;i<3;i++)
		cout << "\t" << str[i] <<endl; 
	
	printf("\n*************************************************************************\n");
	 
	/*************************���ʵ�ֱȽϺ���cmp********************************************/ 
	
	return 0;
} 

#endif

/********************************p1�Ǹ��������㷨��ʵ�� ******************************************/
//#define p1	
#ifdef p1 
//SelectSort��InsertSort 
#include <stdio.h>
#include <stdlib.h> 

void Print(int A[],int n){
	//�˺����������һ������			
	for(int p=0;p<n;p++)		//�������Ԫ�� 
		printf("%d ",A[p]);
	printf("\n"); 
}

void SelectSort(int A[],int n){
	//�㷨˼�룺ÿ�δ�����ʣ��Ԫ����ѡ��һ����С��Ԫ�أ�����������򲿷ֵĵ�һ��Ԫ�ؽ��� 
	for(int i=0;i<n;i++){
		int k=i;		//�±�k���������СԪ�ص��±꣬����ʱ���ڴ�š������򲿷ֵĵ�һ��Ԫ�ء� 
		for(int j=i;j<n;j++){//�ӡ������򲿷֡��ĵ�һ��Ԫ�ؿ�ʼ 
			if(A[j]<A[k])
				k=j;
		}					
		int temp=A[i];			//���� 
		A[i]=A[k];
		A[k]=temp;
	}
	
	Print(A,n); 		//�������Ԫ�� 
}

void InsertSort(int A[],int n){
	//�㷨˼�룺ÿ�ν�һ��������ļ�¼������ؼ��ִ�С���뵽ǰ���Ѿ��ź�����������У�ֱ��ȫ����¼������� 
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
