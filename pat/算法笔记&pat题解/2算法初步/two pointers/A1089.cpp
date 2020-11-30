//���ڣ�2018/6/14 ʱ�䣺19:36- 
//����˼·����Ҫ���� ���ù鲢����ķǵݹ�˼�룬����д����һ�ι鲢�����Ľ�� 
//for(int i=0;i<n;i+=(2*step)) 
//		sort(partial+i,partial+min(i+2*step,n));
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n); 
	int initial[105];
	int partial[105];
	
	for(int i=0;i<n;i++)
		scanf("%d",&initial[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&partial[i]);
		
	//˼·���ж����ǲ��ǲ�������������Ǿ��ǹ鲢����
	//�鲢����Ļ���ȷ�����ĵ�ǰ����step.Ȼ�����step*2��������
	//��������Ļ��ж���Ŀǰ�Ѿ��ŵ������ˣ�����ǰֵ����ǰ���������� 

	int flag=0;			//2��ʾ�鲢����1��ʾ�������� 
	int insertcur=0;		//������������ꡣ 
	int c;
	for(int c=1;c<n;c++){			//�ж��Ƿ�Ϊ�������򣬱�׼�ǣ�ǰ������򲿷֣�����ķ����򲿷ֺ�ԭ����һ�� 
		if(partial[c-1] > partial[c]){
			insertcur=c; 
			//printf("%d\n",insertcur);
			break;
		}
	}
	for(int i=insertcur;i<n;i++){
		if(partial[i]!=initial[i]){
			flag = 2;
			break;
		}
		flag=1;
	} 
	
	if(flag == 1){			//��insertcur����������뵽ǰ���Ѿ��ź���������У�partial[0~insertcur-1]����
		 printf("Insertion Sort\n");
		 int i;
		 int temp = partial[insertcur];
		 for(i=0;i<insertcur;i++){
		 	if(partial[i]>=temp)		//�����������뵽i��λ�� 
		 		break; 
		 }
		 for(int j=insertcur;j>=i+1;j--){
		 	partial[j]=partial[j-1];
		 }
		 partial[i] = temp;
			
	}else if(flag == 2){
		printf("Merge Sort\n");
		//�����жϲ����Ƕ���
		int step=n;
		int temp=1;
		for(int i=1;i<n;i++){
			if(partial[i] >= partial[i-1]){
				temp++;
			}else{
				step = min(step,temp);
				temp=1;
			}
		}
		//printf("%d\n",step);
		//���ù鲢����ķǵݹ�˼�룬����д����һ�ι鲢�����Ľ�� 
		for(int i=0;i<n;i+=(2*step)) 
			sort(partial+i,partial+min(i+2*step,n));
	}
	
	for(int i=0;i<n;i++){
		if(i != n-1)
			printf("%d ",partial[i]);
		else
			printf("%d",partial[i]);
	}
		

	return 0;
}

