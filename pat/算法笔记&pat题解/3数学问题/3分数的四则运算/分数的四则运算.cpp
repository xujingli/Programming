//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//�ƶ��������� 
//downΪ�Ǹ������������Ϊ���������upΪ�����ɣ�
//����÷���Ϊ0����ô�涨�����Ϊ0����ĸΪ1
//���Ӻͷ�ĸû�г���1����Ĺ�Լ�� 
struct Fraction{
	int up,down;
};

int gcd(int a,int b){
	return !b ? a : gcd(b,a%b);
}

//�������򣬻�����������
//�����ĸdownΪ��������ô���ӷ�ĸȡ�෴��
//�������upΪ0����ô���ĸdownΪ1
//�ҳ����ӷ�ĸ����ֵ�����Լ�������ӷ�ĸ�ֱ���������
Fraction reduction(Fraction result){
	if(result.down < 0){
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0)
		result.down = 1;
	else{
		int d = gcd(abs(result.down),abs(result.up));
		result.down /= d;
		result.up /= d;
	}
	
	return result;
} 

//��������� 
void showResult(Fraction r){
	r = reduction(r);
	if(r.down == 1)	printf("%d",r.up);
	else if(abs(r.up) > r.down){
		printf("%d %d/%d",r.up/r.down,abs(r.up)%r.down,r.down);
	}else{
		printf("%d/%d",r.up,r.down);
	}
}

//���µļӼ��˳�����һ���ġ� 
Fraction add(Fraction f1,Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
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

