//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d",&N); 
	int num[10005],input[100005];
	memset(num,0,sizeof(num));//num[i]��ʾ����i���ֵĴ���
	
	for(int i=0;i<N;i++){
		scanf("%d",&input[i]);
		num[input[i]]++;
	}
	
	int flag=0;
	for(int i=0;i<N;i++){
		if(num[input[i]]==1){
			flag=1;
			printf("%d",input[i]);
			break;
		}
	}
	if(flag==0){
		printf("None");
	}
	

	return 0;
}

