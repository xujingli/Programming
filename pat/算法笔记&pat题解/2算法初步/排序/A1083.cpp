//日期：2018/4/30  时间：13:33-13:46 AC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=10000;

struct stu{
	char name[11],id[11];
	int grade;
}studs[maxn];

bool cmp(stu a,stu b){
	return a.grade > b.grade;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %s %d",studs[i].name,studs[i].id,&studs[i].grade);
	}
	int grade1,grade2;
	scanf("%d %d",&grade1,&grade2);
	
	sort(studs,studs+N,cmp);
	int flag=0;			
	for(int i=0;i<N;i++){
		if(studs[i].grade >= grade1 && studs[i].grade <= grade2){
			flag=1;
			printf("%s %s\n",studs[i].name,studs[i].id);
		}
	}
	if(flag==0)
		printf("NONE\n");

	return 0;
}

