//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//�������жϡ�Ҫ�ж�һ����n�Ƿ�Ϊ��������Ҫ�ж�n�ܷ�2,3,4.....n-1�������������Ӷ�ΪO(n)
//����ʵ�ϣ�ֻ��Ҫ�ж�n�ܷ�2,3......sqrt(n) �������ɡ��������ӶȾ���O(sqrt(n)) 
bool isPrime(int n){
	if(n <= 1)	return false;
	int sqr = (int)sqrt(1.0*n);			//���� 
	for(int i=2;i<=sqr;i++){
		if(n%i == 0)	return false;
	}
	return true;
}

//���� 
bool isPrime1(int n){
	if(n <= 1)	return false;
	for(long long i = 2; i*i <= n;i++){		//��ֹiԽ�磬ʹ��long long�ͱ��� 
		if(n % i == 0)	return false;
	}
	return true;
}

//������Ļ�ȡ����ӡ1~n��Χ��������ķ���������1~n����ö�٣��ж�ÿ�����Ƿ���������ö�ٵĸ��Ӷ���O(n),�жϵĸ��Ӷ���O(sqrt(n))
//����ܵĸ��Ӷ���O(n*sqrt(n)),��һ��������n��100000��Χ���ǿ��Գ��ܵġ� 
const int maxn = 3;
int prime[maxn],pNum=0;		//prime���������е�������pNumΪ�����ĸ���
bool p[maxn] ={0};			//p[i] == true ��ʾi������

void Find_Prime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i)==true){
			prime[pNum++]=i;
			p[i] = true;
		}
	}
} 

//������ָ���Χ�����������´��븴�Ӷ�ΪO(nloglogn).����ɸ����
//�㷨��С����ö�����е�������ÿһ��������ɸȥ�������б�����ʣ�µľ��������ˡ���С����ﵽĳ����aʱ
//���aû�б�ǰ�����ɸȥ����ôaһ����������
void eFind_Prime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[pNum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				//ɸȥ���е�i�ı�����ѭ����������д��j<=maxn
				p[j] = true; 
			}
		}
	}
} 

int main(){
	Find_Prime();
	for(int i=0;i<pNum;i++)
		printf("%d ",prime[i]);

	return 0;
}

