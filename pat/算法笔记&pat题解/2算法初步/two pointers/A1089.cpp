//日期：2018/6/14 时间：19:36- 
//本题思路最重要的是 利用归并排序的非递归思想，即可写出下一次归并排序后的结果 
//for(int i=0;i<n;i+=(2*step)) 
//		sort(partial+i,partial+min(i+2*step,n));
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n); 
	int initial[105];
	int partial[105];
	
	for(int i=0;i<n;i++)
		scanf("%d",&initial[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&partial[i]);
		
	//思路：判断他是不是插入排序，如果不是就是归并排序。
	//归并排序的话就确定他的当前步长step.然后输出step*2的排序结果
	//插入排序的话判断他目前已经排到哪里了，将当前值插入前面的输出即可 

	int flag=0;			//2表示归并排序，1表示插入排序 
	int insertcur=0;		//插入排序的坐标。 
	int c;
	for(int c=1;c<n;c++){			//判断是否为插入排序，标准是，前面的升序部分，后面的非升序部分和原数组一样 
		if(partial[c-1] > partial[c]){
			insertcur=c; 
			//printf("%d\n",insertcur);
			break;
		}
	}
	for(int i=insertcur;i<n;i++){
		if(partial[i]!=initial[i]){
			flag = 2;
			break;
		}
		flag=1;
	} 
	
	if(flag == 1){			//将insertcur坐标的数插入到前面已经排好序的数组中（partial[0~insertcur-1]）。
		 printf("Insertion Sort\n");
		 int i;
		 int temp = partial[insertcur];
		 for(i=0;i<insertcur;i++){
		 	if(partial[i]>=temp)		//则把这个数插入到i的位置 
		 		break; 
		 }
		 for(int j=insertcur;j>=i+1;j--){
		 	partial[j]=partial[j-1];
		 }
		 partial[i] = temp;
			
	}else if(flag == 2){
		printf("Merge Sort\n");
		//首先判断步长是多少
		int step=n;
		int temp=1;
		for(int i=1;i<n;i++){
			if(partial[i] >= partial[i-1]){
				temp++;
			}else{
				step = min(step,temp);
				temp=1;
			}
		}
		//printf("%d\n",step);
		//利用归并排序的非递归思想，即可写出下一次归并排序后的结果 
		for(int i=0;i<n;i+=(2*step)) 
			sort(partial+i,partial+min(i+2*step,n));
	}
	
	for(int i=0;i<n;i++){
		if(i != n-1)
			printf("%d ",partial[i]);
		else
			printf("%d",partial[i]);
	}
		

	return 0;
}

