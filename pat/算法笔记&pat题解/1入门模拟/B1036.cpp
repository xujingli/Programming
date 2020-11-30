//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	char c;
	scanf("%d %c",&n,&c);	//输入正方形边长和字符

	int col=n;							//列数即为n
	int raw=(n%2==0 ? n/2 : (n/2)+1 );//行数即为n/2,四舍五入 
	
	for(int i=0;i<raw;i++){
		for(int j=0;j<col;j++){
			if(i==0 || i== raw-1)
				printf("%c",c);	//第一行和最后一行,每一列都输出字符 
			else{
				if(j==0 || j==col-1)
					printf("%c",c);//第一列和最后一列输出,其他列输空格
				else
					printf(" "); 
			} 
			
		}
		if(i!=raw-1) 
			printf("\n");
	} 
		
	return 0;
}

