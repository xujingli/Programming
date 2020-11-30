//耐心细致，仔细分析
//16:17- 17:00

/*
此题中的启示是：要先在草稿纸上把数学关系理清楚，打印时也可以在草稿纸上画图理解。
此题中，把呢n2从小往大遍历，n1,n3相加必须是偶数，其次n1,n3都小于或等于n2. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[85];
	scanf("%s",s);
	
	int len=strlen(s);	//strlen()可以得到第一个'\0'之前的字符长度
	int n1,n2,n3;
	for(n2=3;n2<=len;n2++){
		if((len+2-n2) % 2 !=0 )
			continue;					//n1,n3相加为奇数，则不对称
		n1=n3=(len+2-n2)/2;
		if(n1 <= n2 && n3<=n2)	
			break;
	}
	//得出n1,n2,n3的长度
	
	//n1行,n2列
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(i != (n1-1) && j==0)//不是最后一行 ,第一列 
				printf("%c",s[i]);	//画图可以看出 和行号相同 
			
			else if(i != (n1-1) && j==(n2-1))//不是最后一行，最后一列
				printf("%c",s[len-1-i]);
				
			else if(i == (n1-1))			//最后一行
				printf("%c",s[i+j]); 
			else
				printf(" ");	//其他情况用空格填充 
		} 
		printf("\n");		//打印完一行要换行	
	}
	 
	return 0;
}

