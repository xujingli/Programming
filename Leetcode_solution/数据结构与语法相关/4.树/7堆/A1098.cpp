//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 110;
int initial[maxn],second[maxn];			//数组
int n;		//长度 
int pos=1;	//排序坐标 

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
			pos = i;		//0~pos-1已经插入排序好，接下来就是选取pos位置的元素插入到前面即可 
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


//对initial数组在[low,high]范围进行向下调整 
//其中low为欲调整节点 数组下标,high为堆的最后一个节点的数组下标 
void downAdjust(int low,int high){
	int i=low,j = i*2;	//i为欲调整节点，j为其左孩子。下面j存放i的左右孩子中较大孩子的坐标‘
	while(j<=high){		//存在孩子节点 
		//如果右孩子存在，且右孩子节点的值大于左孩子
		if(j+1 <= high && initial[j+1]>initial[j]){
			j=j+1;
		} 
		
		//如果孩子中最大权值比欲调整节点i大
		if(initial[j] > initial[i]){
			swap(initial[i],initial[j]);	//交换两个节点
			i=j;		//从上往下，继续调整 
			j=2*i;
		} else {
			break;		//孩子节点的权值都比欲调整节点i小，调整结束 
		}
	}	
} 

//建堆
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
			if(temp < second[i]){	//把temp插入到第i个位置上 
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
		
	} else {			//堆排序 
		//createHeap();
		for(int i=n;i>=1;i--){
			initial[i] = initial[i-1];
			second[i] = second[i-1];
		}
		heapSort();
	}

	return 0;
}

