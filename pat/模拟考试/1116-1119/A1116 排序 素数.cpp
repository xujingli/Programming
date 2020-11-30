//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std; 

const int maxn = 10005; 

struct stu{
	bool q;	//�Ƿ��Ѿ�����ѯ�� 
	int rank;		//���� 
}s[maxn];
bool isExist[maxn] = {false};	//�Ƿ���ڴ�ѧ��

bool isPrime(int n){	//�ж�n�Ƿ�Ϊ���� 
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i == 0)
			return false;
	}
	return true;
} 

int main(){
	int n;
	scanf("%d",&n);
	
	int id;
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		isExist[id] = true;
		s[id].rank = i+1;	//���� 
	}
	for(int i=0;i<maxn;i++)
		s[i].q = false;		//��û�б���ѯ��
	
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&id);
		if(isExist[id] == false){//������ 
			printf("%04d: Are you kidding?\n",id);
		} else {
			if(s[id].q == true){
				printf("%04d: Checked\n",id);	
			} else{
				s[id].q = true;
				if(s[id].rank == 1){
					printf("%04d: Mystery Award\n",id);
				}else if(isPrime(s[id].rank)){
					printf("%04d: Minion\n",id);
				}else{
					printf("%04d: Chocolate\n",id);
				}
			}
		}
	} 

	return 0;
}

