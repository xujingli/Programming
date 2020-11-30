//���ڣ�2018/ ʱ�䣺
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
}S,T,Node;					//SΪ��㣬TΪ�е㣬NodeΪ��ʱ�ڵ�

int n,m;
char maze[maxn][maxn];		//�Թ���Ϣ
bool inq[maxn][maxn] = {false};	//��¼λ��(x,y)�Ƿ��������
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

//���λ��(x,y)�Ƿ���Ч 
bool test(int x,int y){
	if(x>=n || x<0 || y>=m || y<0)	return false;
	if(maze[x][y]=='*')	return false;
	if(inq[x][y] == true)	return false;	//�Ѿ������
	return true; 
}

int BFS(){
	queue<node> q;
	q.push(S);			//���
	while(!q.empty()){
		node top = q.front();		//ȡ������Ԫ�� 
		q.pop(); 
		if(top.x == T.x && top.y == T.y){
			return top.step;		//�յ㣬ֱ�ӷ������ٲ��� 
		}
		for(int i=0;i<4;i++){
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if(test(newx,newy)){	//λ��()��Ч 
				Node.x = newx,Node.y = newy;
				Node.step = top.step + 1;	//Node����Ϊtop�Ĳ�����һ
				q.push(Node);
				inq[newx][newy] = true; 
			} 
		}
	} 
	
	return -1;	//�޷����� 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();			//������һ�еĻ��з�
		for(int j=0;j<m;j++){
			maze[i][j] = getchar();
		} 
		maze[i][m+1]='\0';	//���Ͻ����� 
	}
	scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);		//�����յ�����
	S.step=0;
	printf("%d\n",BFS()); 
	
	
	return 0;
} 
/*
�������ݣ� 
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
	int x,y;	//λ��(x,y) 
}Node;

int n,m;		//�����СΪn*m
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};		//��¼λ��(x,y)�Ƿ��������
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool judge(int x,int y){			//�ж�����(x,y)�Ƿ���Ҫ���� 
	//Խ�� 
	if(x>=n || x<0 || y>m || y<0) return false;
	//��ǰλ��Ϊ0����(x,y)��������У�����false
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;
	
	//���϶������㣬����true
	return true; 
}

//BFS��������λ��(x,y)���ڿ飬���ÿ�������'1'��inq������Ϊtrue 
void BFS(int x,int y){
	queue<node> q;
	Node.x = x,Node.y = y;		//��ǰ�ڵ�����
	q.push(Node);		//���ڵ�Node���
	inq[x][y] = true;
	while(!q.empty()){
		node top = q.front();		//ȡ������Ԫ��
		q.pop();				//����Ԫ�س���
		for(int i=0;i<4;i++){
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if(judge(newx,newy)){	//�����λ��(newX,newY)��Ҫ���� 
				//����Node����Ϊ(newX,newY)
				Node.x = newx,Node.y = newy;
				q.push(Node);		//���ڵ�Node������� 
				inq[newx][newy] = true; //����λ��(newx,newy)������� 
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
	int ans = 0;		//��ſ���
	
	for(int x=0;x<n;x++){		//ö��ÿһ��λ�� 
		for(int y=0;y<m;y++){
			//���Ԫ��Ϊ1����δ�����
			 if(matrix[x][y] == 1 && inq[x][y] == false){
			 	ans++;		//������һ
				BFS(x,y);	//���������飬���ÿ�����"1"��inq�����Ϊtrue 
			 }
		}
	} 
	printf("%d\n",ans);

	return 0;
}
#endif
