//����ϸ�£���ϸ����
//8:00-8:34
/*
����ԭ��û�п��ǵ�����N=0�����
������
		if(N==0)
			bnum[++len]=0; 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N,b;
	scanf("%d %d",&N,&b);	//ʮ�������ֺͻ��� 
	int bnum[35];		//�������ʮ��������ת���ɵ�b��������
	int len=0;			//������ʾ��������ĳ���
	
	if(N==0)
		bnum[++len]=0;
	
	while(N!=0){
		bnum[++len]=N%b;	//�����±��1��ʼ 
		N/=b;				//��Ȼ�ǵ����ţ����ǲ�Ҫ������Ӱ�챾��Ľ⣬������������ʱ������������� 
	} 
	
	int flag=1;
	for(int i=1;i<=len/2;i++){
		if(bnum[i] != bnum[len+1-i]){
			flag=0;				//������ǣ���������������� 
			printf("No\n");
			break;
		}	
	}
	
	if(flag==1)
		printf("Yes\n"); 
	
	for(int i=len;i>=1;i--){
		if(i!=1)
			printf("%d ",bnum[i]);
		else
			printf("%d",bnum[i]);	
	}
	

	return 0;
}

