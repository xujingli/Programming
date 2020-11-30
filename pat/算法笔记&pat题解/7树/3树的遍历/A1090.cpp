//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];	//����� 
double p,r;
//maxDepthΪ�����ȣ�numΪ�����ȵ�Ҷ�ڵ����
int n,maxDepth = 0, num = 0;

void DFS(int index,int depth){
	if(child[index].size() == 0){
		//�ﵽҶ�ڵ�
		if(depth > maxDepth){
			maxDepth = depth;		//���������� 
			num = 1;				//���������ȵ�Ҷ�ڵ����Ϊ1 
		} else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
} 

int main(){
	int father,root;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;					//���ٷ�������100
	for(int i=0;i<n;i++){
		scanf("%d",&father);
		if(father != -1){
			child[father].push_back(i);		//i��father���ӽڵ� 
		} else{
			root = i;						//���ڵ� 
		}
	} 
	DFS(root,0);			//DFS���
	printf("%.2f %d\n",p * pow(1+r,maxDepth),num); 

	return 0;
}

