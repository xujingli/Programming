/*
 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int cards[54]; 
	for(int i=0;i<54;i++)		//牌的初始序列 
		cards[i]=i;
	char c[5]={'S','H','C','D','J'};

	int selfAdjust[54];
	for(int i=0;i<54;i++)			//输入自己的序列 
		scanf("%d",&selfAdjust[i]);	//需要注意的是这里的selfAdjust序列是从1开始的， 
	
	for(int i=0;i<n;i++){			//进行n次洗牌 
		int cardstemp[54]; 			//暂存一次调整后的牌
		 
		for(int i=0;i<54;i++){
			cardstemp[selfAdjust[i]-1]=cards[i];
		}
		
		for(int i=0;i<54;i++){
			cards[i]=cardstemp[i];
		}
	}
	/*打印牌x	*/
	for(int i=0;i<54;i++){
		if(i!=53)
			printf("%c%d ",c[cards[i]/13],cards[i]%13+1);
		else
			 printf("%c%d",c[cards[i]/13],cards[i]%13+1);
	}

    return 0;
}

