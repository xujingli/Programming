//日期：2018/4/29 时间：12:46-13:03 暂停	4/30 9:50-12:00	诸多错误  13:00-13:20 19/25
/*
见《上机训练》P112 
分为三种情况：
	1）全场都没有提交
	2）没有能通过编译的提交
	3）有能通过编译的提交
将无法通过编译的提交得分记为0，表示该题有过提交。
1）或2）的考生不需要输出。
但是某个考生的所有通过编译的提交都为0分，这是考生的成绩为0分，但是也要被输出。 

反思：你急着干什么呢？题目都不审清楚，都不理解清楚就去做题，急着去死吗？ 
*/				 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 10010;
struct Student{
	int id;
	int score[6];	//每道题的得分 
	bool flag;
	int score_all;
	int solve;		//完美解题数 
}stu[maxn]; 

int n,k,m;
int full[6];		//每道题的满分
bool cmp(Student a,Student b){
	if(a.score_all != b.score_all)	return a.score_all > b.score_all;
	else if(a.solve != b.solve)	return a.solve > b.solve;
	else return a.id < b.id;
} 

void init(){	//初始化 
	for(int i=1 ;i <= n ;i++){
		stu[i].id = i;
		stu[i].score_all = 0;
		stu[i].solve = 0;
		stu[i].flag = false;		//初始化为没有能通过编译的提交
		memset(stu[i].score,-1,sizeof(stu[i].score));	//题目得分标记为-1 
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i=1;i<=k;i++){			//分值 
		scanf("%d",&full[i]);
	}
	
	int u_id,p_id,score_obtained;	//考生id,题目id，所获分数
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		
		if(score_obtained != -1)	//若不是编译错误，则该考生有能通过编译的提交
			stu[u_id].flag = true;
		
		if(score_obtained == -1 && stu[u_id].score[p_id] == -1)	//某题第一次编译错误，分值记为0分，便于输出
			stu[u_id].score[p_id] = 0;
		
		if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id])	//某题第一次获得满分，完美解题数加一
			stu[u_id].solve++;
			
		if(score_obtained > stu[u_id].score[p_id]) 	//某题获得更高的分值，则覆盖
			stu[u_id].score[p_id] =  score_obtained;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j] != -1){	//计算总分
				stu[i].score_all += stu[i].score[j]; 
			}
		}
	}
	
	sort(stu+1,stu+n+1,cmp);
	int r = 1;	//当前排名
	for(int i=1;i<=n && stu[i].flag == true;i++){
		if(i>1 && stu[i].score_all != stu[i-1].score_all)	//当前考生分数低于前一位考生分数，则排名为在该考生之前的总考生数
			r=i;
			
		printf("%d %05d %d",r,stu[i].id,stu[i].score_all);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j] == -1)
				printf(" -");
			else
				printf(" %d",stu[i].score[j]); 
		} 
		printf("\n");
	} 
	
	return 0;
}
