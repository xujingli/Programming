//���ڣ�2018/ ʱ�䣺
/*
a[i]*p���ܴﵽ10^18����˱���ʹ��long long����ǿ������ת�� 
��˼��two pointers����ָ�����һ�����һ����ǰ ��Ҳ��������ͬ�����ƶ������һЩ��
p1��û��AC,�»ؿ��������ٷ�˼һ��Ϊʲô 
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
const int maxn = 100005; 
//#define p1
//p1ʹ��two pointers˼��
#define p4
//ʹ������һ��two pointers˼�� 

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

/******************************p4**********************************************/
#ifdef p4
//����ָ���ǰ������j�������ӣ�ֱ������ʽ�պò�����Ϊֹ,�ڴ˹����и���count��
//������������i����һλ����������j���һ�����ʼ�տ���i,j֮�������� 
int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//��������
	int i=0,j=0,count=1;
	while(i<N && j<N) {
		//j�������ƣ�ֱ��ǡ�ò���������
		while(j<N && A[j] <= (long long)A[i]*p){
			count = max(count,j-i+1);			//���¼�����count
			j++; 
		} 
		i++;	//����һλ 
	}
	printf("%d",count);
	
	return 0;
}
#endif
/***************************************************************************/
