//耐心细致，仔细分析
//9:29- 9:46
#include <stdio.h>
#include <stdlib.h>

struct num{
	int Galleon,Sickle,Knut;
}A,B,res;

int main(){
	scanf("%d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut);
	scanf("%d.%d.%d",&B.Galleon,&B.Sickle,&B.Knut);
	
	int n1=0,n2=0;			//n1为sickle向Galleon的进位，n2为Kunt向Sicket的进位 
	
	if((res.Knut = (A.Knut+B.Knut)) >= 29){	//需要进位 
		n2=1;
		res.Knut-=29;
	}	
	
	if((res.Sickle= (A.Sickle+B.Sickle+n2)) >= 17){//加上前面的进位标志符，需要进位 
		n1=1;
		res.Sickle-=17; 
	}
	res.Galleon=A.Galleon+B.Galleon+n1;		//加上进位标记符
	
	printf("%d.%d.%d",res.Galleon,res.Sickle,res.Knut); 
	

	return 0;
}

