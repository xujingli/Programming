//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define p2
//��2
#ifdef p2
const int maxn = 30;
int n,k,x,maxSumSqu = -1,A[maxn];
//����A��n����ѡk����ʹ�ú�Ϊx�����ƽ����ΪmaxSumSqu
vector<int> temp,ans;
//temp�����ʱ������ans���ƽ�������ķ���

//��ǰ����index����������ǰ��ѡ��������ΪnowK
//��ǰ��ѡ����֮��Ϊsum,��ǰ��ѡ����ƽ����ΪsumSqu
void DFS(int index,int nowK,int sum,int sumSqu){
	if(nowK == k && sum == x){			//�ҵ�k�����ĺ�Ϊx 
		if(sumSqu > maxSumSqu){			//����ȵ�ǰ�ҵ��ĸ��� 
			maxSumSqu = sumSqu;
			ans = temp;					//�������ŷ��� 
		}
		return;
	}
	//�Ѿ�������n���������߳���k���������ߺͳ���x,����
	if(index == n || nowK > k || sum > x)	return;
	
	//ѡindex����
	temp.push_back(A[index]);
	DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]); 
	temp.pop_back();
	
	//��ѡindex����
	DFS(index+1,nowK,sum,sumSqu); 
}

int main(){
	scanf("%d%d%d",&n,&k,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	DFS(0,0,0,0);
	printf("%d %d",ans[0],ans[1]);
} 

#endif 


//#define p1
#ifdef p1
const int maxn = 30;
int n,V,maxValue = 0;	//��Ʒ����n,��������V������ֵmaxValue
int w[maxn],c[maxn];	//w[i]Ϊÿ����Ʒ��������c[i]Ϊÿ����Ʒ������ 

//DFS1()���������е���Ʒ��ѡ�����ġ�ʱ�临�Ӷ�ΪO(n^2) 
void DFS1(int index,int sumW,int sumV){
	if(index == n){
		if(sumW <= V && sumV >maxValue){
			maxValue = sumV;			//��������������ʱ��������ֵ 
		}
		return;
	}
	//��·��
	DFS1(index+1,sumW,sumV);				//��ѡ��index����Ʒ 
	DFS1(index+1,sumW+w[index],sumV+c[index]); //ѡ��index����Ʒ 
}

void DFS2(int index,int sumW,int sumV){
	if(index == n)	return;
	
	DFS2(index+1,sumW,sumV);		//��ѡindex����Ʒ 
	if(sumW + w[index] <= V){		//��ǰ��Ʒ���뱳�����Ƿ񳬹���������û�г���������뱳�� 
		if(sumV + c[index] > maxValue){
			maxValue = sumV + c[index];
		}
		DFS2(index+1,sumW + w[index],sumV+c[index]);
	}
}

int main(){
	scanf("%d %d",&n,&V);
	for(int i=0;i<n;i++)
		scanf("%d",&w[i]);		//ÿ����Ʒ�������������Ǽ�ֵ 
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]); 
		
	DFS2(0,0,0); 
	printf("%d\n",maxValue);

	return 0;
}
#endif

