//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = {0};		//ÿһλ��ߣ�����P�ĸ��� 

int main(){
	gets(str);
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(i>0){	//�������0��λ 
			leftNumP[i] = leftNumP[i-1];
		}
		if(str[i] == 'P'){
			leftNumP[i]++; 
		}
	}
	int ans = 0,rightNumT = 0;		//ansΪ�� 
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

