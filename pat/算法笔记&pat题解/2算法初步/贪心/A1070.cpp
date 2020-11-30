//���ڣ�2018/ ʱ�䣺
/*
	sort(unitp,unitp+n,cmp);		//���۴Ӵ�С����	
	
	double profit=0;	//����
	int cur=0;			//ָ��ĳ���±� 
	while(d!=0){
		if(amount[cur] >= d){		//��������±��������������������������������߶�Ӧ������ 
			profit+= (d * unitp[cur]);
			break;
		}
		else{				//�����±����������� 
			profit+= price[cur];
			d-=amount[cur];
			cur++;
		}
	} 
	��������Ѿ���������ˣ�������������ֻ��unitp�����ˣ�˳����ˣ��±�Ҳ���ˣ�����price��amount���±껹��ԭ�����±갡�� 
	�ýṹ������� 
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1005;

struct mc{
	double amount;		//���� 
	double unitprice;	//���� 
}mcs[maxn];

bool cmp(mc a,mc b){
	return a.unitprice>=b.unitprice;
} 

int main(){
	int n;
	double d;	//������ 
	scanf("%d%lf",&n,&d);
	
	for(int i=0;i<n;i++)
		scanf("%lf",&mcs[i].amount);
	
	double price;
	for(int i=0;i<n;i++){
		scanf("%lf",&price);			//�����ܼ� 
		mcs[i].unitprice = (price / mcs[i].amount);		//���㵥�� 
	}
	
	sort(mcs,mcs+n,cmp);		//���۴Ӵ�С����	
	
	double profit=0;	//����
	for(int i=0;i<n;i++){
		if(mcs[i].amount >= d){		//��������±��������������������������������߶�Ӧ������ 
			profit+= (d * mcs[i].unitprice);
			break;
		}
		else{				//�����±����������� 
			profit+= mcs[i].amount * mcs[i].unitprice;
			d-=mcs[i].amount;
		}
	} 
	
	printf("%.2lf",profit);

	return 0;
}

