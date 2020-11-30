//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1005;

struct mc{
	double left;	//库存量
	double up;		//单价 
}mcs[maxn];

bool cmp(mc a,mc b){
	return a.up>=b.up;
}

int main(){
	int n;
	double d;
	scanf("%d%lf",&n,&d);

	for(int i=0;i<n;i++){
		scanf("%lf",&mcs[i].left);
	}
	
	double price;
	for(int i=0;i<n;i++){
		scanf("%lf",&price);
		mcs[i].up=((price)/(mcs[i].left));
	}
	
	sort(mcs,mcs+n,cmp); 
	
	double m=0;	//最大收益 
	for(int i=0;i<n;i++){
		if(mcs[i].left >= d){		//满足需求 
			m+= (d * mcs[i].up);
			break;
		}else{
			m+=(mcs[i].up * mcs[i].left);
			d-=mcs[i].left;
		}
	}

	printf("%.2f",m);

	return 0;
}

