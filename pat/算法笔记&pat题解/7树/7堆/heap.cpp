//���ڣ�2018/ ʱ�䣺
/*
���µ��������ָ��ڵ�ʼ�մ�������Ҷ�ڵ㡣һֱ���¡�
���ϵ��������Ҷ�ڵ���ڸ��׽ڵ㣬�ͽ���λ�á�ʹ�ø��ڵ�ʼ�մ����ӽڵ�

���ѣ�    ��n/2����ʼ���µ�����������ɺ�����Ԫ�ؾ��ڸ��ڵ�
���룺    �ѽڵ���ڶѵ���󣬴��������λ�ÿ�ʼ ���ϵ���
ɾ���Ѷ�Ԫ�أ�	  �ѵ�һ��Ԫ��λ��ɾ���������һ���ڵ�ŵ���һ��λ�ã�Ȼ��Ӵ˿�ʼ���µ���

������  ���ա�ɾ�����ķ�����ɾ����Ԫ�أ�����ɾ�����Ԫ�طŵ���󡣴ӵ�һ��Ԫ�ؿ�ʼ���µ�����
 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100;
int heap[maxn],n=10;		//heapΪ�ѣ�nΪԪ�ظ���

//��heap������[low,high]��Χ�������µ��� 
//����lowΪ�������ڵ� �����±�,highΪ�ѵ����һ���ڵ�������±� 
void downAdjust(int low,int high){
	int i=low,j = i*2;	//iΪ�������ڵ㣬jΪ�����ӡ�����j���i�����Һ����нϴ��ӵ����ꡮ
	while(j<=high){		//���ں��ӽڵ� 
		//����Һ��Ӵ��ڣ����Һ��ӽڵ��ֵ��������
		if(j+1 <= high && heap[j+1]>heap[j]){
			j=j+1;
		} 
		
		//������������Ȩֵ���������ڵ�i��
		if(heap[j] > heap[i]){
			swap(heap[i],heap[j]);	//���������ڵ�
			i=j;		//�������£��������� 
			j=2*i;
		} else {
			break;		//���ӽڵ��Ȩֵ�����������ڵ�iС���������� 
		}
	}	
} 

//����
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
} 

//ɾ���Ѷ�Ԫ��,�����һ��Ԫ�طŵ��Ѷ���Ȼ�����µ��� 
void deleteTop(){
	heap[1] = heap[n--];
	downAdjust(1,n);
} 

//����Ԫ�أ���Ԫ�ز��뵽�ѵ����Ȼ�����ϵ���
//����lowһ����Ϊ1��high��ʾ�������ڵ�������±� 
void upAdjust(int low,int high){
	int i=high,j=i/2;			//iΪ�������ڵ㣬jΪ�丸�� 
	while(j>=low){				//������[low,high]��Χ�� 
		//����ȨֵС���������ڵ�i��Ȩֵ
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=i/2;
		} else {
			break;
		}
	}
} 

void insert(int x){
	heap[++n] = x;
	upAdjust(1,n);
} 

//������˼�룺����->����Ѷ�Ԫ��->�Ѷѵ�Ԫ�طŵ��Ѷ�->�������µ���->����Ѷ�Ԫ��->......
void heapSort(){
	createHeap();
	for(int i=n;i>=1;i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
	}
} 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&heap[i]);
	}
	heapSort();
	for(int i=1;i<=n;i++){
		printf("%d",heap[i]);
		if(i!=n)
			printf(" ");
		else printf("\n");
	}

	return 0;
}

