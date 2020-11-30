//日期：2018/6/13 时间：16:35-15:15 19/25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm> 
using namespace std;

//#define p1
#define p2
//p2使用二分法 

/*******************************p2*********************************************/
#ifdef p2

typedef long long LL;
LL Map[256];			//0~9/a~z与0~35对应
LL inf = (1LL << 63) - 1;		//long long的最大值是2^63-1,注意加括号

void init(){
	for(char c='0';c <= '9';c++){
		Map[c] = c - '0';		//将'0'~'9'映射到0~9 
	}
	for(char c='a';c <= 'z';c++){
		Map[c] = c - 'a' +10;	//将'a'~'z'映射到10~35 
	}
}

LL convertNum10(char a[],LL radix,LL t){	//将a转换为十进制，t为上界 
	LL ans=0;
	int len = strlen(a);
	for(int i=0;i<len;i++){
		ans = ans * radix + Map[a[i]];		//进制转换 
		if(ans < 0 || ans > t)	return -1;  //溢出或超过N1的十进制 
	} 
	return ans;
}

int cmp(char N2[],LL radix,LL t){			//N2的十进制与t比较 
	int len = strlen(N2);
	LL num = convertNum10(N2, radix ,t);	//将N2转换为十进制
	if(num < 0)	return 1;				//溢出，肯定是N2 > t 
	if(t > num) return -1;				//t较大，返回-1
	else if(t == num)	return 0;		//相等，返回0
	else	return 1; 
}

int findLargestDigit(char N2[]){		//求最大数位
	int ans = -1,len = strlen(N2);
	for(int i=0;i<len;i++){
		if(Map[N2[i]] > ans){
			ans = Map[N2[i]];
		}
	} 
	return ans+1;						//最大的数位为ans,说明进制数的底线是ans+1 
}

int binarySearch(char N2[],LL left,LL right,LL t){	//二分求解N2的进制 
	LL mid;
	while(left < right){
		mid = (left + right)/2;
		int flag = cmp(N2,mid,t);		//判断N2转换为十进制后与t比较
		if(flag == 0) return mid;		//找到解，返回mid
		else if(flag == -1) left = mid+1;		//往右子区间继续查找
		else	right = mid-1;			//往左子区间继续查找 
	}
	return -1;
}

char N1[15],N2[15],temp[15];
int tag,radix;

int main(){
	init();
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	if(tag == 2){
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	} 
	LL t = convertNum10(N1,radix,inf);		//将N1从radix进制转换为十进制
	LL low = findLargestDigit(N2);			//找到N2中数位最大的位加一，当成二分下界
	LL high = max(low,t) + 1;				//上界 
	LL ans = binarySearch(N2, low, high, t);	//二分
	if(ans == -1)	printf("Impossible\n");
	else	printf("%lld\n",ans); 
	
	
	return 0;
} 

#endif
/****************************************************************************/

/*******************************p1*********************************************/
#ifdef p1
long long CtoD(char n[],int radix){	//将radix进制数n[]转换为十进制返回 
	int k=strlen(n);
	//printf("%d\n",k);
	long long dnum=0;		//转换后的十进制数
	long long r=1; 
	for(int i=k-1;i>=0;i--){
		if(n[i]>='0' && n[i]<='9')
			dnum+=r*(n[i]-'0');
		else if(n[i]>='a' && n[i]<='z')
			dnum+=r*(n[i]-'a'+10);
		r= r*radix;
	}
	return dnum;
}

int main(){
	char n1[15],n2[15];
	int tag,radix;
	long long dnum1,dnum2;		//转换为十进制数存储,最多可达36^10,因此用long long 
	
	scanf("%s",n1);
	getchar();		//吸取中间的空格 
	scanf("%s",n2); 
	getchar();
	scanf("%d",&tag);
	scanf("%d",&radix);
	
	if(tag == 2){
		char temp[15];
		strcpy(temp,n1);
		strcpy(n1,n2);
		strcpy(n2,temp);
	}
	
	int flag=0;			//判断是否可能 
	dnum1=CtoD(n1,radix);		//把字符串当做radix进制数字，转换为十进制数 
	
	int r=2; 
	//遍历n2这个字符串，确认一下可能最小进制 
	for(int i=0;i<strlen(n2);i++){
		if(n2[i]>='0' && n2[i]<='9'){		//数字 
			r = (r > (n2[i]-'0'+1) ? r : (n2[i]-'0'+1));
		}
		else if(n2[i]>='a' && n2[i]<='z'){		//数字 
			r = (r > (n2[i]-'a'+10+1) ? r : (n2[i]-'a'+10+1));
		}			
	}		//已经确定了最小的可能进制 
/**/	
	for(int i=r;i<=36;i++){
		dnum2=CtoD(n2,i);
		//printf("%s %d %lld\n",n2,r,dnum2);
		if(dnum2 == dnum1){
			flag=1;
			printf("%d",i);
			break;
		}
		if(dnum2 > dnum1)
			break;
	}
	
	if(flag == 0)
		printf("Impossible"); 

	return 0;
}

#endif
/****************************************************************************/

