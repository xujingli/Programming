//���ڣ�2018/ ʱ�䣺
/*�����˵������Ҫ����ͷ�ļ�<time.h>����<stdlib.h>. 
  ������main()������ͷ����srand((unsigned)time(NULL));
  rand()��������һ����Χ��[0,RAND_MAX]���������rand()/RAND_MAX�ͻ����һ��[0,1]���������
  ��Ҫ���ɴ�Χ�����������Ҫ�� (rand()/RAND_MAX)*(b-a) + a ���ٽ�����������ȡ��ת����int��
  ����(int)(round((rand()/RAND_MAX)*(b-a) + a)) ----------�Ͳ�����[a,b]��Χ�ڵ�������������� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

//two pointer������ 
//�������е�Ԫ�أ�ʹ��ǰ��������˵�Ԫ�ص��������㣬���������Ԫ�ض���������Ԫ�أ��Ҳ�����Ԫ�ض����ڸ�Ԫ�� 
int Partition(int A[],int left,int right){
	int temp = A[left];		//��A[left]�������ʱ����temp
	while(left < right){
		while(left < right && A[right] > temp) right--;
		A[left]=A[right];
		while(left < right && A[left] <= temp ) left++;
		A[right]=A[left];
	} 
	A[left] = temp;
	return left;
}

//���ŵ�˼���ǣ�1�����������е�Ԫ�أ�ʹ��ǰ��������˵�Ԫ�ص��������㣬���������Ԫ�ض���������Ԫ�أ��Ҳ�����Ԫ�ض����ڸ�Ԫ��
//				2���Ը�Ԫ�ص������Ҳ�ֱ���еݹ飬ֱ����ǰ��������ĳ��Ȳ�����1
//left��right��ֵΪ������β�±꣨����1��n��
void quickSort(int A[],int left,int right){
	if(left < right){	//��ǰ���䳤�ȳ���1 
		//��[left,right]��A[left]һ��Ϊ��
		int pos = Partition(A, left,right);
		quickSort(A,left,pos-1);		//����������ݹ���п�������
		quickSort(A,pos+1,right);		//����������ݹ���п������� 
	}
} 

//��������������Ӷ�ΪO(n^2) ����Ҫԭ�����ڣ���������Ԫ�ؽӽ�����ʱ����Ԫû�аѵ�ǰ���仮��Ϊ�������Ƚӽ��������� 
//��ܷ����ǣ���A[left,right]�����ѡȡһ����Ԫ��
//��˲�������һ����Χ��[left,right]�ڵ������p��Ȼ����A[p]��Ϊ��Ԫ���л��֡�
//���������ǣ���A[p]��A[left]������Ȼ����ԭ�ȵ�Partition������д������
int randPartition(int A[],int left,int right){
	int p = (int)(round(1.0*rand()/RAND_MAX * (right-left) + left));
	swap(A[p],A[left]);			//include <algorithm>
	
	int temp = A[left];		//��A[left]�������ʱ����temp
	while(left < right){
		while(left < right && A[right] > temp) right--;
		A[left]=A[right];
		while(left < right && A[left] <= temp ) left++;
		A[right]=A[left];
	} 
	A[left] = temp;
	return left;
} 

int main(){
	

	return 0;
}

