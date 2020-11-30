//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1005;

struct mc{
	double left;	//�����
	double up;		//���� 
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
	
	double m=0;	//������� 
	for(int i=0;i<n;i++){
		if(mcs[i].left >= d){		//�������� 
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

