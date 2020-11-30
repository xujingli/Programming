//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = {0};		//每一位左边（含）P的个数 

int main(){
	gets(str);
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(i>0){	//如果不是0号位 
			leftNumP[i] = leftNumP[i-1];
		}
		if(str[i] == 'P'){
			leftNumP[i]++; 
		}
	}
	int ans = 0,rightNumT = 0;		//ans为答案 
	for(int i=len-1;i>=0;i--){
		if(str[i]=='T'){
			rightNumT++;
		}else if(str[i] == 'A'){
			ans = (ans + leftNumP[i]*rightNumT) % MOD;
		}
	}
	
	printf("%d\n",ans);

	return 0;
}

