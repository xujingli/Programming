//����ϸ�£���ϸ����
//9:02-10:20 19/20
// 
//����ȷ���==�Ͳ�Ҫд��=�ˣ���ô�ͼ��Ĵ��󣬽����Ȼ�Ѿ����������أ������˺ܳ�ʱ�� 

/*
1.for(;;i++),����ѭ��ʱ��i�Ѿ�������1����һ��Ҫ���� 
2.�ύʱ��ҪҪ���Լ��Ĳ��Դ�ӡ�����ע�͵����������ʾ�𰸴���
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char snum[10010];	//��ѧ������
	char num[20010];	//��ͨ������
	scanf("%s",snum);
	
	char numsign=snum[0];		//���ֵ�������
	int len=0;			//�ӵ�һ�����ֿ�ʼ��"E"֮ǰ�ĳ���,����С���� 
	char expsign;		//ָ����������
	int exp=0;			//ָ����ֵ
	
	int i; 
	for(i=1;i<strlen(snum);i++) {		//������ѧ������������ַ������������ϵ���Ϣ 		
		if(snum[i]!='E')
			len++;
		else
			break;
	}
	
	expsign=snum[i+1];
	//����Ϊָ���ļ���
	int p=1;			//Ȩֵ 
	for(int j=(strlen(snum)-1) ; j >= i+2 ; j--){
		exp += (snum[j]-48) * p;
		p*=10;		//Ȩֵ���� 
	} 
	
	//printf("%c %d %c %d\n",numsign,len,expsign,exp); 
	//ע���ѧ���������飺+���±�0��1���±�1��.���±�2�� 
	if(expsign == '-'){
		num[0]='0';
		num[1]='.';
		int j;
		for(j=2;j<=exp;j++)		//����exp-1���㣬����д�����������������±��2~exp 
			num[j]='0';
			
		num[j++]=snum[1]; 		//�����±��1��ʼ���±�0�������� 
		for(int k=3;k<=len;k++)
			num[j++]=snum[k];	//��num���濪ʼ���� snum�����±��3~len�����ֶ��ŵ����� 
	}
	else if(expsign == '+'){
		//���exp>len-2��Ҫ��ĩβ���㣬exp==len-2,Ҫȥ������С���㣬exp<len-2ֱ���ƶ�С���㼴��
		if(exp < len-2){		//ֻ��Ҫ�ƶ�С���� 
			num[0]=snum[1];
			int j;
			for(j=1;j<=exp;j++)
				num[j]=snum[j+2];	//j=1~exp��λ���ϣ�num�д��snum�������������� 
			num[j++]='.';
			for(int k=j+1;k<=len;k++)
				num[k-1]=snum[k];	//�ٰѴ�С����֮������ְᵽnum�����С����Ƹ����Ѷ�����ʵд������������һ�¾Ͷ��� 
		}
		else if(exp > len-2){		//��Ҫ���㣬��Ҫ��exp-(len-2)����,��ô����len-1+[exp-(len-2)]λ���� 
			num[0]=snum[1];
			int j;
			for(j=1;j<=len-2;j++)
				num[j]=snum[j+2];	//���ƶ�Ӧλ������
			//����ѭ��ʱ��j�Ѿ��Լ�һ 
			for(int k=j;k <= j-1+(exp-(len-2));k++)	//��exp-(len-2)��1�� 
				num[k]='0'; 
			//printf("j:%d\n",j);
		}
		else if(exp == len-2){		//��ĩβ��С����ȥ�� 
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

