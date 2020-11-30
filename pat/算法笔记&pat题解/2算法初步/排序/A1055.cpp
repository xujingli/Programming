//���ڣ�2018/ ʱ�䣺20min AC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct person{
	char name[10];
	int age,nw;
}p[100010];

bool cmp(person a,person b){
	if(a.nw == b.nw){
		if(a.age == b.age){
			return strcmp(a.name,b.name) <0;
		}
		return a.age < b.age;
	}
	return a.nw > b.nw;
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%s %d %d",p[i].name,&p[i].age,&p[i].nw);
	
	sort(p,p+N,cmp);
	
	int n[1005][3];			//���the maximum number of outputs[0], and [Amin, Amax] [1,2]
	for(int i=0;i<K;i++)
		scanf("%d %d %d",&n[i][0],&n[i][1],&n[i][2]);
	
	for(int i=0;i<K;i++){
		printf("Case #%d:\n",i+1);
		int flag=0;			//�ж�������������������
		int count=0;		//���ڼ������ҳ��Ľ�����ܳ���n[i][0] 
		for(int j=0;j<N && count<n[i][0];j++){	//���������ˡ� 
			if(p[j].age >= n[i][1] && p[j].age <= n[i][2]){	//�ڷ�Χ�� 
				flag=1;
				count++;
				printf("%s %d %d\n",p[j].name,p[j].age,p[j].nw);
			}
		} 
		if(flag==0)
			printf("None\n");
	}

	return 0;
}
