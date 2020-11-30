#include <stdio.h>
#include <stdlib.h>

#include <string.h>

    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x ==0) return true;
        char reverse[15], original[15];
        memset(reverse,'\0',sizeof(reverse));
        sprintf(original,"%d",x);	//将数字转为字符串
        int i = 0;
        while(x){
        	reverse[i++] = (x % 10 + 48);
        	x /= 10;
        }
        //printf("%s\n",reverse);
        //printf("%d %d \n",strlen(reverse),strlen(original));
        
        if(strcmp(reverse,original) == 0) return true;
        else return false;
    }

int main(){
	printf("%d",isPalindrome(1));
	
	
	return 0;
}

