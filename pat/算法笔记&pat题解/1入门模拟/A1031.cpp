//����ϸ�£���ϸ����
//16:17- 17:00

/*
�����е���ʾ�ǣ�Ҫ���ڲݸ�ֽ�ϰ���ѧ��ϵ���������ӡʱҲ�����ڲݸ�ֽ�ϻ�ͼ��⡣
�����У�����n2��С���������n1,n3��ӱ�����ż�������n1,n3��С�ڻ����n2. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[85];
	scanf("%s",s);
	
	int len=strlen(s);	//strlen()���Եõ���һ��'\0'֮ǰ���ַ�����
	int n1,n2,n3;
	for(n2=3;n2<=len;n2++){
		if((len+2-n2) % 2 !=0 )
			continue;					//n1,n3���Ϊ�������򲻶Գ�
		n1=n3=(len+2-n2)/2;
		if(n1 <= n2 && n3<=n2)	
			break;
	}
	//�ó�n1,n2,n3�ĳ���
	
	//n1��,n2��
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(i != (n1-1) && j==0)//�������һ�� ,��һ�� 
				printf("%c",s[i]);	//��ͼ���Կ��� ���к���ͬ 
			
			else if(i != (n1-1) && j==(n2-1))//�������һ�У����һ��
				printf("%c",s[len-1-i]);
				
			else if(i == (n1-1))			//���һ��
				printf("%c",s[i+j]); 
			else
				printf(" ");	//��������ÿո���� 
		} 
		printf("\n");		//��ӡ��һ��Ҫ����	
	}
	 
	return 0;
}

