//日期：2018/ 时间：
/*
警示：一、审题太慢太慢！半个小时还没有完全搞清楚！为什么不动笔写写画画？？？？？？？？？？？你想死吗？真的到了考试怎么办？
			拿到题目就发呆，呆在那里！能不能提高一点效率！@！！！@！！！！？？？不会可以学，但是态度不端正真的无药可救
启示：一、动笔仔细分析，题目肯定是没错的！ 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include<queue>
using namespace std;

const int maxn = 1010;

struct mouse{
	int weight;
	int R;
}mouse[maxn];

int main(){
	int np,ng,order;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&mouse[i].weight);
	}
	queue<int> q;	//定义一个队列
	for(int i =0;i<np;i++){
		scanf("%d",&order);		//给定序列
		q.push(order);			//按顺序把老鼠们的标号入队 
	} 
	int temp = np,group;		//temp为当前轮的比赛总老鼠数，group为组数
	while(q.size() != 1){
		//计算group，即当前轮分为几组进行比赛
		if(temp % ng ==0)
			group = temp / ng;
		else group = temp / ng + 1;
		
		//枚举每一组，选出该组中老鼠质量最大的
		for(int i=0;i<group;i++){
			int k = q.front();		//k存放该组质量最大的老鼠编号
			for(int j=0;j<ng && i*ng+j<temp;j++){
				int front = q.front();	//队首老鼠编号
				if(mouse[front].weight > mouse[k].weight)
					k = front;			//找出质量最大的老鼠 
				mouse[front].R = group + 1; //该轮老鼠排名为group+1
				q.pop();				//把每只老鼠都出队 
			} 
			q.push(k);				//把胜利的老鼠入队 
		} 
		temp = group;		//group只老鼠晋级，下轮总老鼠数为group 
	} 
	mouse[q.front()].R=1;	//当队列中只剩下一只老鼠时，令其排名为1
	//输出所有老鼠的信息
	for(int i=0;i<np;i++){
		printf("%d",mouse[i].R);
		if(i<np-1) printf(" ");
	} 

	return 0;
}

