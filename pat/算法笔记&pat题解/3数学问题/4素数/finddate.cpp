//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

const int maxn = 21000000;
int prime[maxn],pNum=0;		//prime���������е�������pNumΪ�����ĸ���
bool p[maxn] ={0};			//p[i] == true ��ʾi������

//������ָ���Χ�����������´��븴�Ӷ�ΪO(nloglogn).����ɸ����
//�㷨��С����ö�����е�������ÿһ��������ɸȥ�������б�����ʣ�µľ��������ˡ���С����ﵽĳ����aʱ
//���aû�б�ǰ�����ɸȥ����ôaһ����������
int count = 0; 
void eFind_Prime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){	//iΪ������i�ı����������� 
			prime[pNum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				//ɸȥ���е�i�ı�����ѭ����������д��j<=maxn
				p[j] = true; 
				
			}
			if(i>=20190525 && ((i/100)%1000)>0 && ((i/100)%1000)<=12 && (i%100000)>0 && (i%100000)<= ){	//���ǵ��� �� ����Ϊ0 
			 	count++;
				printf("%d\n",i);
			} 
		}
	}
} 

bool isPrime(int n){
	if(n <= 1)	return false;
	for(long long i = 2; i*i <= n;i++){		//��ֹiԽ�磬ʹ��long long�ͱ��� 
		if(n % i == 0)	return false;
	}
	return true;
}

void Find_Prime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i)==true){
			prime[pNum++]=i;
			p[i] = true;
		}
	}
} 


int main(){
	int birth,death;
	eFind_Prime();
	printf("������ܻ2100��,\n��ô�㻹������ %d ������������",count);
	
	return 0;
}

