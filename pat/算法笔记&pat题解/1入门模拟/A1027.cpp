//耐心细致，仔细分析
//8:39-9:27
/*
警示：	没有这样的语句：if(0<= n1 <=9)!!!!!!!!!!!
	看似简单的问题也要事先想清楚再做，不然白白浪费时间！ 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n[3];
	char res[3][2];
	for(int i=0;i<3;i++){
		scanf("%d",&n[i]);
		
		if(n[i]==0)			//处理输入为0的情况，严谨 
			res[i][0]=res[i][1]='0';
		else{
			int n1 = n[i]%13;	//个位数字
			if(0 <= n1 && n1 <=9)
				res[i][1] = n1+48;//从0开始 
			else
				res[i][1] = n1+55;//从A开始 
			
			n[i]/=13;
			if(n[i]==0)
				res[i][0] = 48;		//0
			else{
				int n2 = n[i]%13;	//个位数字
				if(0 <= n2&& n2 <=9)
					res[i][0] = n2+48;//从0开始 
				else
					res[i][0] = n2+55;//从A开始 
			} 
		}
	}
	
	printf("#");
	for(int i=0;i<3;i++)	
		for(int j=0;j<2;j++)
			printf("%c",res[i][j]);

	return 0;
}

