//���ڣ�2018/4/21 ʱ�䣺13:59-15:01 17/20   15:01-15:07 AC
/*
����ԭ��Ѱ�Һ�׺ʱ���Ӻ���ǰ������һ�����ֲ���ͬʱ������break�� 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	int N;
	scanf("%d",&N);
	char K[105][260];		//��һά�ĳ���ΪN
	
	getchar();			//��ȡ�����������������Ļ��з�	
	for(int i=0;i<N;i++){
		gets(K[i]);
	} 
	
	int suffixlen=0;	//��׺�ĳ���
	char suffix[260];	//�����ź�׺ 
	for(int i=(strlen(K[0])-1),j=(strlen(K[1])-1) ; i>=0 && j>=0 ; j--,i--){	//���ҳ�ǰ�����ĺ�׺ 
		if(K[0][i]==K[1][j])
			suffix[suffixlen++] = K[0][i];
		else
			break; 		//�������ͬ�������˳��������������ˣ����� 
	}
	
	if(suffixlen==0){		//���ǰ������û�й�����׺�����˳� 
		printf("nai");
		return 0;
	} 
	
	//printf("%s",suffix);
	for(int a=2;a<N;a++){	//�ҳ�ǰ�����Ĺ�����׺�󣬴ӵ�������ʼ�������±��� 
		int curstr = strlen(K[a])-1;	//�ַ����α��������
		int cursuf = 0;					//��׺�α��������
		int count=0;			//ͳ�ƺ�׺�ַ��뵱ǰ�ַ�����ͬ���� 
		for(;cursuf<suffixlen && curstr>=0 ;cursuf++,curstr--){//��׺�ַ����α���󻬶� ��ǰ�ַ����α�������󻬶� 
			if(suffix[cursuf] == K[a][curstr])
				count++;
			else
				break; 
		} 
		suffixlen = count;		//���º�׺����
		
		if(suffixlen == 0)
			break;				//����ͬ��׺ 
	}
	
		 
	if(suffixlen==0){	//����ͬ��׺
		printf("nai");
	}
	else{
		for(int i=suffixlen-1;i>=0;i--)
			printf("%c",suffix[i]);
	} 
	
	return 0;
}

