//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	int A[1000];//用于存放输入的数据 
	
	int B[1000];//用于存放被五整除后余1的数字的下标
	int BSize=0;	//用于存放B中存放数字的个数；
	
	int sum=0,num=0;	//存放被5除后余3的数字的总和与个数 
	
	int C[1000];//用于存放 被5除后余4的数字的下标
	int CSize=0;	// 用于存放C中存放数字的个数；
	
	int A1=0,A2=0,A3=0,A4=0,A5=0;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]); 	//输入数据 
		
		if(A[i]%10==0)	//A1 = 能被5整除的数字中所有偶数的和；
			A1+=A[i];
			
		if(A[i]%5==1){
			B[BSize++]=i;	//依次保存下标 ，方便以后处理 
		}
		
		if(A[i]%5==2)	//A3 = 被5除后余2的数字的个数；
			A3++;
			
		if(A[i]%5==3){	//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
			sum+=A[i];
			num++;
		} 
		if(A[i]%5==4)	//A3 = 被5除后余2的数字的个数；
			C[CSize++]=i;
		
	}
	
	if(A1!=0)
		printf("%d ",A1);
	else
		printf("N ");
	
	//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
	for(int i=0;i<BSize;i++){
		if(i%2==0)
			A2+=A[B[i]];
		else
			A2-=A[B[i]];
	}
	
	if(A2!=0)
		printf("%d ",A2);
	if(BSize==0) 
		printf("N ");
	
	if(A3!=0)
		printf("%d ",A3);
	else
		printf("N ");
	
	//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
	if(sum!=0)
		printf("%.1f ",((double)sum/num));
	else
		printf("N ");
	
	//A5 = 被5除后余4的数字中最大数字
	for(int i=0;i<CSize;i++){
		if(A[C[i]]>A5)
			A5=A[C[i]];
	}
	
	if(A5!=0)
		printf("%d",A5);
	else
		printf("N");
	 
	
	
	return 0;
}

