//���ڣ�2018/ ʱ�䣺
//����ֱ���� pal����ֱ����� 
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int k,num[maxn],tmp[maxn];			//k�ǳ��ȣ�num[]�Ǹ��� 

bool isPal(){
	for(int i=0;i<k/2;i++){
		if(num[i] != num[k-i-1])
			return false;
	}
	return true;
}

void print(int tt[]){
	for(int i=0;i<k;i++)
		printf("%d",tt[i]);
}

void add(){						//num+tmp����͵�num�� 
	int ans[maxn];
	int carry=0;		//��λ
	int nk;				//�µ�kֵ 
	for(nk=0;nk<k;nk++){
		ans[nk] = (num[nk]+tmp[nk] +carry )% 10;
		carry = (num[nk]+tmp[nk] +carry ) / 10;
	} 
	if(carry ==1) ans[(++k)-1] = carry;

	for(int i=0;i<k;i++)
		num[i] = ans[k-i-1];
}

bool judge(){
	if(isPal()){
		print(num);
		printf(" is a palindromic number.");
		return true;	
	} 	
	
	for(int i=0;i<10;i++){
		//��num�����͵�tmp�� 
		for(int j=0;j<k;j++)
			tmp[j] = num[k-j-1];
		
		print(num);
		printf(" + ");
		print(tmp);

		add();		//��� �����Ұѽ���͵�num�� 
		printf(" = ");
		print(num);	
		printf("\n");		
		
		if(isPal()){
			print(num);
			printf(" is a palindromic number.");
			return true;	
		} 	
	} 
	return false;
}

int main(){
	char n[maxn];
	scanf("%s",n);
	k = strlen(n);
	for(int i=0;i<k;i++)
		num[i] = n[i] - '0'; 
	
	if(!judge()){
		printf("Not found in 10 iterations.\n");
	}

	return 0;
}

