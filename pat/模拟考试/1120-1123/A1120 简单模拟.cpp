//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10005;
bool E[maxn] = {false};	//�жϸ�friend id�Ƿ��Ѿ����� 
int fi[maxn];		//friend

int main(){
	int n;
	scanf("%d",&n);
	int count = 0;			//ͳ��friend id���� 
	
	for(int i = 0;i<n;i++){
		char num[6];
		scanf("%s",num);
		int len = strlen(num);
		int id = 0;
		for(int j=0;j<len;j++){
			id += (num[j]-'0');	//����id 
		}
		if(E[id] == false){
			fi[count++] = id;
			E[id] = true;
		}
	}
	
	printf("%d\n",count);
	sort(fi,fi+count);
	for(int i=0;i<count;i++){
		printf("%d",fi[i]);
		if(i<count-1) printf(" ");
	}

	return 0;
}

