//耐心细致，仔细分析
//9:02-10:20 19/20
// 
//像相等符号==就不要写成=了，那么低级的错误，今天居然已经出现了两回，还找了很长时间 

/*
1.for(;;i++),跳出循环时，i已经增加了1。这一点要谨慎 
2.提交时主要要把自己的测试打印代码给注释掉，否则会提示答案错误
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char snum[10010];	//科学计数法
	char num[20010];	//普通计数法
	scanf("%s",snum);
	
	char numsign=snum[0];		//数字的正负号
	int len=0;			//从第一个数字开始到"E"之前的长度,包括小数点 
	char expsign;		//指数的正负号
	int exp=0;			//指数的值
	
	int i; 
	for(i=1;i<strlen(snum);i++) {		//遍历科学计数法输入的字符串，解析以上的信息 		
		if(snum[i]!='E')
			len++;
		else
			break;
	}
	
	expsign=snum[i+1];
	//以下为指数的计算
	int p=1;			//权值 
	for(int j=(strlen(snum)-1) ; j >= i+2 ; j--){
		exp += (snum[j]-48) * p;
		p*=10;		//权值增加 
	} 
	
	//printf("%c %d %c %d\n",numsign,len,expsign,exp); 
	//注意科学计数法数组：+（下标0）1（下标1）.（下标2） 
	if(expsign == '-'){
		num[0]='0';
		num[1]='.';
		int j;
		for(j=2;j<=exp;j++)		//共添exp-1个零，可以写出来看看，正好是下标从2~exp 
			num[j]='0';
			
		num[j++]=snum[1]; 		//数字下标从1开始。下标0是正负号 
		for(int k=3;k<=len;k++)
			num[j++]=snum[k];	//从num后面开始，把 snum后面下标从3~len的数字都放到后面 
	}
	else if(expsign == '+'){
		//如果exp>len-2需要在末尾补零，exp==len-2,要去掉最后的小数点，exp<len-2直接移动小数点即可
		if(exp < len-2){		//只需要移动小数点 
			num[0]=snum[1];
			int j;
			for(j=1;j<=exp;j++)
				num[j]=snum[j+2];	//j=1~exp的位置上，num中存放snum复制下来的数字 
			num[j++]='.';
			for(int k=j+1;k<=len;k++)
				num[k-1]=snum[k];	//再把从小数点之后的数字搬到num数组中。看似复杂难懂，其实写几个数字推敲一下就懂了 
		}
		else if(exp > len-2){		//需要补零，需要补exp-(len-2)个零,那么就有len-1+[exp-(len-2)]位数字 
			num[0]=snum[1];
			int j;
			for(j=1;j<=len-2;j++)
				num[j]=snum[j+2];	//复制对应位的数字
			//跳出循环时，j已经自加一 
			for(int k=j;k <= j-1+(exp-(len-2));k++)	//补exp-(len-2)个1零 
				num[k]='0'; 
			//printf("j:%d\n",j);
		}
		else if(exp == len-2){		//把末尾的小数点去掉 
			num[0]=snum[1];
			for(int j=1;j<=exp;j++)
				num[j]=snum[j+2];
		}
	}
	
	if(numsign == '-')
		printf("%c%s",numsign,num);
	else
		printf("%s",num);
	return 0;
}

