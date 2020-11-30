//日期：2018/ 时间：
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn=10005;

int main(){
	char a[maxn],b[maxn];
	bool HashTable[128];	//记录字符是否在第二个字符串中出现过 ,初始状态全是false 
	
	int n,lenA=0,lenB=0;
	while((n=getchar()) != '\n'){
		a[lenA++]=n;
	}
	while((n=getchar()) != '\n'){
		b[lenB++]=n;
	}
	
	for(int i=0;i<lenB;i++){
		HashTable[b[i]] = true;		//第二个字符串中出现 
	}
	
	for(int i=0;i<lenA;i++){
		if(HashTable[a[i]] == false){
			printf("%c",a[i]);
		}
	}

	return 0;
}

