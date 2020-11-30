//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

typedef long long LL;
//求a^b % m递归写法
LL binaryPow(LL a,LL b,LL m){
	if(b ==0) return 1;	//如果b==0
	
	//b为奇数，转换为b-1
	if(b % 2 == 1) return a*binaryPow(a,b-1,m) % m;
	else{	//b为偶数，转换为b/2 
		LL mul = binaryPow(a,b/2,m);
		return mul * mul % m;	//注意此处千万不要返回binaryPow(a,b/2,m) * binaryPow(a,b/2,m)！ 
	} 
} 

//求a^b % m的迭代写法
LL binaryPow1(LL a,LL b,LL m){
	LL ans = 1;
	while(b > 0){
		if(b & 1){	//如果b的二进制末尾为1 
			ans = ans * a % m;
		}
		a = a * a % m;		//令a平方
		b >>= 1;		//将b的二进制右移一位，即 b = b >>1 或者 b = b / 2 
	}
	
	return ans;
}
 
int main(){
	

	return 0;
}

