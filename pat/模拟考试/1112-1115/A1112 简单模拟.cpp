//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int position(char c){
	int pos;
	if(c>='a' && c<='z')
		pos = c-'a';	
	else if(c>='0' && c<='9')
		pos = c-'0'+26;
	else if(c == '_')
		pos = 36;
	return pos;
}

int main(){
	int k;
	scanf("%d",&k);
	char str[1005];
	scanf("%s",str); 
	int len = strlen(str);
	
	bool hash[37]={false};		//0~25 a~z 26~35 0~9 36 _
	bool inst[37]={false};		//�ַ����ַ����� 
	
	for(int i=0;i<len;i++){		//�ж��Ƿ����ַ����� 
		inst[position(str[i])] = true;
	} 
	
	int cnt=1;
	char c = str[0];
	for(int i=1;i<len;i++){
		if(c == str[i]){		//��һ���ַ���ǰһ���ַ���� 
			cnt++;
			if(i == len-1 && cnt !=k){
				hash[position(c)] = true;
				break;
			}
		} else{					//�����,�Ҽ���������
			int pos = position(c);
			hash[pos] = true; 	//δ�� 
			c = str[i];
			cnt = 1;
		}
		if(cnt == k){
			c = str[i+1];
			cnt = 0;
		}
	}
	
	//hash�е���true��δ��,
	bool flag = false;
	for(int i=0;i<=36;i++){
		if(i<=25 && hash[i] == false && inst[i] == true){
			flag = true;
			printf("%c",i+'a');
		} else if(i>=26 && i<=35 && hash[i] == false&& inst[i] == true){
			flag = true;
			printf("%c",i-26+'0');
		} else if(i ==36 && hash[i] == false && inst[i] == true){
			flag = true;
			printf("_");
		}
	}
	if(flag == true)		//û���𻵵İ��� 
		printf("\n");
	for(int i=0;i<len;){
		char c =str[i]; 
		int pos = position(c);
		
		printf("%c",c);
		if(hash[pos] == false && inst[pos] == true){	//�� 
			i+=k;
		} else{
			i++;
		}
	} 

	return 0;
}

