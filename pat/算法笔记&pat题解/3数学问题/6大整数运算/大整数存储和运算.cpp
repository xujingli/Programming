//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用字符串读入，再反转着存到d[]数组中。 
struct bign{
	int d[1000];
	int len;
	bign(){			//“构造函数”初始化结构体 
		memset(d,0,sizeof(d));
		len = 0;
	}
}; 

void print(bign a){
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
}

//用字符串读入，再把字符串存放到bign结构体中 
bign change(char str[]){	//将整数转换为bign 
	bign a;
	a.len= strlen(str);		//bign的长度就是字符串的长度
	for(int i=0;i<a.len;i++){
		if(str[a.len-1-i]>='0' && str[a.len-1-i]<='9') 
			a.d[i] = str[a.len-1-i] - '0';
		else
			a.d[i] = str[a.len-1-i];
	} 
	return a;
}

//比较两个结构体：1)len不一样的话，直接判断，2)len一样，从d[len-1]往d[0]看，一位大则整体都大
int compare(bign a,bign b){	//比较a和b大小，a大、相等、a小分别返回1、0、-1 
	if(a.len > b.len)	return 1;	//a大
	else if(a.len < b.len) return -1;	//a小
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i] > b.d[i])	return 1;	//只要有一位a大，则a大
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;	//两数相等
	} 
} 

//加法 。需要指出的是，这种写法要确保两个数都是非负整数，如果一方为负数要转为减法 
bign add(bign a, bign b){
	//print(a); print(b);
	bign res;
	int carry=0;			//进位标志 
	for(int i=0;i<a.len || i<b.len ;i++){
		int temp = a.d[i] + b.d[i] +carry;
		carry = temp / 10;
		res.d[res.len++] = temp % 10;
	}
	if(carry != 0){			//考虑最高位是否有进位 
		res.d[res.len++] = carry;
	}
	return res;
}

//减法 
bign minus(bign a,bign b){		//a,b为非负整数 计算a-b的绝对值，正负号由自己判断
//如果不够减，则令被减位的高位减一，被减位加10再进行减法运算。
//最后一步要注意减法后高位可能有多余的0，要除去它们，但是也要保证结果至少有一位 
	bign res;
	if(compare(a,b)==-1){		//如果a<b，则交换位置 
		bign temp = a;
		a = b;
		b = temp;
	} 
	
	for(int i=0;i<a.len || i<b.len;i++){
		if(a.d[i] < b.d[i]){
			a.d[i+1]--;
			a.d[i] += 10;
		}
		res.d[res.len++] = a.d[i] - b.d[i];
	} 
	while(res.len-1 >=1 && res.d[res.len-1] == 0)
		res.len--;			//while(res.len -1 >=1)是至少保留一位为最低位，去除高位的0 
	return res;
}

//取bign得某位与int型整体相乘，再与进位相加，所得的结果的个位数作为该位的结果，高位部分作为进位 
bign multi(bign a,int b){		//高精度乘法 
	bign res;
	int carry = 0;
	for(int i=0;i<a.len;i++){
		int temp = a.d[i] * b + carry;
		res.d[res.len++] = temp%10;		//个位作为该位的结果 
		carry = temp/10;				//高位部分作为新的进位 
	}
	while(carry != 0){					//和加法不一样，乘法的进位可能不止一位，因此用while 
		res.d[res.len++] = carry % 10;
		carry /= 10; 
	}
	return res;
}

bign divide(bign a,int b,int& r){		//高精度除法，r为余数 
	bign res;
	res.len = a.len; 	//被除数的每一位和商的每一位是一一对应的，因此先令长度相等
	for(int i=a.len-1; i>=0;i--){	//从高位开始 
		r = r * 10 + a.d[i];		//和上一位遗留的余数进行组合
		if(r < b)	res.d[i] = 0;
		else{						//够除 
			res.d[i] = r / b;		//商 
			r %= b;					//获得新余数 
		} 
	} 
	
	//再去除高位的0,同时至少保留一位 
	while(res.len -1 >= 1 && res.d[res.len-1] == 0){
		res.len--;
	} 
	
	return res;
}

int main(){
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	bign a = change(str1);
	bign b = change(str2);
	
	printf("a+b=");			//加法 
	print(add(a,b));
	printf("\n");

	printf("a-b=");
	print(minus(a,b));
	printf("\n");
	
	int m = 10;
	printf("a*10=");
	print(multi(a,m));
	printf("\n");
	
	printf("a/10=");
	int r=0;
	print(divide(a,m,r));
	printf("······%d\n",r);
	
	return 0;
}

