//日期：2018/4/22 时间：
/*
需要注意的问题，产生排序序列的时候特别要注意。尤其是 46行 testee[j].local_rank=j-total+1;	
												以及 60行 testee[i].final_rank=i+1; 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <algorithm>
using namespace std;

struct stu{
	char registration_number[14];
	int score;
	int final_rank,location_number,local_rank;
}testee[300010]; 

bool cmp(stu a,stu b){
	if(a.score != b.score)	return a.score>b.score;		//分数从高到低排序
	else	return strcmp(a.registration_number,b.registration_number)<0;	//按字母表升序排列 
}

int main(){
	int N;	//test locations
	scanf("%d",&N);
	
	int total=0;		//total number of testees 
	for(int i=0;i<N;i++){
		int K;
		scanf("%d",&K);
		
		for(int j=0;j<K;j++){
			//getchar();		//吸取换行符 
			scanf("%s %d",testee[j+total].registration_number,&testee[j+total].score);		//连续存放参加测试者的信息 
			testee[j+total].location_number=i+1;		//存放区号 
		}
		
		//对刚输入的信息，即testee[total]-testee[total+K-1]的成绩进行排序。即先产生local_rank
		//局部排序 
		sort(testee+total,testee+total+K,cmp);	
		testee[total].local_rank=1;
		for(int j=total+1;j<total+K;j++){
			//printf("%d \n",j);
			if(testee[j].score == testee[j-1].score)
				testee[j].local_rank=testee[j-1].local_rank;
			else
				testee[j].local_rank=j-total+1;		
		} 
		
		total+=K;
	} 
	
	//全局排序对testee[0]-testee[total-1]的成绩进行排序
	sort(testee,testee+total,cmp);
	testee[0].final_rank=1;
	for(int i=1;i<total;i++){
		if(testee[i].score == testee[i-1].score)
			testee[i].final_rank=testee[i-1].final_rank;
		else
			testee[i].final_rank=i+1;
	} 

	printf("%d\n",total);
	for(int i=0;i<total;i++){
		printf("%s %d %d %d\n",testee[i].registration_number,testee[i].final_rank,testee[i].location_number,testee[i].local_rank);
	}

	return 0;
}

