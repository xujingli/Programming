/*
题意：

考察点：
思路：
易错点：
*/
#include <stdio.h>
#include <stdlib.h>

const int N = 100005;
int father[N];

void initial(){
	for(int i=1;i<=N;i++){
		father[i]=i;
	}
} 

//寻找元素x所在集合的根节点 
int findFather(int x){
	while(x!=father[x]){
		x = father[x];
	}
	return x;
}

int findFather1(int x){	//查找时压缩路径 
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	
	while(a!=father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int FaA = findFather(a);
	int FaB = findFather(b);
	if(FaA != FaB){
		FaA = father[FaB];
	}
} 

int main(){


	return 0;
}

