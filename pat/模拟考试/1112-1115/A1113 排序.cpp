//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int total=0;
	
	int num[100005];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		total+=num[i];
	}
	sort(num,num+n);
	int t =0;
	for(int i=0;i<n/2;i++){
		t+=num[i];
	}
	printf("%d %d",n%2,total-t-t);

	return 0;
}

