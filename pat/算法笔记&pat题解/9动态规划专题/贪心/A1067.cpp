//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
const int maxn = 100005;
int number[maxn];

int main(){
	int N;
	scanf("%d",&N);
	int pz;					//��¼0��λ������ 
	for(int i=0;i<N;i++){
		scanf("%d",&number[i]);
		if(number[i]==0)
			pz=i; 
	}
		
	
	

	return 0;
}

