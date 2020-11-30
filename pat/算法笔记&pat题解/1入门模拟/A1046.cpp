#include <stdio.h>
#include <stdlib.h>

//#define p1
/*
p1运行超时，原因：n1的最大值是10000，a->b的最大值是100000.所以以下双层for循环在极端情况下的复杂度是10的九次方
	因此超时 
改进措施：把1到i的总距离放到D[i-1]中，则a->b的顺时针距离就是D[b-1]-D[a-1],逆时针距离就是D[n]-(D[b-1]-D[a-1]) 
*/
#ifdef p1

int main(){
	int n;
	scanf("%d",&n);				//代表n个顶点 1->2->...->n->1
	int D[100001];
	
	int total=0;				//总路程， 
	
	for(int i=1;i<=n;i++){ 
		scanf("%d",&D[i]);		//D[1]~D[n] ，D[i]为i-->i+1的距离 
		total+=D[i];			//总路程 
	} 
 
	int n1;				
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		int a1,b1;				//起点与终点 
		scanf("%d%d",&a1,&b1);
		int a=(a1 < b1 ? a1 : b1);
		int b=(a1 >=b1 ? a1 : b1);	//较小值赋给a,较大的给b 
		
		int len=0;				//先计算顺时针路程，total-len即为反方向路程，取二者的最小值
		for(int j=a;j<b;j++){
			len+=D[j];
		} 
		
		int slen=(len <= (total-len) ? len : (total-len));//shortest length
		 
		printf("%d\n",slen);
	} 
	
    return 0;
}
#endif

#define p2
#ifdef p2
int main(){
	int n;
	scanf("%d",&n);				//代表n个顶点 1->2->...->n->1
	int D[100001];
	D[0]=0;//初始化 
	
	int total=0;				//总路程， 
	
	for(int i=1;i<=n;i++){ 
		int dist;				//dist为i-->i+1的距离 
		scanf("%d",&dist);		//D[1]~D[n] ，D[i]为i-->i+1的距离 
		D[i]=D[i-1]+dist;		//D[n]为总路程 
	} 
	
	int n1;				
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		int a1,b1;				//起点与终点 
		scanf("%d%d",&a1,&b1);
		int a=(a1 < b1 ? a1 : b1);
		int b=(a1 >=b1 ? a1 : b1);	//较小值赋给a,较大的给b 
		
		int len1=D[b-1]-D[a-1],len2=D[n]-(D[b-1]-D[a-1]);	//先计算顺时针路程，total-len即为反方向路程，取二者的最小值
		
		int slen=(len1 <= len2 ? len1 : len2);//shortest length
		 
		printf("%d\n",slen);
	} 

	return 0;
}


#endif 
