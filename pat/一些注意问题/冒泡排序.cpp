#include <stdio.h>
 
 int main(){
 	int a[10]={3,1,4,5,2};
 	for(int i=1;i<=4;i++){	//进行n-1趟 
 		//第i趟从a[0]到a[n-i-1]都与他们的下一个数比较
		for(int j=0 ;j<5-i+1;j++){
			if(a[j]>a[j+1]){
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		} 
 	}
 	for(int i=0;i<5;i++)
		printf("%2d ",a[i]);
	printf("\n");
 	return 0;
 }
