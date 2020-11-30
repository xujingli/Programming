//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

const int N = 100005;
//Union Find Set
int father[N]; 				//father[x]�д��Ԫ��x�ĸ��׽ڵ� 
//��ʼ��
void initial(){
	for(int i=1;i<=N;i++){
		father[i]=i;		//һ��ʼ��ÿһ��Ԫ�ض��Ƕ�����һ�����ϡ� 
	}
}

//Ѱ��Ԫ��x���ڼ��ϵĸ��ڵ� 
int findFather(int x){
	while(x!=father[x])
		x=father[x];
	return x; 
}

//�ϲ��������ϣ����ж�����Ԫ���Ƿ�ͬ����ͬһ�����ϣ�ֻ�е�����Ԫ�����ڲ�ͬ���ϲźϲ���
//�ϲ��Ĺ���һ���ǰ�����һ�����ϵĸ��ڵ�ĸ���ָ����һ�����ϵĸ��ڵ� 
void Union(int a,int b){
	int FaA = findFather(a);
	int FaB = findFather(b);
	if(FaA != FaB){
		FaA = father[FaB];		//�ϲ� 
	} 
}

//����ʱѹ��·�� 
int findFather1(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];			//Ѱ�Ҹ��ڵ� 
	}//x������ڵ㡣�����·���ϵ����нڵ��father���ĳɸ��ڵ�
	
	//��a��ʼ ����a�����һ��ָ�롣ָ������ 
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
} 

int main(){
	

	return 0;
}

