//���ڣ�2018/6/2 ʱ�䣺14:18-13:11
/*
��Ϊ���û��ע�⵽�����ظ��������⣬����Ľ������ ��78�� 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int neednum[62],provnum[62];	// ��Ҫ�ĺ��̵��ṩ�� ÿһ�ֵĸ�����0~25Ϊ'a'~'z'.26~51Ϊ'A'~'Z'.52~61Ϊ'0'~'9'
	memset(neednum,0,sizeof(neednum));
	memset(provnum,0,sizeof(provnum));
	
	char prov[1005],need[1005];
	scanf("%s",prov);
	scanf("%s",need);
	
	//��������Ϣת����neednum��provnum�С���ͳ��ÿ�����ӵĸ���
	int cur;
	for(int i=0;i<strlen(prov);i++){
		if(prov[i]>='0' && prov[i]<='9'){
			cur=prov[i]-'0'+52;
			provnum[cur]++;
		}
		else if(prov[i]>='a' && prov[i]<='z'){
			cur=prov[i]-'a';
			provnum[cur]++;
		}
		else if(prov[i]>='A' && prov[i]<='Z'){
			cur=prov[i]-'A'+26;
			provnum[cur]++;
		}
	}
	
	for(int i=0;i<strlen(need);i++){
		if(need[i]>='0' && need[i]<='9'){
			cur=need[i]-'0'+52;
			neednum[cur]++;
		}
		else if(need[i]>='a' && need[i]<='z'){
			cur=need[i]-'a';
			neednum[cur]++;
		}
		else if(need[i]>='A' && need[i]<='Z'){
			cur=need[i]-'A'+26;
			neednum[cur]++;
		}
	}
	//������ϣ�����neednum�д�ŵ��Ƕ�ÿһ�����ӵ�����������provnum�д�ſ����ṩ���ӵ�����
/*	
	for(int i=0;i<62;i++){
		if(neednum[i]!=0)
			printf("%d %d\n",i,neednum[i]);
	}
*/	
	//�������жϣ����������Ҫ����ô���Yes���������������ṩ���ַ�������֮�
	//���������Ҫ����ô���No,���Ҽ�¼ȱʧ�ĸ���
	int flag=0;
	int num=0;	//��¼ȱ�����ӵĸ�������flagΪ1ʱ���
	for(int i=0;i<strlen(need);i++){
		if(need[i]>='0' && need[i]<='9'){
			cur=need[i]-'0'+52;
		}
		else if(need[i]>='a' && need[i]<='z'){
			cur=need[i]-'a';
		}
		else if(need[i]>='A' && need[i]<='Z'){
			cur=need[i]-'A'+26;
		}	//�����α� 
		
		if(provnum[cur] >= neednum[cur]){	//�������� 
			continue;
		} 
		else{
			flag=1;	//���������� 
			num+=(neednum[cur] - provnum[cur]);
			neednum[cur]=provnum[cur]=0;		//��Ϊ0����ֹ�����жϣ�����num���� 
		}
	} 
	
	if(flag==0){
		printf("Yes %d",strlen(prov)-strlen(need));
	}else{
		printf("No %d",num);
	}

	return 0;
}

