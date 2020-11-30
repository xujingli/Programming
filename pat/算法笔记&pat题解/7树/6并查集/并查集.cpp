//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

const int N = 100005;
//Union Find Set
int father[N]; 				//father[x]中存放元素x的父亲节点 
//初始化
void initial(){
	for(int i=1;i<=N;i++){
		father[i]=i;		//一开始，每一个元素都是独立的一个集合。 
	}
}

//寻找元素x所在集合的根节点 
int findFather(int x){
	while(x!=father[x])
		x=father[x];
	return x; 
}

//合并两个集合，先判断两个元素是否同属于同一个集合，只有当两个元素属于不同集合才合并。
//合并的过程一般是把其中一个集合的根节点的父亲指向另一个集合的根节点 
void Union(int a,int b){
	int FaA = findFather(a);
	int FaB = findFather(b);
	if(FaA != FaB){
		FaA = father[FaB];		//合并 
	} 
}

//查找时压缩路径 
int findFather1(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];			//寻找根节点 
	}//x代表根节点。下面把路径上的所有节点的father都改成根节点
	
	//从a开始 。把a想象成一个指针。指针上移 
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
} 

int main(){
	

	return 0;
}

