//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;		
	scanf("%d",&n);	//����һ������
	 
	int count=0;	//count��¼��Ҫ���ٲ� 
	while(n!=1){
		if(n%2 == 0)//ż��
			n/=2;
		else		//���� 
			n=(n*3+1)/2;
		count++;	//����һ�� 
	} 

	printf("%d\n",count);//������� 
	return 0;
}

