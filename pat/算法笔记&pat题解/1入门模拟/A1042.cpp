/*
 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int cards[54]; 
	for(int i=0;i<54;i++)		//�Ƶĳ�ʼ���� 
		cards[i]=i;
	char c[5]={'S','H','C','D','J'};

	int selfAdjust[54];
	for(int i=0;i<54;i++)			//�����Լ������� 
		scanf("%d",&selfAdjust[i]);	//��Ҫע����������selfAdjust�����Ǵ�1��ʼ�ģ� 
	
	for(int i=0;i<n;i++){			//����n��ϴ�� 
		int cardstemp[54]; 			//�ݴ�һ�ε��������
		 
		for(int i=0;i<54;i++){
			cardstemp[selfAdjust[i]-1]=cards[i];
		}
		
		for(int i=0;i<54;i++){
			cards[i]=cardstemp[i];
		}
	}
	/*��ӡ��x	*/
	for(int i=0;i<54;i++){
		if(i!=53)
			printf("%c%d ",c[cards[i]/13],cards[i]%13+1);
		else
			 printf("%c%d",c[cards[i]/13],cards[i]%13+1);
	}

    return 0;
}

