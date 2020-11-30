/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Fraction{
	int up,down;
}; 

int gcd(int a,int b){
	return !b ? a : gcd(b,a%b);
}

Fraction reduction(Fraction result){
	if(result.down < 0){
		result.up *= -1;
		result.down *= -1;
	}
	if(result.up == 0){
		result.down = 1;
	}
	else{
		int d = gcd(abs(result.down),abs(result.up));
		result.down /= d;
		result.up /= d;
	}
	
	return result;
}

void showResult(Fraction r){
	r = reduction(r);
	if(r.down == 1){
		printf("%d",r.up);
	}else if(abs(r.up) > r.down){
		printf("%d %d/%d",r.up/r.down,abs(r.up)%r.down,r.down);
	}else{
		printf("%d/%d",r.up,r.down);
	}
}

Fraction add(Fraction f1,Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down +f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction minu(Fraction f1,Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

int main(){


	return 0;
}

