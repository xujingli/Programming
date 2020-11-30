//���ڣ�2018/5/2 ʱ�䣺23:04- 

/*https://www.cnblogs.com/kl2blog/p/6908048.html
�ڴ����Ĺ���ܼ򵥣�
����1.��ʼ��ַΪ�ñ���������ռ�ڴ�������������������㲿���������������ռ�ڴ����������
����2.�ýṹ����ռ���ڴ�Ϊ�ṹ���Ա����������������͵�������

��˼�����⽨������ϸ�����Ļ����ϣ������ľͻ�Խ��Խ�죬��Ҫ����һ�ж���������ģ������Լ���ֻҪÿ�춼Ŭ����һ������� 
��һ���������ݣ� 
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn=40010;
 
struct stu{
	int GE,GI,sum;
	int stuID;	//������ѧ����� 
	int cho[6];		//ѧУѡ�� 
}studs[maxn];

int sch[101][maxn];	//ÿ��ѧУ��¼ȡ���� .����sch[i][0]��¼��i��ѧУ��ʵ��¼ȡ�������ɼ���ͬ���¼�����Դ˴���������ȷ�ģ��� 
					//��sch[][1]��ʼ��¼��i��ѧУ¼ȡ�ĵ�1���˵ı�� 
void init(int M){	//��ʼ�� 
	for(int i=0;i<M;i++)
		sch[i][0]=0;
} 

bool cmp(stu a,stu b){
	if(a.sum != b.sum)	return a.sum>b.sum;
	else return a.GE > b.GE;
} 

int main(){
	int N,M,K;	//N�������ߡ�M��ѧУ��K������ѡ�� 
	// N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; 
	//and K (<=5), the number of choices an applicant may have.
	scanf("%d%d%d",&N,&M,&K);
	init(M); 
	int num[101];	//M��ѧУ��ÿ��ѧУ������ .num[0]��ʾ��0��ѧУ������ 
	for(int i=0;i<M;i++)
		scanf("%d",&num[i]);
		
	//��һ��ѧУ�����¼�������ѧУѧ���ı�ţ��Լ�����  
	for(int i=0;i<N;i++){
		scanf("%d%d",&studs[i].GE,&studs[i].GI);
		studs[i].sum=(studs[i].GE+studs[i].GI)/2;	
		studs[i].stuID=i;
		for(int j=0;j<K;j++){ 
			scanf("%d",&studs[i].cho[j]);	//�־Ը 
		} 
	} 
	
	sort(studs,studs+N,cmp);		//���ܷ����� 
	//printf("%d\n",studs[2].GE); 
	//num[choice]��ʾchoiceѧУʣ��������ϼ��١�  
	//stu[i].cho[1,2---K-1]���β鿴�������ѧУ�����Ƿ�����,
	for(int i=0;i<N;i++){	//����ÿһ��������  
		for(int j=0;j<K;j++){	//������������ѡ�� 
			int choice = studs[i].cho[j];	//��j��־Ը���ж��Ƿ���Ա�¼ȡ
			if(num[choice]!=0){//�����ѧУ����������ߺ��Ǹ�choiceѧУ�ո�¼ȡ�����һ�� �ֺܷ�GE������ͬ��				
				//��ѧУ��������Ͱ����ѧ����ż�¼����Ӧ��ѧУ�
				num[choice]--;
				sch[choice][0]++;
				sch[choice][sch[choice][0]]=studs[i].stuID;		//��¼ѧ����� 
				break; 
			}
			if(num[choice]==0 && sch[choice][0]!=0 && (studs[sch[choice][sch[choice][0]]].sum==studs[i].sum && studs[i].GE==studs[sch[choice][sch[choice][0]]].GE )){
				//¼ȡ�ĵڶ������ 
				sch[choice][0]++;
				sch[choice][sch[choice][0]]=studs[i].stuID;		//��¼ѧ����� 
				break; 
			}
		} 
	} 
	
	for(int i=0;i<M;i++){
		sort(sch[i]+1,sch[i]+sch[i][0]+1);	//��ÿһ�н����������� 
		//printf("%d: ",i);
		for(int j=1;j<=sch[i][0];j++){
			if(j == sch[i][0])
				printf("%d",sch[i][j]);
			else
				printf("%d ",sch[i][j]);
		} 
		printf("\n");
	}

	return 0;
}

