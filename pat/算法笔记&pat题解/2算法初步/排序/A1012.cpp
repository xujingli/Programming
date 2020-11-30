//日期：2018/4/23 时间：20:25-21:40  8:10-8:33 AC 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Stu{
	char id[7];
	int C,M,E,A;
	int rC,rM,rE,rA;
}stu[2010];

bool cmpC(Stu a,Stu b){
	return a.C>b.C;
}

bool cmpE(Stu a,Stu b){
	return a.E>b.E;
}

bool cmpM(Stu a,Stu b){
	return a.M>b.M;
}

bool cmpA(Stu a,Stu b){
	return a.A>b.A;
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=0;i<N;i++){
		scanf("%s %d %d %d",stu[i].id,&stu[i].C,&stu[i].M,&stu[i].E);
		stu[i].A=(stu[i].C+stu[i].M+stu[i].E)/4;
	}
	//下面进行排序，分别找出每个人的C M E A的排名
	sort(stu,stu+N,cmpC);
	stu[0].rC=1;
	for(int i=1;i<N;i++){
		if(stu[i].C==stu[i-1].C)
			stu[i].rC=stu[i-1].rC;
		else
			stu[i].rC=i+1;
	}

	//printf("%d\n",stu[2].rC);
	
	sort(stu,stu+N,cmpM);
	stu[0].rM=1;
	for(int i=1;i<N;i++){
		if(stu[i].M==stu[i-1].M)
			stu[i].rM=stu[i-1].rM;
		else
			stu[i].rM=i+1;
	}
	
	sort(stu,stu+N,cmpE);
	stu[0].rE=1;
	for(int i=1;i<N;i++){
		if(stu[i].E==stu[i-1].E)
			stu[i].rE=stu[i-1].rE;
		else
			stu[i].rE=i+1;
	}
	
	sort(stu,stu+N,cmpA);
	stu[0].rA=1;
	for(int i=1;i<N;i++){
		if(stu[i].A==stu[i-1].A)
			stu[i].rA=stu[i-1].rA;
		else
			stu[i].rA=i+1;
	}
	
	//printf("%d %d %d %d\n",stu[2].rA,stu[2].rC,stu[2].rM,stu[2].rE);
	
	for(int i=0;i<M;i++){
		char id[7];
		scanf("%s",id);
		
		int flag=0;			//判断有没有这个id 
		
		int j;
		for(j=0;j<N;j++){
			if(strcmp(id,stu[j].id)==0){	//有这个id ,j是他的下标 
				flag=1;
				break;
			}
		}
		
		if(flag==0)		//没有这个id 
			printf("N/A\n");
		else{
			int bestrank=stu[j].rA;		//最佳排名
			int cur=0;			//最佳排名的下标 按照ACME的顺序
			char s[4]={'A','C','M','E'};
			if(stu[j].rC < bestrank){	//如果后一个学科的排名比前一个学科的排名靠前，那么就更新最佳排名 
				bestrank=stu[j].rC; 
				cur=1;
			} 
			if(stu[j].rM < bestrank){
				bestrank=stu[j].rM;
				cur=2;
			}
			if(stu[j].rE < bestrank){
				bestrank=stu[j].rE;
				cur=3;
			}
			printf("%d %c\n",bestrank,s[cur]);
		}
		
	}
	
	return 0;
}

