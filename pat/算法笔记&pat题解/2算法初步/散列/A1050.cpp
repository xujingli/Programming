//���ڣ�2018/ ʱ�䣺
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn=10005;

int main(){
	char a[maxn],b[maxn];
	bool HashTable[128];	//��¼�ַ��Ƿ��ڵڶ����ַ����г��ֹ� ,��ʼ״̬ȫ��false 
	
	int n,lenA=0,lenB=0;
	while((n=getchar()) != '\n'){
		a[lenA++]=n;
	}
	while((n=getchar()) != '\n'){
		b[lenB++]=n;
	}
	
	for(int i=0;i<lenB;i++){
		HashTable[b[i]] = true;		//�ڶ����ַ����г��� 
	}
	
	for(int i=0;i<lenA;i++){
		if(HashTable[a[i]] == false){
			printf("%c",a[i]);
		}
	}

	return 0;
}

