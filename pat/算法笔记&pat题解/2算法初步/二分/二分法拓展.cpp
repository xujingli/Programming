//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

//计算根号2,精度为1e-5 
const double eps = 1e-5;
double f(double x){
	return x*x;
} 

double calSqrt(){
	double left=1,right=2,mid;
	while(right - left > eps){
		mid = (left + right)/2;
		if(f(mid) > 2){
			right= mid;
		}else{
			left = mid;
		}
	}
	return mid;
}

int main(){
	

	return 0;
}

