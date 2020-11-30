//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

const int maxn = 100;

bool judge(char num[],int len){
	bool point = false; 
	bool n = false;		//判断在.号之前是否有数字 
	for(int i=0;i<len;i++){
		if(num[i]!='-' && num[i]!='.'&&(num[i]>'9' || num[i]<'0'))
			return false;	//出现了非数字的其他符号
		if(num[i] == '-' && i!=0)
			return false;	//除了第一个位置，其余位置出现'-' 
		if(num[i] == '.' && len-1-i >2)	//小数点后长度大于2 
			return false;
		if(num[i]=='.' && point == false){
			if(n == false)	//小数点前还没有数字
				return false; 
			point = true;
			continue;					//第一次出现'.' 
		}
		if(num[i] == '.' && point == true)		//第二次出现 '.'
			return false;
			
		if(num[i] <='9' && num[i]>='0'){
			n = true;
			continue;
		}
		
	}
	return true;
}

double sTod(char num[],int len){
	double m = 0,n=0;	//整数部分，小数部分 
	bool isneg = false;
	bool before = true;	//在小数点前面 
	double t;			//倍数 
	for(int i=0;i<len;i++){
		if(num[i] == '-' && i==0){
			isneg = true;		//负数
			continue;
		}
			
		if(num[i] == '.'){
			before = false;
			t = 0.1;
			continue;
		}
		if(before == true){
			m = m*10+(num[i]-'0');
		}
		if(before == false){
			n = n + (num[i]-'0') * t;
			t /= 10;
		}
	}
	if(isneg == true)
		return (-1)*(m+n);
	else
		return m+n;
}

int main(){
	int n;
	scanf("%d",&n);
		
	int count = 0;
	double total = 0;
	for(int i=0;i<n;i++){
		char num[maxn];
		scanf("%s",num);
		int len = strlen(num);
		
		if(judge(num,len) == false){
			printf("ERROR: %s is not a legal number\n",num);
		} else{
			double n = sTod(num,len);
			if(n < -1000 || n > 1000)
				printf("ERROR: %s is not a legal number\n",num);
			else{
				count++;
				total += sTod(num,len);
			}
		}
	} 
	
	if(count == 0){
		printf("The average of 0 numbers is Undefined\n");
	} else if(count == 1){
		printf("The average of 1 numbers is %.2f",total);
	} else
		printf("The average of %d numbers is %.2f",count,total/count);

	return 0;
}

