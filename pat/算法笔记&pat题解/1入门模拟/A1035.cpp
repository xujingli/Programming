//����ϸ�£���ϸ����
//13:23- 13:55
/*
�ӱ����У�����̵���ʶ�������ȿ��ǳ�֣����ʱ���ٻ�ʱ�䡣 ���������ң�����Ҫdebug����
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char name[15];
	char pw[15];
}users[1005];		//������һǧ���û������� 

int main(){
	int N;
	scanf("%d",&N);
	
	int M=0;		//����ͳ�Ʊ��޸��û�������,MҲ��num����ĳ��� 
	int num[1001];	//������ű��޸ĵ��û����±ꡣ��ӡʱ���δ�ӡ users[num[i]].name .pw����
	for(int i=0;i<N;i++){
		scanf("%s %s",users[i].name,users[i].pw);
		
		int flag=0;		//�޸ı�ǣ�һ������������޸����飬flag�ͻ��Ϊ1 
		for(int j=0;j<strlen(users[i].pw);j++){
			if(users[i].pw[j]=='1') {users[i].pw[j]='@'; flag=1;}
			if(users[i].pw[j]=='0') {users[i].pw[j]='%'; flag=1;}
			if(users[i].pw[j]=='l') {users[i].pw[j]='L'; flag=1;}
			if(users[i].pw[j]=='O') {users[i].pw[j]='o'; flag=1;}
		}
		if(flag==1){	
			num[M++]=i;		//������޸ģ�M++,���Ұ��޸ĵ��±�����num������ 
		}
		 
	}
	
	if(M==0){
		if(N==1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified",N);
	}
	else if(M!=0){
		printf("%d\n",M); 
		for(int i=0;i<M;i++)
			printf("%s %s\n",users[num[i]].name,users[num[i]].pw);
	}

	return 0;
}

