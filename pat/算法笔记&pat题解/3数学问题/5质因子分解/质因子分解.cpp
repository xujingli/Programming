//���ڣ�2018/ ʱ�䣺
//�����ӷֽ⣺��һ��������nд��һ�����������ĳ˻�180==2*2*3*3*5 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct factor{
	int x,cnt;		//xΪ�����ӣ�cntΪ����� 
}fac[10];//��Ϊ2*3*5*7*11*13*17*19*23*29�Ѿ�������int�ķ�Χ�����fac����Ĵ�Сֻ��Ҫ����10������ 

const int maxn = 100010;
bool p[maxn]={0};
int prime[maxn]={0},pNum=0;		//�������������� 

void eFind_Prime(){
	for(int i=2;i<maxn;i++){
		if(p[i] == false){
			prime[pNum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				//i�ı���ȫ������������ 
				p[j] = true;
			}
		}
	}
}

/*		�����ӷֽ��˼·
����һ��������n��˵�����������[2,n]�ڵ������ӣ�Ҫô��Щ�����Ӷ�С�ڵ���sqrt(n)��
												Ҫôֻ����һ������sqrt(n)�������ӣ������������Ӷ�С�ڵ���sqrt(n) 


*/

int main(){
	eFind_Prime();
	int n,num=0;		//numΪn�Ĳ�ͬ�����ӵĸ���
	scanf("%d",&n);
	
	if(n==1)	printf("1=1"); //�����ж�
	else{
		printf("%d=",n);
		int sqr = (int)sqrt(1.0*n);
		
		//ö�ٸ���n�ڵ�������
		for(int i=0; i<pNum && prime[i]<=sqr; i++){
			if(n%prime[i] == 0){		//���prime[i]��n�������� 
				fac[num].x = prime[i];		//��¼������
				fac[num].cnt = 0;
				while(n%prime[i] == 0){	//�����������prime[i]�ĸ���
					fac[num].cnt++;
					n/=prime[i]; 
				} 
				num++;					//��ͬ�����Ӹ�����һ 
			}
			if(n == 1) break;			//��ʱ�˳�ѭ������ʡʱ�� 
		} 
		if(n != 1){						//����޷�������n���ڵ������ӳ��� 
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		
		for(int i=0;i<num;i++){
			if(i>0) printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt > 1)
				printf("^%d",fac[i].cnt);
		}
		
	} 

	return 0;
}
