//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxn = 100000;

int main(){
	int D,N;
	scanf("%d%d",&D,&N);
	int A[maxn],B[maxn];
	memset(A,0,sizeof(A)); 
	int idx1,idx2;
	int lenA;
	
	A[1] = D;
	lenA = 1;
	
	for(int i=1;i<N;i++){
		idx1 = 1;idx2 =1;
		int count=1;
		B[idx2++] = A[idx1];//B�ĵ�һ��λ�ô��Ԫ�أ��ڶ���λ�ô�Ÿ���
		for(;idx1<=lenA;idx1++){
			if(A[idx1+1] == A[idx1]){			//ǰ������Ԫ����� 
				count++; 
			} else {					//ǰ������Ԫ�ز��� 
				B[idx2++] = count;		//
				count = 1;
				if(idx1!=lenA)
					B[idx2++] = A[idx1+1];
			}
		}
		lenA = idx2 - 1;
		
		memset(A,0,sizeof(A));	//��ʼ��A������B��Ԫ�ظ��Ƹ��� 
		for(int j=1;j<=lenA;j++){
			A[j] = B[j];
		} 
		memset(B,0,sizeof(B));
	}
	
	for(int j=1;j<=lenA;j++){
		printf("%d",A[j]);
	} 
	

	return 0;
}

