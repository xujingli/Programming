//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	double seg[10005];
	double total = 0;
	for(int i=0;i<n;i++){
		scanf("%lf",&seg[i]);
		total += seg[i];
	}
	
	sort(seg,seg+n);
	
	double tmp = (seg[0]+seg[1]) / 2;
	for(int i=2;i<n;i++){
		tmp = (tmp + seg[i]) / 2;
	}
	int res = floor(tmp);
	printf("%d",res);

	return 0;
}

