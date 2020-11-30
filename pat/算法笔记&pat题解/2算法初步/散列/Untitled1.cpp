//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26*26*26+10];

int hashFunc(char S[], int len){
	//hash���������ַ���Sת��Ϊ����
	int id=0;
	for(int i=0;i<len;i++){
		id = id*26+(S[i]-'A');
	} 
	return id;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",S[i]);
		int id = hashFunc(S[i], 3);	//���ַ���S[i]ת��Ϊ����
		hashTable[id]++;		//���ַ����ĳ��ִ�����һ 
	}
	for(int i=0;i<m;i++){
		scanf("%s",temp);
		int id = hashFunc(temp,3);	//���ַ���tempת��Ϊ����
		printf("%d\n",hashTable[id]);	//������ַ����ĳ��ִ��� 
	}

	return 0;
}

