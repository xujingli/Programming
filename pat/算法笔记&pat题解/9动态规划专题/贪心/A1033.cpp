//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn=510; 

struct station{
	double price,d;	//�ͼۺ��뺼�ݵľ��� 
}stations[maxn];

bool cmp(station a,station b){
	return a.d < b.d;
}

int main(){
	double Cmax,D,Davg;//����������������Ŀ�ĳ��еľ��룬һ��λ�����ܶ��پ��룬��Ϊdouble�ͱ��� 
	int N;			//����վ���� 1
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&stations[i].price,&stations[i].d);
	
	sort(stations,stations+N,cmp);
	for(int i=0;i<N;i++)
		printf("%.2lf %d\n",stations[i].price,(int)stations[i].d);

	return 0;
}

