//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 110;
int initial[maxn],second[maxn];			//����
int n;		//���� 
int pos=1;	//�������� 

bool isInsert(){
	int flag=0;
	int first=0;
	if(second[0] > second[1] && second[0]!=initial[0])
		flag = 1;
	for(int i=1;i<n;i++){
		if(second[i-1] > second[i] && second[i]!=initial[i]){
			flag = 1;
			break;
		}
		if(second[i-1] > second[i] && second[i]==initial[i] && first==0){
			first=1;
			pos = i;		//0~pos-1�Ѿ���������ã�����������ѡȡposλ�õ�Ԫ�ز��뵽ǰ�漴�� 
		}
	}
	if(flag == 1) return false;
	else return true;
}

void print(int num[]){
	for(int i=0;i<n;i++){
		printf("%d",num[i]);
		if(i!=n-1)
			printf(" ");
		else
			printf("\n");
	}
}


//��initial������[low,high]��Χ�������µ��� 
//����lowΪ�������ڵ� �����±�,highΪ�ѵ����һ���ڵ�������±� 
void downAdjust(int low,int high){
	int i=low,j = i*2;	//iΪ�������ڵ㣬jΪ�����ӡ�����j���i�����Һ����нϴ��ӵ����ꡮ
	while(j<=high){		//���ں��ӽڵ� 
		//����Һ��Ӵ��ڣ����Һ��ӽڵ��ֵ��������
		if(j+1 <= high && initial[j+1]>initial[j]){
			j=j+1;
		} 
		
		//������������Ȩֵ���������ڵ�i��
		if(initial[j] > initial[i]){
			swap(initial[i],initial[j]);	//���������ڵ�
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

void heapSort(){
	createHeap();
	for(int i=n;i>=1;i--){
		swap(initial[i],initial[1]);
		downAdjust(1,i-1);
		if(initial[i] != second[i]){
			break;
		}
	}
	printf("Heap Sort\n");
	for(int i=1;i<=n;i++){
		printf("%d",initial[i]);
		if(i!=n)
			printf(" ");
		else
			printf("\n");
	}
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&initial[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&second[i]);
	if(isInsert()){
		int temp = second[pos];
		int i;
		for(i=0;i<pos;i++){
			if(temp < second[i]){	//��temp���뵽��i��λ���� 
				break; 
			}
		}
		int j;
		for(j=pos;j>=i+1;j--){
			second[j] = second[j-1];
		}
		second[i] = temp;
		
		printf("Insertion Sort\n");
		print(second);
		
	} else {			//������ 
		//createHeap();
		for(int i=n;i>=1;i--){
			initial[i] = initial[i-1];
			second[i] = second[i-1];
		}
		heapSort();
	}

	return 0;
}

