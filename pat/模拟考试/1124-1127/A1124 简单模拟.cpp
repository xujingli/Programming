//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

const int maxn = 1005;
char id[maxn][25];		//
char lucky[maxn][25];	//��ѡ�� 

int main(){
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		scanf("%s",id[i]); 
	}
	
	if(s>m || s>n)
		printf("Keep going\n");
	else{
		int c = 0;			//�Ѿ�������
		
	}

	return 0;
}

