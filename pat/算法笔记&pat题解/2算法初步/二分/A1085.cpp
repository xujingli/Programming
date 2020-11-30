//���ڣ�2018/ ʱ�䣺
/*
a[i]*p���ܴﵽ10^18����˱���ʹ��long long����ǿ������ת�� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
const int maxn = 100005; 
//#define p1
//p1ʹ��two pointers˼��
//#define p2
//p2���ֲ��� 
#define p3
//p3ʹ��upper_bound���� 
//#define p4

/*******************************p3*********************************************/
#ifdef p4 


#endif
/******************************************************************************/
 

/*******************************p3*********************************************/
#ifdef p3
//lower_bound()��upper_bound()������ algorithm�����µĳ��ú��� �������ʵ�ּ�4.5.1 �� 
//lower_bound(first,last,val)����Ѱ���������������[first,low)��Χ�ڵ�һ��ֵ   ���ڵ���    valԪ�ص�λ�ã�
							//����������򷵻ظ�λ�õ�ָ��,������������򷵻ظ�λ�õĵ������� 
//upper_bound(first,last,val) ����Ѱ���������������[first,low)��Χ�ڵ�һ��ֵ  ����        valԪ�ص�λ�ã�
							//����������򷵻ظ�λ�õ�ָ��,������������򷵻ظ�λ�õĵ������� 
int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//��������
	int ans = 1;
	for(int i=0;i<N;i++){
		//int j = upper_bound(i+1,n,(long long)A[i]*p);
		int j = upper_bound(A+i+1,A+N,(long long)A[i]*p)-A;
		ans = max(ans, j-i);
	} 
	
	printf("%d",ans);
	return 0;
}

#endif
/***************************************************************************/


/*******************************p2*********************************************/
#ifdef p2

int binarySearch(int A[],int n,int i,long long x){	//����Ϊn������A, ��[i+1]λ�õ�[n-1]Ѱ�ҵ�һ������x���� 
	if(A[n-1] <= x)	return n;		//����������ֶ�С��x���򷵻�n
	 
	int left = i+1,right = n-1;
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] <= x){
			left = mid + 1;
		}else{
			right = mid;
		}
	} 
	return left;
}

int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//��������
	
	int ans=1;
	for(int i=0;i<N;i++){
		int j=binarySearch(A,N,i,(long long)A[i]*p);
		ans = max(ans , j-i);
	}
	printf("%d",ans);
	
	return 0;
}

#endif
/***************************************************************************/

/******************************p1**********************************************/
#ifdef p1
//��һ���𰸴��󣬵÷�23   �ⷨ�ɼ�p165�Լ�p176 
int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//��������
	int i=0,j=N-1;			//���յ��������j-i+1
	while(j>=i){				//ָ��λ��һǰһ�� 
		if(A[j] <= (long long)A[i]*p){		//�������������������������� 
			printf("%d",j-i+1);
			break;
		}
		else if(A[j-1] > (long long)A[i]*p && A[j] > (long long)A[i+1]*p){//i,jָ��ֱ�ǰ���ͺ��ˣ������������������Ҫһ��ǰ��һ��������һ�� 
			i++;
			j--;
		}
		else if(A[j-1] <= (long long)A[i]*p || A[j] <= (long long)A[i+1]*p){//iָ��ǰ��һ��������jָ�����һ����������Ļ���������Ӵ� 
			printf("%d",j-i+1-1);
			break;
		}
	} 
	
	return 0;
}
#endif
/***************************************************************************/
