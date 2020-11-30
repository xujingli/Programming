//���ڣ�2018/ ʱ�䣺
/*
������δ�һ�����������������K���������ֱ�ӵ��뷨�Ƕ���������Ȼ��ֱ��ȡ����K��Ԫ�ء����������ĸ��Ӷ�ΪO(nlogn) 
		�����ѡ���㷨���������Ӷ�ΪO(n)
���ѡ���㷨��ԭ��
	��A[left,right]ִ��һ��randPartition��������Ԫ����Ԫ�ظ�������ȷ���ģ������Ƕ�С����Ԫ��
	�����ʱ��Ԫ��A[p],��ôA[p]����A[left,right]�еĵ�i-left+1�������
	��M=i-left+1�����K==M��������ô��K�����������ԪA[p]��
				  ���K<M��������ô��K���������Ԫ���(��A[left,p-1]�е�K�����)������ݹ鼴�ɣ�
				  ���K>M��������ô��K���������Ԫ�Ҳ�(��A[p+1,right]�е�K-M�����)�����ҵݹ鼴�ɡ�
	�㷨��left==right��Ϊ�ݹ�߽磬����A[left] 
�������£� int randSelect(int A[],int left,int right,int K)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include <algorithm>
using namespace std; 

const int maxn = 100010;
int A[maxn],n;			//A�������������nΪ����� 

//��������������Ӷ�ΪO(n^2) ����p144.��ܷ����ǣ���A[left,right]�����ѡȡһ����Ԫ��
//��˲�������һ����Χ��[left,right]�ڵ������p��Ȼ����A[p]��Ϊ��Ԫ���л��֡�
//���������ǣ���A[p]��A[left]������Ȼ����ԭ�ȵ�Partition������д������
int randPartition(int A[],int left,int right){
	int p = (int)(round(1.0*rand()/RAND_MAX * (right-left) + left));
	//round()��������double�ͱ�����������ȡ�� 
	swap(A[p],A[left]);			//include <algorithm>
	
	int temp = A[left];		//��A[left]�������ʱ����temp	����һ����������һ����λ�� 
	while(left < right){
		while(left < right && A[right] > temp) right--;
		A[left]=A[right];
		while(left < right && A[left] <= temp ) left++;
		A[right]=A[left];
	} 
	A[left] = temp;
	return left;
} 

//���ѡ���㷨����A[left,right]�з��ص�K����� 
int randSelect(int A[],int left,int right,int K){
	if(left == right) return -1;		//�߽�
	
	int p = randPartition(A,left,right);	//���ֺ���Ԫ��λ��Ϊp
	int M = p-left+1;						//A[p]��A[left,right]�еĵ�M��
	if(K == M)	return A[p];				//�ҵ���K�����
	if(K < M){		//��K���������Ԫ��� 
		return randSelect(A,left,p-1,K);	//����Ԫ����ҵ�K�� 
	} else{
		return randSelect(A,p+1,right,K-M);	//����Ԫ�Ҳ��ҵ�K-M�� 
	}
}

/*Ӧ�ã� 
����һ���������ϣ������е�����������ͬ������Ҫ�����Ƿ�Ϊ�����Ӽ��ϣ�ʹ�����������ϵĲ�Ϊȫ������Ϊ�ռ���
�������Ӽ��ϵ�Ԫ�ظ���n1��n2֮��ľ���ֵ|n1-n2|������С������£�Ҫ�����Ǹ��Ե�Ԫ��֮��S1��S2��ľ���ֵ|S1-S2|�����ܴ���|S1-S2|

˼·��
nΪż������������Ԫ�ظ����ֱ�Ϊn/2��nΪ��������������Ԫ�ظ����ֱ�Ϊn/2��n/2+1
��Ȼ��Ϊʹ|S1-S2|�����ܴ���ֱ�ӵ�˼·����������ȡǰn/2��Ԫ��Ϊǰһ���Ӽ��������Ԫ��Ϊ��һ���Ӽ���ʱ�临�Ӷ�ΪO(nlogn)

�����ŵ�������ʹ�����ѡ���㷨���󼯺��е�n/2������֡������Ͱ�����ֳ������֡������ù������ڲ�Ԫ�ص����򷽷��� 
*/ 
int main(){
	srand((unsigned)time(NULL));		//��ʼ�����������
	//sum��sum1��¼��������֮�����зֺ�ǰn/2��Ԫ��֮��
	int sum = 0,sum1 = 0;
	scanf("%d",&n); 				//��������
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);			//��������
		sum += A[i];				//�ۼ���������֮�� 
	} 
	randSelect(A,0,n-1,n/2);		//Ѱ�ҵ�n/2��������������з�
	for(int i=0;i<n/2;i++){
		sum1 += A[i];				//�ۼƽ�С���Ӽ�����Ԫ��֮�� 
	} 
	
	printf("%d\n",(sum - sum1) -sum1);	//�������Ӽ��ϵ�Ԫ�غ�֮�� 

	return 0;
}
/*
13
1 6 33 18 4 0 10 5 12 7 2 9 3
*/

