//日期：2018/6/2 时间：14:18-13:11
/*
因为起初没有注意到会有重复检查的问题，输出的结果错误， 见78行 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int neednum[62],provnum[62];	// 需要的和商店提供的 每一种的个数。0~25为'a'~'z'.26~51为'A'~'Z'.52~61为'0'~'9'
	memset(neednum,0,sizeof(neednum));
	memset(provnum,0,sizeof(provnum));
	
	char prov[1005],need[1005];
	scanf("%s",prov);
	scanf("%s",need);
	
	//把输入信息转换到neednum和provnum中。即统计每种珠子的个数
	int cur;
	for(int i=0;i<strlen(prov);i++){
		if(prov[i]>='0' && prov[i]<='9'){
			cur=prov[i]-'0'+52;
			provnum[cur]++;
		}
		else if(prov[i]>='a' && prov[i]<='z'){
			cur=prov[i]-'a';
			provnum[cur]++;
		}
		else if(prov[i]>='A' && prov[i]<='Z'){
			cur=prov[i]-'A'+26;
			provnum[cur]++;
		}
	}
	
	for(int i=0;i<strlen(need);i++){
		if(need[i]>='0' && need[i]<='9'){
			cur=need[i]-'0'+52;
			neednum[cur]++;
		}
		else if(need[i]>='a' && need[i]<='z'){
			cur=need[i]-'a';
			neednum[cur]++;
		}
		else if(need[i]>='A' && need[i]<='Z'){
			cur=need[i]-'A'+26;
			neednum[cur]++;
		}
	}
	//处理完毕，现在neednum中存放的是对每一种珠子的需求数量，provnum中存放可以提供珠子的数量
/*	
	for(int i=0;i<62;i++){
		if(neednum[i]!=0)
			printf("%d %d\n",i,neednum[i]);
	}
*/	
	//下面是判断，如果该满足要求，那么输出Yes，并且输出需求和提供的字符串长度之差。
	//如果不满足要求，那么输出No,并且记录缺失的个数
	int flag=0;
	int num=0;	//记录缺少珠子的个数，当flag为1时输出
	for(int i=0;i<strlen(need);i++){
		if(need[i]>='0' && need[i]<='9'){
			cur=need[i]-'0'+52;
		}
		else if(need[i]>='a' && need[i]<='z'){
			cur=need[i]-'a';
		}
		else if(need[i]>='A' && need[i]<='Z'){
			cur=need[i]-'A'+26;
		}	//设置游标 
		
		if(provnum[cur] >= neednum[cur]){	//满足需求 
			continue;
		} 
		else{
			flag=1;	//不满足需求 
			num+=(neednum[cur] - provnum[cur]);
			neednum[cur]=provnum[cur]=0;		//设为0，防止二次判断，增加num数量 
		}
	} 
	
	if(flag==0){
		printf("Yes %d",strlen(prov)-strlen(need));
	}else{
		printf("No %d",num);
	}

	return 0;
}

