//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;		
	scanf("%d",&n);	//输入一个整数
	 
	int count=0;	//count记录需要多少步 
	while(n!=1){
		if(n%2 == 0)//偶数
			n/=2;
		else		//奇数 
			n=(n*3+1)/2;
		count++;	//进行一步 
	} 

	printf("%d\n",count);//输出步数 
	return 0;
}

