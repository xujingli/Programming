/*����ϸ�£���ϸ����
���ݣ��������Ƚϣ�Բ���� ���������� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------------------------------------- 
//�������Ƚϣ�һ����a����[b-eps,b+eps]�м伴��a==b��ͨ��epsȡ1e-8 
const double eps = 1e-15;

#define Equ(a,b) ((fabs((a)-(b)))<(eps)) 
//�����������жϣ�����Ϊ1e-15

#define More(a,b) (((a)-(b))>(eps))
//�����������жϣ���a>b+eps �뻭ͼ��� 

#define Less(a,b) (((a)-(b))<(-eps))
//������С���ж� ,��a<b-eps

#define MoreEqu(a,b) (((a)-(b))>(-eps))
//���������ڵ����жϣ���a>b-eps
//-----------------------------------------------------------------------

//Բ����
const double Pi = acos(-1.0); 

//�������� 
void Round(double db,int n){
	//��������db����nλ��������������
	db=db*pow(10,n);
	
	int tmp=(int)round(db); 	//������������ȡ��
	db=(double)(tmp)/(pow(10,n));
	
	printf("%f\n",db); 
}

int main(){
	double db = 1.234567891234567;
	double db1= 1.234567891234567;
	
	printf("Pi = %.15f\n",Pi);//double�ľ���Ϊ15-16λ 
	
	if(Equ(db,db1))
		printf("db == db1\n");
	else
		printf("db != db1\n");
		
	Round(-Pi,6);

	return 0;
}

