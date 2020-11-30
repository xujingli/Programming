//���ڣ�2018/4/30 ʱ�䣺13:47-
/*
��Ҫ��ʾ��
	if(longer(records[j].time,records[j+1].time) >0)
	else if(longer(records[j].time,records[j+1].time) ==0)
	else if(longer(records[j].time,records[j+1].time) <0)
	�����һ�������㣬����еڶ������ڶ��������㣬����е�����������if�����еĺ���ȴ���������Σ��������� 
 �����У�the queries are given in ascending order of the times.��仰���ص㡣���������Բο�P125�������ӶȸߵĿ��� 
 
�Ҵ���ʱ���࿼�Ǳ�Ե��� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct car{
	char id[8];
	int hh,mm,ss;
	char status[4];
}records[100005],valid[100005];

bool cmp(car a,car b){
	if(strcmp(a.id,b.id) != 0)	return strcmp(a.id,b.id)<0;
	else {
		if(a.hh!=b.hh)	return a.hh<b.hh;
		else{
			if(a.mm!=b.mm)	return a.mm<b.mm;
			else{
				if(a.ss!=b.ss)	return a.ss<b.ss;
			}
		}
	}
}

bool cmp1(int a,int b){
	return a>=b;		//�Ӵ�С���� 
}

bool cmp2(car a,car b){		//����ʱ������ 
	if(a.hh!=b.hh)	return a.hh<b.hh;
	else{
		if(a.mm!=b.mm)	return a.mm<b.mm;
		else{
			if(a.ss!=b.ss)	return a.ss<b.ss;
		}
	}
}

int t(int h1,int m1,int s1,int h2,int m2,int s2){	//t2-t1���൱��60��������� 
//	printf("t1:%d:%d:%d\n",h1,m1,s1);
//	printf("t2:%d:%d:%d\n",h2,m2,s2);
	int sec=0;
	if(s2 >= s1) sec+=(s2-s1);
	else{
		sec+=(60-s1+s2);	//����ӽ�һλ
		m2-=1;
	}
	if(m2>=m1)	sec+=((m2-m1)*60); 
	else{		//��Сʱ��һλ 
		sec+=((60-m1+m2)*60);
		h2-=1;
	}
	//Сʱ�����
	sec+=((h2-h1)*3600); 
	
//	printf("t2 - t1:%d:%d:%d\n",(sec/3600),(sec/60)%60,sec%60);
	return sec;
}

bool later(int h,int m,int s,int bh,int bm,int bs){//ʱ��t��bt֮���������,����true 
	if(h>bh) return true;
	else if(h==bh){
		if(m>bm) return true;
		else if(m==bm){
			if(s>=bs)	return true;
		}
	}
	return false;
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	//positive integers N (<= 10000), the number of records, and K (<= 80000) the number of queries
	for(int i=0;i<N;i++){
		scanf("%s %d:%d:%d %s",records[i].id,&records[i].hh,&records[i].mm,&records[i].ss,records[i].status);
	}
	
	sort(records,records+N,cmp);	//����	
	//���濼��ƥ��,�����е�ƥ���¼ȫ����ŵ�valid�У�valid����ʱ������ 
	int num=0;		//������
	int flag=-1;		//����ƥ��
	
	char tid[10005][8];	//������еĳ��ƺ� 
	int time[10005];	//��Ÿó���Ӧ��ȫ��ͣ��ʱ�䣬����Ϊ��λ��һ��num���� 
	char tempid[8];	//�����ʱ��ID
	strcpy(tempid,records[0].id); 
	num++;
	strcpy(tid[num],tempid);	//��ų��ƺš�
	time[num]=0;		//���Ի�ʱ�� 
	
	int h,m,s;		//��ʱ��������������ʱ�� 
	int validrec;	//�����ݴ�Ϸ���¼in���±ꡣ 
	int recnum=0;		//�Ϸ��ļ�¼�� 
	
	for(int i=0;i<N;i++){	//����ƥ�� 
		if(strcmp(records[i].id,tempid)!=0){	//���������ļ�¼����Ҫ���ӳ����������µĳ��ƺ� 
			flag=-1;
			num++;
			strcpy(tempid,records[i].id);	//������ʱ���� 
			strcpy(tid[num],tempid);	//��ų��ƺš�
			time[num]=0;		//��ʼ����ʱ�� 
		} 
		
		if(strcmp(records[i].status,"in")==0){
			flag=0;
			h=records[i].hh; m= records[i].mm; s=records[i].ss;
			validrec=i;		//�ݴ�Ϸ���¼���±꣬�������һ��out��¼ƥ�䣬��Ҫ����in��ŵ�valid�� 
		}
		if(strcmp(records[i].status,"out")==0 && flag==0){	//˵��ƥ��ɹ� 
			 flag=1;	//��ֹ����һ��out����ƥ�� 
			 //�����һ��ƥ���in��¼��valid�У�������out��¼��valid�У�����ʱ�䡣
			 valid[recnum++]=records[validrec];	//��һ�� 
			 valid[recnum++]=records[i];		//��һ��
			 //printf("num:%d\n",num);
			 time[num]+=t(h,m,s,records[i].hh,records[i].mm,records[i].ss); 
		}
	} 	
	
	//��valid����������򣬰���ʱ��˳�򡣲����ô�ʱ�ĳ�����������ʼʱ�̵���Ҫ��ѯ��ʱ�̣�in�ͼ�һ��out�ͼ�һ������д����������������
	//����˵����ѯ��ʱ���ǰ���˳����ģ���ʹ���Լ�˸��Ӷȡ�
	sort(valid,valid+recnum,cmp2);
	
/*	printf("\n\n"); 
	for(int i=0;i<recnum;i++)
	printf("%s %d:%d:%d %s\n",valid[i].id,valid[i].hh,valid[i].mm,valid[i].ss,valid[i].status);
	printf("\n"); 
*/	
	int now=0;			//��¼��ǰ�ж��ٳ���
	int cur=0;			//��¼��ǰ�α��λ�ã�������ѯ����λ������ 
	int bh=valid[cur].hh,bm=valid[cur].mm,bs=valid[cur].ss;	//��ʼʱ�̣�����Ϊÿһ�β�ѯ����һ�����ʱ�� 
	for(int i=0;i<K;i++){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		
		while(later(h,m,s,bh,bm,bs)){	//��Ҫ��ѯ��ʱ��t��bt֮��������ȡ�����������in����out���£����Ҹ���bt 
			if(strcmp(valid[cur].status,"in")==0)
				now++;
			else
				now--;
			if(cur+1<recnum){
				cur++;		//��ѯ�α��һ
				bh=valid[cur].hh; bm=valid[cur].mm; bs=valid[cur].ss;
			}
			else
				break;
		} 
		printf("%d\n",now);
	}

	//�����ǲ�ѯ��������������ʱ�� 
	int longest=0;		//���ʱ�� 
	for(int i=1;i<=num;i++){
		if(time[i]>=longest)
			longest=time[i];
	}
	int c[10005];//���ͣ���ʱ�䳵���±ꡣc[0]-c[numc-1]
	int numc=0; 	//ͣ���ʱ��ĳ�����
	for(int i=1;i<=num;i++){	//ͳ��ͣ���ʱ��ĳ������������±� 
		if(time[i]==longest){
			c[numc++]=i;
		}
	} 
	for(int i=0;i<numc;i++)
		printf("%s ",tid[c[i]]);
	printf("%02d:%02d:%02d",(longest/3600),(longest/60)%60,longest%60);
		
	return 0;
}
/*
*/ 
