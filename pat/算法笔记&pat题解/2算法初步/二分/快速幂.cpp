//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

typedef long long LL;
//��a^b % m�ݹ�д��
LL binaryPow(LL a,LL b,LL m){
	if(b ==0) return 1;	//���b==0
	
	//bΪ������ת��Ϊb-1
	if(b % 2 == 1) return a*binaryPow(a,b-1,m) % m;
	else{	//bΪż����ת��Ϊb/2 
		LL mul = binaryPow(a,b/2,m);
		return mul * mul % m;	//ע��˴�ǧ��Ҫ����binaryPow(a,b/2,m) * binaryPow(a,b/2,m)�� 
	} 
} 

//��a^b % m�ĵ���д��
LL binaryPow1(LL a,LL b,LL m){
	LL ans = 1;
	while(b > 0){
		if(b & 1){	//���b�Ķ�����ĩβΪ1 
			ans = ans * a % m;
		}
		a = a * a % m;		//��aƽ��
		b >>= 1;		//��b�Ķ���������һλ���� b = b >>1 ���� b = b / 2 
	}
	
	return ans;
}
 
int main(){
	

	return 0;
}

