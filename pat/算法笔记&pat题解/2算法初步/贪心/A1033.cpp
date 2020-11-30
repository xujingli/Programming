//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn=510; 

struct station{
	double price,d;	//油价和与杭州的距离 
}stations[maxn];

bool cmp(station a,station b){
	return a.d < b.d;
}

int main(){
	double Cmax,D,Davg;//邮箱容量，杭州与目的城市的距离，一单位油能跑多少距离，设为double型变量 
	int N;			//加油站个数 1
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&stations[i].price,&stations[i].d);
	
	sort(stations,stations+N,cmp);
	for(int i=0;i<N;i++)
		printf("%.2lf %d\n",stations[i].price,(int)stations[i].d);

	return 0;
}

