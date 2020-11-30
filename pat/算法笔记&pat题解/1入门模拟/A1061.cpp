//耐心细致，仔细分析
//10:00-10:20
//10:20- 
//本题审题就花了20分钟！！！所以提醒你一定要加快审题速度，结合input例子来更快哦！ 

/*
本题错误：1.42行和47行，起初没有规定必须是两位，高位补零，造成错误
			2.21行和42行，要限制输入的范围是A~G和A~N，否则严重错误 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[4][65];
	for(int i=0;i<4;i++)
		scanf("%s",s[i]);
	//strlen()
	int count=0;		//计次 
	for(int i=0;i<strlen(s[0]) && i<strlen(s[1]);i++){	 
		if(s[0][i] == s[1][i] && (('A'<= s[0][i] && s[0][i]<='G')) && count == 0){	//第一次遇到相同的字符,必须是字符 
			count=1;				//计次加一
			int d=s[0][i]-65+1;	//换算成数字，星期几就是数字几
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
		else if(s[0][i] == s[1][i] && count == 1){//第二次遇到相同的字符 
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

