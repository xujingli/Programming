//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxn = 200005;
int prime[maxn];
bool p[maxn] = {false};
int pNum=0;

int hash[maxn];
bool h[maxn] = {false};

void prime1(){
	for(int i=2;i<maxn;i++){
		if(p[i] == false){
			prime[pNum++] = i;	//����
			for(int j=i+i;j<maxn;j+=i){
				p[j] = true;
			} 
		}
	}
}

int findPrime(int num){
	prime1();
	for(int i=0;i<pNum;i++){
		if(num <= prime[i]){
			return prime[i];
		}
	}
}

int main(){
	int MSize,n,m;
	scanf("%d%d%d",&MSize,&n,&m);
	int TSize = findPrime(MSize);	//�ҵ�����MSize����С���� 
	memset(hash,0,sizeof(hash));
	
	for(int i=0;i<n;i++){		//ѭ��n�� 
		int num;
		scanf("%d",&num);		//����������� 
		int pos = num % TSize;	//��ʼλ�� 
		int inc = 0;			//��ʼ���� 
		int k; 					//
		for(k=0;k<TSize;k++){
			int j = (pos+inc*inc) % TSize;
			if(h[j] == false){	//�յ�λ��
				hash[j] = num;
				h[j] = true;
				
				break; 
			}
			else{				//��λ���ѱ�ռ 
				inc++;
			}
		}
		if(k>=TSize) printf("%d cannot be inserted.\n",num);	//��ΪԽ���˳���˵���޷����� 
	}
	
	int count=0;
	for(int i=0;i<m;i++){
		int query;
		scanf("%d",&query);
		int pos = query % TSize;
		int inc = 0;
		int k;
		for(k=0;k<TSize;k++){
			int j = (pos+inc*inc) % TSize;
			count++;
			if(h[j] == false){				//��λ�ã�ֱ���˳� 
				break;
			} else if(h[j] == true && hash[j] == query){	//�ҵ����˳� 
				break;
			} else{							//��ǰλ�ò�Ϊ�գ������������ֲ��� 
				inc++;
			}
		}
		if(k>=TSize) count++;		
		/*
		ǿ��ǿ���˴� 
		
		
		*/
		//printf("query: %d  count: %d\n",query,count);
	}
	
	printf("%.1lf",count*1.0/m);
	
	return 0;
}
/*
4 5 4
10 6 4 15 11
11 4 15 2
*/
