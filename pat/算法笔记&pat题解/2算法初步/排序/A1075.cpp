//���ڣ�2018/4/29 ʱ�䣺12:46-13:03 ��ͣ	4/30 9:50-12:00	������  13:00-13:20 19/25
/*
�����ϻ�ѵ����P112 
��Ϊ���������
	1��ȫ����û���ύ
	2��û����ͨ��������ύ
	3������ͨ��������ύ
���޷�ͨ��������ύ�÷ּ�Ϊ0����ʾ�����й��ύ��
1����2���Ŀ�������Ҫ�����
����ĳ������������ͨ��������ύ��Ϊ0�֣����ǿ����ĳɼ�Ϊ0�֣�����ҲҪ������� 

��˼���㼱�Ÿ�ʲô�أ���Ŀ�����������������������ȥ���⣬����ȥ���� 
*/				 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 10010;
struct Student{
	int id;
	int score[6];	//ÿ����ĵ÷� 
	bool flag;
	int score_all;
	int solve;		//���������� 
}stu[maxn]; 

int n,k,m;
int full[6];		//ÿ���������
bool cmp(Student a,Student b){
	if(a.score_all != b.score_all)	return a.score_all > b.score_all;
	else if(a.solve != b.solve)	return a.solve > b.solve;
	else return a.id < b.id;
} 

void init(){	//��ʼ�� 
	for(int i=1 ;i <= n ;i++){
		stu[i].id = i;
		stu[i].score_all = 0;
		stu[i].solve = 0;
		stu[i].flag = false;		//��ʼ��Ϊû����ͨ��������ύ
		memset(stu[i].score,-1,sizeof(stu[i].score));	//��Ŀ�÷ֱ��Ϊ-1 
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i=1;i<=k;i++){			//��ֵ 
		scanf("%d",&full[i]);
	}
	
	int u_id,p_id,score_obtained;	//����id,��Ŀid���������
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		
		if(score_obtained != -1)	//�����Ǳ��������ÿ�������ͨ��������ύ
			stu[u_id].flag = true;
		
		if(score_obtained == -1 && stu[u_id].score[p_id] == -1)	//ĳ���һ�α�����󣬷�ֵ��Ϊ0�֣��������
			stu[u_id].score[p_id] = 0;
		
		if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id])	//ĳ���һ�λ�����֣�������������һ
			stu[u_id].solve++;
			
		if(score_obtained > stu[u_id].score[p_id]) 	//ĳ���ø��ߵķ�ֵ���򸲸�
			stu[u_id].score[p_id] =  score_obtained;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j] != -1){	//�����ܷ�
				stu[i].score_all += stu[i].score[j]; 
			}
		}
	}
	
	sort(stu+1,stu+n+1,cmp);
	int r = 1;	//��ǰ����
	for(int i=1;i<=n && stu[i].flag == true;i++){
		if(i>1 && stu[i].score_all != stu[i-1].score_all)	//��ǰ������������ǰһλ����������������Ϊ�ڸÿ���֮ǰ���ܿ�����
			r=i;
			
		printf("%d %05d %d",r,stu[i].id,stu[i].score_all);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j] == -1)
				printf(" -");
			else
				printf(" %d",stu[i].score[j]); 
		} 
		printf("\n");
	} 
	
	return 0;
}
