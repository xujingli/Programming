/*

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	
	A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
	A3 = 被5除后余2的数字的个数；
	A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
	A5 = 被5除后余4的数字中最大数字。
	*/
	int A[1000];	//存放输入的数字 
	int n;			//数字个数 
	scanf("%d",&n);
	
	int A1=0,A2=0,A3=0,A4=0,A5=0;
	int A2S[1000];	//记录满足A2条件的数组下标；
	int A2SL=0;		//A2S的长度 
	
	int sumA4=0;		//满足A4条件的总和
	int numA4=0;		//个数 
	
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		if(A[i]%10==0)
			A1+=A[i];		//A1 = 能被5整除的数字中所有偶数的和；
		if(A[i]%5==1){		//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...； 
			A2S[A2SL++]=i;
		} 
		if(A[i]%5==2){		//A3 = 被5除后余2的数字的个数；
			 A3++;
		} 
		if(A[i]%5==3){		//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
			sumA4+=A[i];
			numA4++; 
		} 
		if(A[i]%5==4 && A[i]>A5){		//A5 = 被5除后余4的数字中最大数字。
			A5=A[i];
		} 
	} 
	
	//A1
	if(A1!=0)
		printf("%d ",A1);
	else
		printf("N ");
	
	//A2
	if(A2SL==0)
		printf("N ");
	else{
		for(int i=0;i<A2SL;i++){	//交错求和
			if(i%2==0)
				A2+=A[A2S[i]];
			else
				A2-=A[A2S[i]];
		}
		
		printf("%d ",A2); 
	}
	
	//A3
	if(A3==0)
		printf("N ");
	else
		printf("%d ",A3);
	
	//A4
	if(numA4==0)
		printf("N ");
	else
		printf("%.1f ",(double)sumA4 / numA4);
	
	//A5
	if(A5==0)
		printf("N");
	else
		printf("%d",A5);

    return 0;
}

