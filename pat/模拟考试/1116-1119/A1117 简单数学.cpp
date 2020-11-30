//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;

bool cmp(int a,int b){
	return a>=b;
}

int main(){
	int n;
	scanf("%d",&n); 
	int l[maxn];
	for(int i=1;i<=n;i++)
		scanf("%d",&l[i]);
		
	sort(l+1,l+1+n,cmp);
	
	int i;
	for(i=1;i<=n;i++){
		if(l[i]<=i)
			break;
	}
	printf("%d",i-1);

	return 0;
}

