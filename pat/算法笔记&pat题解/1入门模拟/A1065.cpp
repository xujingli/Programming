//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

//#define p1
/*
double��ʾ�ľ��Ȳ��� 
*/
#ifdef p1 

int main(){
	double A,B,C;
	int T;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lf %lf %lf",&A,&B,&C);
		printf("\n%lf %lf %lf\n",A,B,C);	//������ɼ���double��ʾ�ľ������� 
		if(A+B > C)
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}//9223372036854775807

	return 0;
}
#endif

//#define p2
/*
p2��˼·�������ģ������A,B,C�м��費����2��63�η�����long long �ķ�Χ�ǣ�-pow(2,63)��pow(2,63)-1��
	�����ԭ��֪ʶ��֪��ͬ���͵���������һ��������һ�����������
	���������µ�˼·��
	A>0,B>0  if C<0 ��Ϊtrue
	         if C>0 A+B>C ���ж� A>C-B�ȼۣ�������C-B��һ����������һ�����������һ���������
	A>0,B<0  A+B����ֱ�����㣬�������
	A<0,B>0  ͬ��
	A<0,B<0  if C>0 ��Ϊfalse
			 if C<0 A+B>C ���ж� A>C-B�ȼۣ�������C-B��һ����������һ�����������һ���������
����Ҫע�⣬A,B,C��Ϊ0�����������һ�������ڡ���֦�� ��˼�� 


���Ǵ������£�	long long�����ݲ��ܱ�ʾ2��63�η��� �������´����ύ�Ĳ��Զ���ͨ���ģ�˵����Ŀ����д���ˣ�  
*/ 1

#ifdef p2
int main(){
	int T;	
	scanf("%d",&T);
	
	long long A,B,C;
	for(int i=0;i<T;i++){
		scanf("%lld %lld %lld",&A,&B,&C);
		//printf("\n%lf %lf %lf\n",A,B,C);	//������ɼ���double��ʾ�ľ������� 
		if(A>0 && B>0 && C<=0)
			printf("Case #%d: true\n",i+1);
		else if(A>0 && B>0 && C>0 && A > (C-B))
			printf("Case #%d: true\n",i+1);
		else if(A>=0 && B<=0 && (A+B)>C)
			printf("Case #%d: true\n",i+1);
		else if(A<=0 && B>=0 && (A+B)>C)
			printf("Case #%d: true\n",i+1);
		else if(A<0 && B<0 && C<0 && A>(C-B))
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}//9223372036854775807
	return 0;
}

#endif 

#define p3
#ifdef p3

int main(){
	
	
	return 0;
} 

#endif 
