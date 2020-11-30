//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

#define p1
//#define p2

#ifdef p2
int main(){
	int n;
	double v,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&v);
		ans += v*i*(n+1-i);
	}
	printf("%.2f\n",ans);
	return 0;
}

#endif 

#ifdef p1
const int maxn = 100005;

int main(){
	int n;
	scanf("%d",&n);
	
	double num[maxn],S[maxn]={0};
	for(int i=1;i<=n;i++){
		scanf("%lf",&num[i]);
		S[i] = S[i-1] + num[i];
	} 
	
	double res=0;
	for(int i=1;i<=n;i++){
		res += i*S[i];
		res -= (n-i) * S[i];
	}
	printf("%.2lf",res);

	return 0;
}
#endif
