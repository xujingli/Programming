//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

//#define p1
//#define p2
// p1�ݹ�ʵ��  p2�ǵݹ�ʵ��
#define p3
//�����鲢����ÿһ�˽���ʱ������ 

const int maxn=100;
//������A��[L1,R1]/[L2,R2]�ϲ�Ϊ�������䣨L2 = R1 + 1�� 
void merge(int A[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2;		//iָ��A[L1],jָ��A[L2]
	int temp[maxn], index=0;		//temp��ʱ��źϲ�������飬indexΪ���±�
	while(i <= R1 && j<=R2){
		if(A[i] <= A[j]){
			temp[index++]=A[i++];
		}else{
			temp[index++]=A[j++];
		}
	} 
	while(i<=R1) temp[index++]=A[i++];
	while(j<=R2) temp[index++]=A[j++];
	
	for(int i=0;i<index;i++)
		A[L1+i]=temp[i];
}

#ifdef p1
//��array���鵱ǰ����[left,right]���й鲢���� 
void mergeSort(int A[],int left,int right){
	if(left < right){
		int mid = (left+right)/2;
		mergeSort(A,left,mid);		
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
	}
}
#endif

#ifdef p2
//�ǵݹ�����ÿ�η�������Ԫ�ظ������޶���2���ݴΡ�
//����һ������step�������ֵΪ2,Ȼ��ÿstep��Ԫ����Ϊһ�飬�����ڲ���������
//(�������ڵ���ߵ�(step/2)��Ԫ�� �� �ұ�(step/2)��Ԫ�� �ϲ�������Ԫ�ظ���������(step/2)���򲻲���)
//����step����2,�ظ�����Ĳ�����ֱ��step/2����Ԫ�ظ���n
//���´��룬����A[]�±��1��ʼ 
void mergeSort(int A[]){
	//stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ�����ע��Ⱥſ��Բ�ȡ
	for(int step=2;step/2 <= n;step*=2){
		//ÿstep��Ԫ��һ�飬����ǰstep/2��Ԫ�غͺ�step/2��Ԫ�ؽ��кϲ� 
		for(int i=1,i<=n;i+=step){		//һ��step�ֳ�һ��С�� 
			//��ÿһ�� 
			int mid=i + step/2 -1;		//��������Ԫ�ظ���Ϊstep/2
			if(mid + 1 <= n){			//�����������Ԫ����ϲ� 
				//��������Ϊ[i,mid],��������Ϊ[mid+1,min(i+step-1,n)]
				merge(A,i,mid,mid+1,min(i+step-1,n)); 
			} 
		}
	} 
}
#endif
 
#ifdef p3
//���Ҫ�����ÿһ�ι鲢���������У���ô��ȫ����ʹ��sort����ȡ��merge����
void mergeSort(int A[]){
	//stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ�����ע��Ⱥſ��Բ�ȡ
	for(int step = 2;step/2 <= n;step*=2){
		//ÿstep��Ԫ��һ�飬����[i,min(i+step,n+1)]��������
		for(int i=1;i<=n;i+=step){
			sort(A+i,A+min(i+step,n+1));
		} 
		
		//�˴���������鲢�����ĳһ�˽���������� 
	} 
} 

#endif
 
int main(){
	

	return 0;
}

