//���ڣ�2018/ ʱ�䣺18:50-18:54 17/20 �δ��� 
//ԭ���� ����Խ�硣���ܻ����һ���ܴ�����֣����ǿ���ֱ�Ӻ�����������16/17�д��뼴�ɡ� 
#include <stdio.h>
#include <stdlib.h>

const int maxn = 100005; 
bool table[maxn] = {false};

int main(){
	 int n;
	 scanf("%d",&n);
	 
	 int tmp;
	 for(int i=0;i<n;i++){
	 	scanf("%d",&tmp);
	 	if(tmp > n){
	 		continue;	
	 	} else if(tmp>0){
	 		table[tmp] = true;
	 	}
	 	
	 }
	 
	 for(int i=1;i<maxn;i++){
	 	if(table[i] == false){
	 		printf("%d",i);
	 		break;
	 	}
	 }

	return 0;
}
