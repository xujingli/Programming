//����ϸ�£���ϸ����
//10:00-10:20
//10:20- 
//��������ͻ���20���ӣ���������������һ��Ҫ�ӿ������ٶȣ����input����������Ŷ�� 

/*
�������1.42�к�47�У����û�й涨��������λ����λ���㣬��ɴ���
			2.21�к�42�У�Ҫ��������ķ�Χ��A~G��A~N���������ش��� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[4][65];
	for(int i=0;i<4;i++)
		scanf("%s",s[i]);
	//strlen()
	int count=0;		//�ƴ� 
	for(int i=0;i<strlen(s[0]) && i<strlen(s[1]);i++){	 
		if(s[0][i] == s[1][i] && (('A'<= s[0][i] && s[0][i]<='G')) && count == 0){	//��һ��������ͬ���ַ�,�������ַ� 
			count=1;				//�ƴμ�һ
			int d=s[0][i]-65+1;	//��������֣����ڼ��������ּ�
			switch(d){
				case 1: printf("MON ");
						break;
				case 2: printf("TUE ");
						break;
				case 3: printf("WED ");
						break;
				case 4: printf("THU ");
						break;
				case 5: printf("FRI ");
						break;
				case 6: printf("SAT ");
						break;
				case 7: printf("SUN ");
						break;
			};
		}
		else if(s[0][i] == s[1][i] && count == 1){//�ڶ���������ͬ���ַ� 
			if('A'<= s[0][i] && s[0][i]<='N'){
				printf("%02d:",s[0][i]-65+10);
				break;
			}
				
			else if('0'<= s[0][i] && s[0][i]<='9'){
				printf("%02d:",s[0][i]-48);
				break;
			}
				
		}		
		
	}
	
	for(int i=0;i<strlen(s[2]) && i<strlen(s[3]);i++){
		if(s[2][i] == s[3][i] && ( ('A'<= s[3][i] && s[3][i]<='Z') || ('a'<= s[3][i] && s[3][i]<='z')) ){
			printf("%02d",i);
			break;
		}
	}
	
	return 0;
}

