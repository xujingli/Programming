//����ϸ�£���ϸ����
//8:39-9:27
/*
��ʾ��	û����������䣺if(0<= n1 <=9)!!!!!!!!!!!
	���Ƽ򵥵�����ҲҪ�����������������Ȼ�װ��˷�ʱ�䣡 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n[3];
	char res[3][2];
	for(int i=0;i<3;i++){
		scanf("%d",&n[i]);
		
		if(n[i]==0)			//��������Ϊ0��������Ͻ� 
			res[i][0]=res[i][1]='0';
		else{
			int n1 = n[i]%13;	//��λ����
			if(0 <= n1 && n1 <=9)
				res[i][1] = n1+48;//��0��ʼ 
			else
				res[i][1] = n1+55;//��A��ʼ 
			
			n[i]/=13;
			if(n[i]==0)
				res[i][0] = 48;		//0
			else{
				int n2 = n[i]%13;	//��λ����
				if(0 <= n2&& n2 <=9)
					res[i][0] = n2+48;//��0��ʼ 
				else
					res[i][0] = n2+55;//��A��ʼ 
			} 
		}
	}
	
	printf("#");
	for(int i=0;i<3;i++)	
		for(int j=0;j<2;j++)
			printf("%c",res[i][j]);

	return 0;
}

