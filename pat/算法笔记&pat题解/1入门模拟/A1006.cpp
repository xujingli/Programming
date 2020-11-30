//����ϸ�£���ϸ����
//9:00-9:45  19/25
//    -10:45 AC
#include <stdio.h>
#include <stdlib.h>

/*
p1�����д��󣬴���ԭ���ǣ�
	1.�����а��ֽ�һ��һ����ÿһ���ַ�λ�ø�ֵ������������ʱ��ȫ�������
	�����ȸ�id[1]��ֵ'abcdefg' ,�ڶ����ְ��ֽڸ�ֵ����'nnn' ����ôprintfʱ�������nnndefg��
	2.�������ֻ�����������15���ռ䣬��ô���ĳ���ַ�������ʮ����ַ�����ô�������������һ��'\0'�Ľ�����
	3.������ڸ����Ӵ󣬿�����p2�Ƕ�ô����ˬ�������ṹ����ֱ�ӿ��Ը�ֵ�ģ� 
*/
//#define p1
#ifdef p1
bool early(char t1[],char t2[]){	//���t1��t2�磬�򷵻�true��ʱ���ʽΪ HH:MM:SS��8λ
	//��ʱ�����𼶱Ƚϣ���Լʱ�� 
	int h1,h2;
	h1=(t1[0]-48)*10+(t1[1]-48);	//string->int
	h2=(t2[0]-48)*10+(t2[1]-48);
	if(h1 < h2)
		return true;
	else if(h1 > h2)
		return false;
	else{
		int m1,m2;
		m1=(t1[3]-48)*10+(t1[4]-48);
		m2=(t2[3]-48)*10+(t2[4]-48);
		if(m1 < m2)
			return true;
		else if(m1 > m2)
			return false;
		else{
			int s1,s2;
			s1=(t1[6]-48)*10+(t1[7]-48);
			s2=(t2[6]-48)*10+(t2[7]-48);
			if(s1 < s2)
				return true;
			else
				return false; 
		}
	}
}

int main(){
	int M;
	scanf("%d",&M);
	char s[4][20];		//s[1]��ID s[2]�ǽ���ʱ�� s[3]�ǳ���ʱ��
	char time[3][8];	//time[1]Ϊ��ǰ�������ʱ�䣬time[2]Ϊ��ǰ�������ʱ�� 
	char id[3][20];    //id[1]�����������˵�id,id[2]�������ȥ�˵�id 
	
	scanf("%s",s[1]);
	getchar();
	scanf("%s",s[2]);
	getchar();
	scanf("%s",s[3]);
	
	for(int i=0;i<15;i++)
		id[1][i]=id[2][i]=s[1][i];	//�Ȱѵ�һ��������Ϊ�������������뿪 
		
	for(int i=0;i<8;i++){
		time[1][i]=s[2][i];
		time[2][i]=s[3][i];
	}
		
	for(int i=1;i<M;i++){
		scanf("%s",s[1]);
		getchar();
		scanf("%s",s[2]);
		getchar();
		scanf("%s",s[3]);
							//�ٴ�����id,ʱ��
		if(early(s[2],time[1])){	//��������ʱ��ȵ�ǰ�������ʱ�仹Ҫ�� 
			for(int j=0;j<15;j++)	
				id[1][j]=s[1][j];	//��Ѹ����jd��¼���� 
				
			for(int j=0;j<8;j++)	//��Ѹ����ʱ���¼���� 
				time[1][j]=s[2][j]; 
		}
		
		if(early(time[2],s[3])){		//���s[3]>tjme[2] ,��tjme[2]�ȸ������ʱ���� 
			for(int j=0;j<15;j++)	
				id[2][j]=s[1][j];	//��Ѹ����jd��¼���� 
			for(int j=0;j<8;j++)	//��Ѹ����ʱ���¼���� 
				time[2][j]=s[3][j];
		} 	
	}
	
	printf("%s %s",id[1],id[2]); 

	return 0;
}
#endif

#define p2
#ifdef p2
//ʱ�� HH:MM:SS������� printf("%d:%d:%d",&hh,&mm,&ss); 

struct node{
	char id[20];
	int hh,mm,ss;	//ans1�������ʱ�䣬ans2�������ʱ�� 
}temp,ans1,ans2;

bool early(node node1,node node2){	//node1ʱ������node2ʱ�䣬����true
	if(node1.hh != node2.hh)	return node1.hh < node2.hh;
	if(node1.mm != node2.mm)	return node1.mm < node2.mm;
	
	return node1.ss < node2.ss;	
} 

int main(){
	int n;
	scanf("%d",&n);
	ans1.hh=24;ans1.mm=60;ans1.ss=60;	//�ѳ�ʼ����ʱ��������
	ans2.hh=0 ;ans2.mm=0 ;ans2.ss=0 ; 	//�ѳ�ʼ�뿪ʱ����Ϊ��С
	
	for(int i=0;i<n;i++){
		//�ȶ������ʱ�� 
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		if(early(temp,ans1))
			ans1=temp;
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(early(ans2,temp))
			ans2=temp;		 
	} 
	printf("%s %s",ans1.id,ans2.id);
	return 0;
}

#endif
