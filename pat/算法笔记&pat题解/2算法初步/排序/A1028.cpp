//日期：2018/4/29 时间：11:45-12:04  AC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct stu{
	char id[7],name[10];
	int grade;
}studs[100010];

bool cmp1(stu a,stu b){
	return strcmp(a.id,b.id)<0;
}

bool cmp2(stu a,stu b){
	if(strcmp(a.name,b.name)==0)
		return strcmp(a.id,b.id)<0;
	return strcmp(a.name,b.name) < 0;
}

bool cmp3(stu a,stu b){
	if(a.grade == b.grade)
		return strcmp(a.id,b.id)<0;
	return a.grade < b.grade;
}

int main(){
	int N,C;
	scanf("%d %d",&N,&C); 
	for(int i=0;i<N;i++)
		scanf("%s %s %d",studs[i].id,studs[i].name,&studs[i].grade);
	
	if(C==1)
		sort(studs,studs+N,cmp1);
	else if(C==2)
		sort(studs,studs+N,cmp2);
	else if(C==3)
		sort(studs,studs+N,cmp3);
	for(int i=0;i<N;i++)
		printf("%s %s %d\n",studs[i].id,studs[i].name,studs[i].grade);

	return 0;
}

