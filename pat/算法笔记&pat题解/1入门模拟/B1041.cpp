//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d",&N);
	
	char num[1001][];
	int seat[1001];
	for(int i=1;i<=N;i++){
		int temp;
		int cursor=0;		//�α꣬ÿ�ο�ʼʱָ��num[i][0] 
		while((temp=getchar())!=' '){
			num[i][cursor++]=temp;
		}
		scanf("%d %d",);
	} 

	return 0;
}
