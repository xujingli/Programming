//耐心细致，仔细分析
//8:25-8:59   34minAC
#include <stdio.h>
#include <stdlib.h>

int main(){
	double odd[4];	//记录每组最大的概率
	char A[4];		//记录下最大概率的下标
	
	for(int i=1;i<=3;i++){	//输入三行 
		scanf("%lf",&odd[i]);//输入第一个概率 
		A[i]='W';			 //记录第一个最大概率为‘W’
		 
		for(int j=2;j<=3;j++){//每行三个数 
			double temp;
			scanf("%lf",&temp);
			if(temp > odd[i]){
				odd[i]=temp;
				if(j==2)
					A[i]='T';
				else if(j==3)
					A[i]='L'; 
			}
		} 
	} 
	
	for(int i=1;i<=3;i++)
		printf("%c ",A[i]);
	printf("%.2lf",(odd[1]*odd[2]*odd[3]*0.65-1)*2);

	return 0;
}

