//����ϸ�£���ϸ����
//8:25-8:59   34minAC
#include <stdio.h>
#include <stdlib.h>

int main(){
	double odd[4];	//��¼ÿ�����ĸ���
	char A[4];		//��¼�������ʵ��±�
	
	for(int i=1;i<=3;i++){	//�������� 
		scanf("%lf",&odd[i]);//�����һ������ 
		A[i]='W';			 //��¼��һ��������Ϊ��W��
		 
		for(int j=2;j<=3;j++){//ÿ�������� 
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

