//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
const int maxn = 1000005;
int floor[maxn]={0};

int main(){
	int n;
	scanf("%d",&n);
	
	long long res=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&floor[i]);
		int u = floor[i] - floor[i-1];
		if(u>=0) 			//向上升 
			res += u * 6;
		else{
			res += -1 * u * 4;
		}
		res += 5;
	}
	
	printf("%lld",res);

	return 0;
}

