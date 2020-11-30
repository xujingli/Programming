//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
	reverse(a+4,a+6);			//反转[it1,it2)
	
	fill(a+6,a+10,233);			//将a[6]~a[9]换成233 
	
	for(int i=-0;i<11;i++)
		printf("%d ",a[i]); 
	printf("\n");
	
	do{
		printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
	}while(next_permutation(a,a+4));

	return 0;
}

