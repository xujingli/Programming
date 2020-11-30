#include <stdio.h>
#include <stdlib.h>

//#define p1
/*
p1���г�ʱ��ԭ��n1�����ֵ��10000��a->b�����ֵ��100000.��������˫��forѭ���ڼ�������µĸ��Ӷ���10�ľŴη�
	��˳�ʱ 
�Ľ���ʩ����1��i���ܾ���ŵ�D[i-1]�У���a->b��˳ʱ��������D[b-1]-D[a-1],��ʱ��������D[n]-(D[b-1]-D[a-1]) 
*/
#ifdef p1

int main(){
	int n;
	scanf("%d",&n);				//����n������ 1->2->...->n->1
	int D[100001];
	
	int total=0;				//��·�̣� 
	
	for(int i=1;i<=n;i++){ 
		scanf("%d",&D[i]);		//D[1]~D[n] ��D[i]Ϊi-->i+1�ľ��� 
		total+=D[i];			//��·�� 
	} 
 
	int n1;				
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		int a1,b1;				//������յ� 
		scanf("%d%d",&a1,&b1);
		int a=(a1 < b1 ? a1 : b1);
		int b=(a1 >=b1 ? a1 : b1);	//��Сֵ����a,�ϴ�ĸ�b 
		
		int len=0;				//�ȼ���˳ʱ��·�̣�total-len��Ϊ������·�̣�ȡ���ߵ���Сֵ
		for(int j=a;j<b;j++){
			len+=D[j];
		} 
		
		int slen=(len <= (total-len) ? len : (total-len));//shortest length
		 
		printf("%d\n",slen);
	} 
	
    return 0;
}
#endif

#define p2
#ifdef p2
int main(){
	int n;
	scanf("%d",&n);				//����n������ 1->2->...->n->1
	int D[100001];
	D[0]=0;//��ʼ�� 
	
	int total=0;				//��·�̣� 
	
	for(int i=1;i<=n;i++){ 
		int dist;				//distΪi-->i+1�ľ��� 
		scanf("%d",&dist);		//D[1]~D[n] ��D[i]Ϊi-->i+1�ľ��� 
		D[i]=D[i-1]+dist;		//D[n]Ϊ��·�� 
	} 
	
	int n1;				
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		int a1,b1;				//������յ� 
		scanf("%d%d",&a1,&b1);
		int a=(a1 < b1 ? a1 : b1);
		int b=(a1 >=b1 ? a1 : b1);	//��Сֵ����a,�ϴ�ĸ�b 
		
		int len1=D[b-1]-D[a-1],len2=D[n]-(D[b-1]-D[a-1]);	//�ȼ���˳ʱ��·�̣�total-len��Ϊ������·�̣�ȡ���ߵ���Сֵ
		
		int slen=(len1 <= len2 ? len1 : len2);//shortest length
		 
		printf("%d\n",slen);
	} 

	return 0;
}


#endif 
