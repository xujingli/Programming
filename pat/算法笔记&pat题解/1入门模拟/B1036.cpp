//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	char c;
	scanf("%d %c",&n,&c);	//���������α߳����ַ�

	int col=n;							//������Ϊn
	int raw=(n%2==0 ? n/2 : (n/2)+1 );//������Ϊn/2,�������� 
	
	for(int i=0;i<raw;i++){
		for(int j=0;j<col;j++){
			if(i==0 || i== raw-1)
				printf("%c",c);	//��һ�к����һ��,ÿһ�ж�����ַ� 
			else{
				if(j==0 || j==col-1)
					printf("%c",c);//��һ�к����һ�����,��������ո�
				else
					printf(" "); 
			} 
			
		}
		if(i!=raw-1) 
			printf("\n");
	} 
		
	return 0;
}

