//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
//#define p1
#define p2

//*******************************************************************************
#ifdef p2
const int maxn = 100;
struct node{
	int x,y;
	int step;
}S,T,Node;					//S为起点，T为中点，Node为临时节点

int n,m;
char maze[maxn][maxn];		//迷宫信息
bool inq[maxn][maxn] = {false};	//记录位置(x,y)是否已入过队
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

//检测位置(x,y)是否有效 
bool test(int x,int y){
	if(x>=n || x<0 || y>=m || y<0)	return false;
	if(maze[x][y]=='*')	return false;
	if(inq[x][y] == true)	return false;	//已经入过队
	return true; 
}

int BFS(){
	queue<node> q;
	q.push(S);			//起点
	while(!q.empty()){
		node top = q.front();		//取出队首元素 
		q.pop(); 
		if(top.x == T.x && top.y == T.y){
			return top.step;		//终点，直接返回最少步数 
		}
		for(int i=0;i<4;i++){
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if(test(newx,newy)){	//位置()有效 
				Node.x = newx,Node.y = newy;
				Node.step = top.step + 1;	//Node层数为top的层数加一
				q.push(Node);
				inq[newx][newy] = true; 
			} 
		}
	} 
	
	return -1;	//无法到达 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();			//过滤上一行的换行符
		for(int j=0;j<m;j++){
			maze[i][j] = getchar();
		} 
		maze[i][m+1]='\0';	//补上结束符 
	}
	scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);		//起点和终点坐标
	S.step=0;
	printf("%d\n",BFS()); 
	
	
	return 0;
} 
/*
测试数据： 
5 5
.....
.*.*.
.*S*.
.***.
...T*
2 2 4 3
*/ 


#endif
//*******************************************************************************
#ifdef p1
const int maxn = 100;
struct node{
	int x,y;	//位置(x,y) 
}Node;

int n,m;		//矩阵大小为n*m
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};		//记录位置(x,y)是否已入队列
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool judge(int x,int y){			//判断坐标(x,y)是否需要访问 
	//越界 
	if(x>=n || x<0 || y>m || y<0) return false;
	//当前位置为0，或(x,y)已入过队列，返回false
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;
	
	//以上都不满足，返回true
	return true; 
}

//BFS函数访问位置(x,y)所在块，将该块中所有'1'的inq都设置为true 
void BFS(int x,int y){
	queue<node> q;
	Node.x = x,Node.y = y;		//当前节点坐标
	q.push(Node);		//将节点Node入队
	inq[x][y] = true;
	while(!q.empty()){
		node top = q.front();		//取出队首元素
		q.pop();				//队首元素出队
		for(int i=0;i<4;i++){
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if(judge(newx,newy)){	//如果新位置(newX,newY)需要访问 
				//设置Node坐标为(newX,newY)
				Node.x = newx,Node.y = newy;
				q.push(Node);		//将节点Node加入队列 
				inq[newx][newy] = true; //设置位置(newx,newy)已入队列 
			}
		} 
	} 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			scanf("%d",&matrix[x][y]);
		}
	}
	int ans = 0;		//存放块数
	
	for(int x=0;x<n;x++){		//枚举每一个位置 
		for(int y=0;y<m;y++){
			//如果元素为1，且未入过队
			 if(matrix[x][y] == 1 && inq[x][y] == false){
			 	ans++;		//块数加一
				BFS(x,y);	//访问整个块，将该块所有"1"的inq都标记为true 
			 }
		}
	} 
	printf("%d\n",ans);

	return 0;
}
#endif
