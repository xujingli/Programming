//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;	//sqrt(100001),表示块内元素个数。共317块

stack<int> st;
int block[sqrN+1];		//记录每一块中存在的元素个数 
int table[maxn];	 	//hash数组，记录元素当前存在个数 

void Push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}

void Pop(){
	int x = st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	printf("%d\n",x);
}

void peekMedian(int k){
	int sum = 0;		//存放当前累计存在的数的个数 
	int idx = 0;		//块号
	while(sum + block[idx] < k){	//找到第k大数所在的块号 
		sum += block[idx++];
	} 
	
	int num = idx * sqrN;			//idx号块的第一个数
	while(sum + table[num] < k){
		sum += table[num++];
	} 
	
	printf("%d\n",num);
}

int main(){
	int x,query;
	memset(block,0,sizeof(block));
	memset(table,0,sizeof(table));
	char cmd[20];
	scanf("%d",&query); 
	for(int i=0;i<query;i++){
		scanf("%s",cmd);
		if(strcmp(cmd,"Push") == 0){
			scanf("%d",&x);
			Push(x);
		} else if(strcmp(cmd,"Pop") == 0){
			if(st.empty() == true){
				printf("Invalid\n");
			}else{
				Pop();
			} 
		} else if(strcmp(cmd,"PeekMedian") == 0){
			if(st.empty() == true){
				printf("Invalid\n");
			} else {
				int K = st.size();
				if(K % 2 == 1) K=(K+1)/2;
				else K = K / 2;
				
				peekMedian(K); 
			}
		} 
	}
	
	return 0;
}

