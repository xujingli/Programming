//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i == 0) return false;
	}
	return true;
}

const int N = 11111;
bool h[N] = {false};

int main(){
	int n,TSize,a;
	scanf("%d%d",&TSize,&n);
	while(!isPrime(TSize))
		TSize++;
	
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		int M = a%TSize;
		if(h[M] == false){				//���M��λδ��ʹ�ã����Ѿ��ҵ� 
			h[M] = true;
			if(i == 0) printf("%d",M);
			else printf(" %d",M);
		} else{
			int step;				//���η�̽�鷽���Ĳ��� 
			for(step=1;step<TSize;step++){
				M = (a+step*step) % TSize;
				if(h[M] == false){
					h[M] = true;
					if(i == 0) printf("%d",M);
					else printf(" %d",M);
					break;
				}
			}
			if(step >= TSize){		//�Ҳ�������ĵط� 
				if(i>0) printf(" ");
				printf("-"); 
			}
		}
	}
	
	return 0;
}


/*
const int maxn = 20000;
int prime[maxn];
int pNum=0;
bool p[maxn] = {false};

int hash[maxn];
bool h[maxn] = {false};

void eprime(){
	for(int i=2;i<maxn;i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = i+i;j<maxn;j+=i){
				p[j] = true;
			}
		}
	}
}

int main(){
	int MSize,n;
	scanf("%d%d",&MSize,&n);
	eprime();
	int TSize;
	for(int i=0;i<pNum;i++){
		if(MSize <= prime[i]){
			TSize = prime[i];
			break;
		}
	} 		//ȷ��TSize�� 

	for(int i=0;i<n;i++){		//ѭ��n�� 
		int num;
		scanf("%d",&num);		//����������� 
		int pos = num % TSize;	//��ʼλ�� 
		int inc = 0;			//��ʼ���� 
		int k; 					//jΪƽ�����������λ�� 
		for(k=0;k<TSize;k++){
			int j = (pos+inc*inc) % TSize;
			if(h[j] == false){	//�յ�λ��
				hash[j] = num;
				h[j] = true;
				printf("%d",j);
				
				break; 
			}
			else{				//��λ���ѱ�ռ 
				inc++;
			}
		}
		if(k>=TSize) printf("-");	//��ΪԽ���˳���˵���޷����� 
		if(i<n-1) printf(" ");		//��֤ĩβ�޿ո� 
	}
		
	return 0;
}
*/
