//����ϸ�£���ϸ����
//9:29- 9:46
#include <stdio.h>
#include <stdlib.h>

struct num{
	int Galleon,Sickle,Knut;
}A,B,res;

int main(){
	scanf("%d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut);
	scanf("%d.%d.%d",&B.Galleon,&B.Sickle,&B.Knut);
	
	int n1=0,n2=0;			//n1Ϊsickle��Galleon�Ľ�λ��n2ΪKunt��Sicket�Ľ�λ 
	
	if((res.Knut = (A.Knut+B.Knut)) >= 29){	//��Ҫ��λ 
		n2=1;
		res.Knut-=29;
	}	
	
	if((res.Sickle= (A.Sickle+B.Sickle+n2)) >= 17){//����ǰ��Ľ�λ��־������Ҫ��λ 
		n1=1;
		res.Sickle-=17; 
	}
	res.Galleon=A.Galleon+B.Galleon+n1;		//���Ͻ�λ��Ƿ�
	
	printf("%d.%d.%d",res.Galleon,res.Sickle,res.Knut); 
	

	return 0;
}

