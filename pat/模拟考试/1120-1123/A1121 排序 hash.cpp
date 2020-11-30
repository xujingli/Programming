//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int cp[maxn];		//第i个表示i的cp
bool in[maxn] = {false};	//是否参加 
const int INF = 0x7fffffff;

int main(){
	int n;
	scanf("%d",&n);
	
	int n1,n2;
	for(int i=0;i<n;i++){
		scanf("%d %d",&n1,&n2);
		cp[n1] = n2;
		cp[n2] = n1;
	}
	
	int m;
	scanf("%d",&m);
	int query[10005];
	for(int i=0;i<m;i++){
		scanf("%d",&query[i]);
		in[query[i]] = true;
	}
	
	int c = m;
	//printf("m: %d\n",m);
	for(int i=0;i<m;i++){	//query[i]表示这个人编号 
		if(in[cp[query[i]]]){		//如果这个人的cp(cp[query[i]])来了，则把这两个人删了 
			//删除的方法是：query[i]置为无穷大.count--
			 query[i] = INF;
			 c--;
		}
	}
	
	sort(query,query+m);
	printf("%d\n",c);
	for(int i=0;i<c;i++){
		printf("%05d",query[i]);
		if(i<c-1) printf(" ");
	}

	return 0;
}

