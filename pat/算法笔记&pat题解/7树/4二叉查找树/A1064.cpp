//日期：2018/ 时间：
//BST的中序遍历序列 等于 从小到大排序结果 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;

//n为节点数，number用于存放节点权值，CBT用于存放完全二叉树
//index从小到大枚举number数组 
int n,number[maxn],CBT[maxn],index=0;

void inOrder(int root){
	if(root > n)	return;
	inOrder(root * 2);		//往左子树递归
	CBT[root] = number[index++];	//根节点处赋值number[index]。中序遍历=中序遍历序列 
	inOrder(root * 2 + 1); 
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	sort(number,number+n);		//从小到大排序 ，得到BST中序遍历的结果 
	
	inOrder(1);					//1号位为根节点
	for(int i=1;i<=n;i++){
		printf("%d",CBT[i]);
		if(i<n) printf(" ");
	} 

	return 0;
}

