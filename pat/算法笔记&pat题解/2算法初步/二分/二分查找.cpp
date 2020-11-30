//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

//A[]Ϊ�ϸ�������У�leftΪ�����½磬 rightΪ�����Ͻ磬xΪ����ѯ����
//��������Ϊ����ұ�[left,right]������ĳ�ֵΪ[0,n-1]
int binarySearch(int A[],int left,int right,int x){
	int mid;
	while(left <= right){		//���left>right��û�취�γɱ������� 
		mid = (right + left) / 2;	//ȡ�е�
		if(A[mid] == x)	return mid;	//�ҵ�x,�����±�
		else if(A[mid] > x) {		//�м��������x 
			right = mid - 1;		//����������[left,mid-1]���� 
		}else{						//�м����С��x 
			left = mid + 1;			//����������[mid+1,right]���� 
		}
	}
	return -1;		//����ʧ�ܣ�����-1 
} 

//�����������A�е�Ԫ�ؿ����ظ�����������е�һ�����ڵ���x��λ��L, �Լ���һ������x��λ��R,
//����Ԫ��x�������еĴ��������������ҿ�����[L,R) 

//1���������е�һ�����ڵ���x��Ԫ�ص�λ�� 
//���ֵĳ�������Ӧ���ܸ��ǵ����п��ܷ��صĽ���������½���0�������Ͻ���n������n-1����Ϊ����Ԫ�ؿ��ܱ����е�Ԫ�ض��� 
//�������½�Ϊ����ұ�����[left,right],�����ֵΪ[0,n] 
int lower_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){		//��[left,right]��˵��left==right��ζ���ҵ�Ψһ��λ�� 
		mid = (left+right)/2;		//ȡ�е�
		if(A[mid] >= x){
			right = mid;		//������������� 
		}else{
			left = mid+1;
		}
	}
	return left; 
} 

//2���������е�һ������x��Ԫ�ص�λ��
//�������½�Ϊ����ұ�����[left,right],�����ֵΪ[0,n] 
int upper_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){
		mid = (left + right)/2;
		if(A[mid] > x){
			right = mid;
		}else{		//A[mid] <= x 
			left = mid+1;
		}
	}
	return left;
}

int main(){
	const int n=10; 
	int A[n] = {1,3,4,6,7,8,10,11,12,15};
	
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));

	return 0;
}



