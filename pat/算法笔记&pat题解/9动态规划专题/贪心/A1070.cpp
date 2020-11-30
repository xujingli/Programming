//日期：2018/ 时间：
/*
	sort(unitp,unitp+n,cmp);		//单价从大到小排列	
	
	double profit=0;	//利润
	int cur=0;			//指向某种月饼 
	while(d!=0){
		if(amount[cur] >= d){		//如果此种月饼的数量大于需求量，满足需求，则拿走对应的利润 
			profit+= (d * unitp[cur]);
			break;
		}
		else{				//这种月饼的数量不够 
			profit+= price[cur];
			d-=amount[cur];
			cur++;
		}
	} 
	此类错误已经层出不穷了！！！！！！！只对unitp排序了，顺序变了，下标也变了，可是price和amount的下标还是原来的下标啊！ 
	用结构体更方便 
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1005;

struct mc{
	double amount;		//数量 
	double unitprice;	//单价 
}mcs[maxn];

bool cmp(mc a,mc b){
	return a.unitprice>=b.unitprice;
} 

int main(){
	int n;
	double d;	//需求量 
	scanf("%d%lf",&n,&d);
	
	for(int i=0;i<n;i++)
		scanf("%lf",&mcs[i].amount);
	
	double price;
	for(int i=0;i<n;i++){
		scanf("%lf",&price);			//输入总价 
		mcs[i].unitprice = (price / mcs[i].amount);		//计算单价 
	}
	
	sort(mcs,mcs+n,cmp);		//单价从大到小排列	
	
	double profit=0;	//利润
	for(int i=0;i<n;i++){
		if(mcs[i].amount >= d){		//如果此种月饼的数量大于需求量，满足需求，则拿走对应的利润 
			profit+= (d * mcs[i].unitprice);
			break;
		}
		else{				//这种月饼的数量不够 
			profit+= mcs[i].amount * mcs[i].unitprice;
			d-=mcs[i].amount;
		}
	} 
	
	printf("%.2lf",profit);

	return 0;
}

