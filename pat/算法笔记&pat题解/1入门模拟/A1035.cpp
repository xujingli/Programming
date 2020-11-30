//耐心细致，仔细分析
//13:23- 13:55
/*
从本题中，我深刻地认识到：事先考虑充分，编程时就少花时间。 否则程序混乱，你又要debug半天
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char name[15];
	char pw[15];
}users[1005];		//创建有一千个用户的数组 

int main(){
	int N;
	scanf("%d",&N);
	
	int M=0;		//用来统计被修改用户的数量,M也是num数组的长度 
	int num[1001];	//用来存放被修改的用户的下标。打印时依次打印 users[num[i]].name .pw即可
	for(int i=0;i<N;i++){
		scanf("%s %s",users[i].name,users[i].pw);
		
		int flag=0;		//修改标记，一旦进入下面的修改数组，flag就会变为1 
		for(int j=0;j<strlen(users[i].pw);j++){
			if(users[i].pw[j]=='1') {users[i].pw[j]='@'; flag=1;}
			if(users[i].pw[j]=='0') {users[i].pw[j]='%'; flag=1;}
			if(users[i].pw[j]=='l') {users[i].pw[j]='L'; flag=1;}
			if(users[i].pw[j]=='O') {users[i].pw[j]='o'; flag=1;}
		}
		if(flag==1){	
			num[M++]=i;		//如果被修改，M++,并且把修改的下标存放在num数组中 
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

