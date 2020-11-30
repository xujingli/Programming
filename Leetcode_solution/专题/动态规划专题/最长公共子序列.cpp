#include <stdio.h>
#include <string.h>
#define MAXLEN 50

//method2是空间优化版本 
//#define method1
#define method2

#ifdef method1
void LCSLength(char *x,char *y,int m, int n,int c[][MAXLEN],int b[][MAXLEN]){
	int i,j;
	for(i=0;i<=m;i++)
		c[i][0] = 0;
	for(j=1;j<=n;j++)
		c[0][j] = 0;
		
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){			//注意此处，i,j都是从1开始所以要减1，详见图 
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1; //左上 
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 3; //上 
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 2; //左 
			}
		}
	}
}

void PrintLCS(int b[][MAXLEN], char *x,int i, int j){
	if(x ==0 || j==0)
		return;
	if(b[i][j] == 1){
		PrintLCS(b,x,i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j] == 3)
		PrintLCS(b,x,i-1,j);
	else
		PrintLCS(b,x,i,j-1);
}

int main(){
	//char x[MAXLEN] = "ABCBDAB";
	//char y[MAXLEN] = "BDCABA";
	char x[MAXLEN] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"; //算法导论上222页的DNA的碱基序列匹配
    char y[MAXLEN] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	
	int b[MAXLEN][MAXLEN];//传递二维数组必须知道列数，所以使用MAXLEN这个确定的数
	int c[MAXLEN][MAXLEN];
	
	int m,n;
	m = strlen(x);
	n = strlen(y);
	
	LCSLength(x,y,m,n,c,b);
	PrintLCS(b,x,m,n);
	
	return 0;
} 
#endif

#ifdef method2
void LCSLength(char *x,char *y,int m, int n,int c[][MAXLEN]){
	int i,j;
	for(i=0;i<=m;i++)
		c[i][0] = 0;
	for(j=1;j<=n;j++)
		c[0][j] = 0;
		
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){			//仅仅去掉了对数组b的使用，其他不变 
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
			}
			else {
				c[i][j] = c[i][j-1];
			}
		}
	}
}

void PrintLCS(int c[][MAXLEN], char *x,int i, int j){
	if(x ==0 || j==0)
		return;
	//因为else if(c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j];
	//说明c[i-1][j] == c[i][j-1] == c[i][j] 的话，先向竖直方向走。 
	//所以解答了下一行的疑惑 .因为如果 c[i][j] == c[i][j-1] ==  c[i-1][j] 先往左边走就不对了！！！ 
	if(c[i][j] == c[i-1][j]){		//思考：为什么这一项要放在前面，而不是先判断  if(c[i][j] == c[i][j-1]) ??
		PrintLCS(c,x,i-1,j);
	} else if(c[i][j] == c[i][j-1]){
		PrintLCS(c,x,i,j-1);
	} else{
		PrintLCS(c,x,i-1,j-1);
		printf("%c",x[i-1]);	//只有在c[i][j] == c[i-1][j-1]时，才输出这个值 
	}
}

int main(){
	//char x[MAXLEN] = "ABCBDAB";
	//char y[MAXLEN] = "BDCABA";
	char x[MAXLEN] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"; //算法导论上222页的DNA的碱基序列匹配
    char y[MAXLEN] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	
	int c[MAXLEN][MAXLEN];
	
	int m,n;
	m = strlen(x);
	n = strlen(y);
	
	LCSLength(x,y,m,n,c);
	printf("%d\n",c[m][n]);
	PrintLCS(c,x,m,n);
	
	return 0;
} 

#endif 
