//日期：2018/ 时间： 15分钟 运行超时 30分钟仍然超时！看来不能死磕一题 
//运行超时： 死循环10 + 边界情况2147483647  AC 1小时！！！
//转换成double，等式右边必须也要先强制转换。 
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int change(char num[],int s,int e){
	int n=0;
	for(int i=s;i<=e;i++){
		n = n*10 + (num[i] - '0');
	}
	return n;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char num[15];
		scanf("%s",num);
		int len = strlen(num);
		int N = change(num,0,len-1);
		int N1 = change(num,0,len/2-1);
		int N2 = change(num,len/2,len-1);
		//printf("%d %d %d\n",N,N1,N2);
		int temp = N1 * N2;
		if(N2 == 0 || N1 == 0){
			printf("No\n");
			continue;
		} 
		
		int j = 1;
		while(1){
			double t=(double)temp*j*1.0;
			//printf("%f\n",t);
			//printf("%f\n",(double)N);
			if(t == (double)(N)){
				printf("Yes\n");
				break;
			} else if(t < double(N)){
				j++;
			}else{
				printf("No\n");
				break;
			}
		}
		
		//printf("%d\n",j);
	}

	return 0;
}

