#include <stdio.h>
#include <string.h>
#define MAXLEN 50

//method2�ǿռ��Ż��汾 
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
			if(x[i-1]==y[j-1]){			//ע��˴���i,j���Ǵ�1��ʼ����Ҫ��1�����ͼ 
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1; //���� 
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 3; //�� 
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 2; //�� 
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
	char x[MAXLEN] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"; //�㷨������222ҳ��DNA�ļ������ƥ��
    char y[MAXLEN] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	
	int b[MAXLEN][MAXLEN];//���ݶ�ά�������֪������������ʹ��MAXLEN���ȷ������
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
			if(x[i-1]==y[j-1]){			//����ȥ���˶�����b��ʹ�ã��������� 
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
	//��Ϊelse if(c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j];
	//˵��c[i-1][j] == c[i][j-1] == c[i][j] �Ļ���������ֱ�����ߡ� 
	//���Խ������һ�е��ɻ� .��Ϊ��� c[i][j] == c[i][j-1] ==  c[i-1][j] ��������߾Ͳ����ˣ����� 
	if(c[i][j] == c[i-1][j]){		//˼����Ϊʲô��һ��Ҫ����ǰ�棬���������ж�  if(c[i][j] == c[i][j-1]) ??
		PrintLCS(c,x,i-1,j);
	} else if(c[i][j] == c[i][j-1]){
		PrintLCS(c,x,i,j-1);
	} else{
		PrintLCS(c,x,i-1,j-1);
		printf("%c",x[i-1]);	//ֻ����c[i][j] == c[i-1][j-1]ʱ����������ֵ 
	}
}

int main(){
	//char x[MAXLEN] = "ABCBDAB";
	//char y[MAXLEN] = "BDCABA";
	char x[MAXLEN] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"; //�㷨������222ҳ��DNA�ļ������ƥ��
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
