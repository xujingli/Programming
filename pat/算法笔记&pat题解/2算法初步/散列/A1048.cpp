//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn=100005;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	int coins[maxn],tmp;		//面值为i的coin有coins[i]个 
	memset(coins,0,sizeof(coins));
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		coins[tmp]++;
	}
	
	int flag=0;
	for(int i=1;i<=(m/2);i++){
		if((i!=(m-i) && coins[i] >=1 && coins[m-i] >=1) || (i==(m-i) && coins[i]>=2)){
			flag=1;
			printf("%d %d",i,m-i);
			break;
		}
	}
	
	if(flag==0)
		printf("No Solution");

	return 0;
}

