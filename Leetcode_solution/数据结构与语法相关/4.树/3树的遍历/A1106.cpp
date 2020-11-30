//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100005;
int n;
double p,r;
vector<int> suply[maxn];

double lowest=9876543210;
int num=0;
int level=0;

void DFS(int root,int level){
	if(suply[root].size() == 0){		//根节点，计算售价 
		double price = pow(1+r,level) * p;
		if(price < lowest){
			lowest = price;
			num=1;
		} else if(price == lowest){
			num++;
		}
	}
	
	for(int i=0;i<suply[root].size();i++){
		DFS(suply[root][i],level+1);
	}
}

int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	
	int child,k;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			suply[i].push_back(child);
		}
	}
	
	DFS(0,0);
	
	printf("%.4f %d",lowest,num); 
	
	return 0;
}

