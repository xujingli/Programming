//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
const int maxn = 100005;
int number[maxn];

int main(){
	int N;
	scanf("%d",&N);
	int pz;					//记录0的位置坐标 
	for(int i=0;i<N;i++){
		scanf("%d",&number[i]);
		if(number[i]==0)
			pz=i; 
	}
		
	
	

	return 0;
}

