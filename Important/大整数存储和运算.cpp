/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};

void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
}

bign change(char str[]){
	//把证书转换为bign
	bign a;
	a.len = strlen(str);
	for(int i=0;i<a.len;i++) {
		if(str[a.len-1-i]>='0' && str[a.len-1-i]<='9')
			a.d[i] = str[a.len-1-i] - '0';
		else
			a.d[i] = str[a.len-1-i];
	}
	return a;
}

bign add(bign a,bign b){
	bign res;
	int carry = 0;	//进位标志
	for(int i=0;i<a.len||i<b.len;i++){
		int temp = a.d[i] + b.d[i]+carry;
		carry = temp /10;
		res.d[res.len++] = temp%10;
	} 
	if(carry!=0){
		res.d[res.len++] = carry;
	}
	return res;
}

int compare(bign a,bign b){
	if(a.len >b.len) return 1;	//a大
	else if(a.len<b.len) return -1;	//a小
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i] > b.d[i]) return 1;	//
			else if(a.d[i] < b.d[i]) return -1; 
		}
		return 0;
	} 
}

bign minus(bign a,bign b){
	bign res;
	if(compare(a,b) == -1){
		bign temp =a;
		a = b;
		b = temp;
	}
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i] < b.d[i]){
			a.d[i+1]--;
			a.d[i]+=10;
		}
		res.d[res.len++] = a.d[i] - b.d[i];
	}
	while(res.len-1 >= 1 && res.d[res.len-1] ==0){
		res.len--;
	} 
	return res;
}

bign multi(bign a,int b){
	bign res;
	int carry = 0;
	for(int i=0;i<a.len;i++){
		int temp = a.d[i]*b+carry;
		res.d[res.len++] = temp % 10;
		carry = temp/10;
	}
	while(carry != 0){
		res.d[res.len++] = carry % 10;
		carry /= 10;
	}
	return res;
}

bign divide(bign a,int b,int& r){	//高精度除法，r为余数 
	bign res;
	res.len = a.len;
	for(int i=a.len-1;i>=0;i--){
		r = r * 10 + a.d[i];
		if(r<b) res.d[i] = 0;
		else{
			res.d[i] = r /b;
			r%=b;
		} 
	}
	
	while(res.len-1 >=1 && res.d[res.len-1] == 0){
		res.len--;
	}
	return res;
}

int main(){
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	bign a = change(str1);
	bign b = change(str2);
	
	printf("a+b = ");
	print(add(a,b));
	printf("\n");
	printf("a-b = ");
	print(minus(a,b));
	printf("\n");
	
	return 0;
}

