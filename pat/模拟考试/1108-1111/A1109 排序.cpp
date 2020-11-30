//日期：2018/ 时间：
//对整体排序，再对每一组人排序（输出即可） 
//一个错误：没有注意字典序排序的顺序 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10005;

struct person{
	char name[10];
	int weight;
}people[maxn];

bool cmp(person a,person b){
	if(a.weight == b.weight)
		return strcmp(a.name,b.name) < 0;
	else
		return a.weight > b.weight;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s %d",people[i].name,&people[i].weight);
	}
	sort(people+1,people+n+1,cmp);
	/*
	for(int i=1;i<=n;i++){
		printf("%s %d\n",people[i].name,people[i].weight);
	}*/

	int m = n - (n/k * (k-1));	//最后一行人数 
	//printf("%d\n",m); 
	//处理最后一行
	if(m%2 == 1){	//奇数 			
		for(int i=1;m-(2*i-1)>0;i++){
			printf("%s ",people[m-(2*i-1)].name);
		}
			
		for(int i=1;i<=m;i+=2){
			printf("%s",people[i].name);
			if(i+2<=m)	printf(" ");
			else printf("\n");
		}
	} else{				//偶数 
		for(int i=0;m-(2*i)>0;i++){
			printf("%s ",people[m-(2*i)].name);
		}
			
		for(int i=1;i<=m;i+=2){
			printf("%s",people[i].name);
			if(i+2<=m)	printf(" ");
			else printf("\n");
		}
	} 

	//再处理其他几行
	int begin = m+1;		//下一行开始的坐标 
	m = n/k;			//每行人数 
	//printf("m: %d\n",m);
	for(int j=2;j<=k;j++){	//2~k行 
		//printf("begin: %d\n",begin);
		//从begin~begin+m-1;共m个数字,与上面相同，只不过是 
		int t = m; 
		if(t%2 == 1){	//奇数 			
			for(int i=1;t-(2*i-1)>0;i++){
				printf("%s ",people[(begin-1) + t-(2*i-1)].name);
			}
				
			for(int i=1;i<=t;i+=2){
				printf("%s",people[(begin-1) + i].name);
				if(i+2<=t)	printf(" ");
				else printf("\n");
			} 
		}else{				//偶数 
			for(int i=0;t-(2*i)>0;i++){
				printf("%s ",people[(begin-1) + t-(2*i)].name);
			}
				
			for(int i=1;i<=t;i+=2){
				printf("%s",people[(begin-1) + i].name);
				if(i+2<=t)	printf(" ");
				else printf("\n");
			}
		} 
		begin = begin + m;	//每一行的开始坐标
	} 

	return 0;
}

/*
11 3
xuj 195
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

*/
