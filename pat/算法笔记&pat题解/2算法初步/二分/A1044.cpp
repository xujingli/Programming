//���ڣ�2018/6/13 ʱ�䣺20:10- 21:10 19/25
/*
����
*/ 
#include <stdio.h>
#include <stdlib.h>

const int maxn = 100005;

//#define p1
#define p2
//#define p3

/*******************************p3*********************************************/
#ifdef p3
//�鱾�ϵĽⷨ�������н������α�������һ�α���������ڵ���S����ӽ�S�ĺ�ֵnearS��
//�ڶ��α����ҳ���Щ��ֵǡ��ΪnearS�ķ�����������ܸ��Ӷ�ΪO(nlogn)
int sum[maxn];
int n,S,nearS = 100000010;
//upper_bound����[L,R]�ڣ���һ������x��λ�ô����ֵΪ[��һ��Ԫ�����꣬���һ��Ԫ�ص���һ������] 
int upper_bound(int L,int R,int x){
	int left = L,right = R,mid;
	while(left < right){
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	scanf("%d%d",&n,&S);			//Ԫ�ظ�������ֵS
	sum[0]=0;						//��ʼ��sum[0]=0
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	} 
	for(int i=1;i<=n;i++){			//ö����˵� 
		int j = upper_bound(i,n+1,sum[i-1]+S);		//���Ҷ˵�
		if(sum[j-1] - sum[i-1] == S){			//���ҳɹ� 
			nearS = S;				//��ӽ���ֵ����S
			break; 
		} else if(j <= n && sum[j] - sum[i-1] < nearS){
			//����nearS
			nearS = sum[j] - sum[i-1]; 
		}
	}
	for(int i=1;i<=n;i++){
		int j = upper_bound(i,n+1,sum[i-1]+nearS);		//���Ҷ˵�
		if(sum[j-1] - sum[i-1] == nearS){			//���ҳɹ� 
			printf("%d-%d\n",i,j-1);				//�����˵���Ҷ˵� 
		}
	}
}

#endif
/******************************************************************************/


/*******************************p2*********************************************/
//���ַ� 
#ifdef p2
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	int D[maxn];
	int Sum[maxn];
	Sum[0]=0;
	
	int t[maxn][2];			//��һά��ŵ�һ���±꣬�ڶ�ά��ų���mʱ���ܺ�
	int tnum=0;				//t�ĳ���

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){ 
		scanf("%d",&D[i]);
		Sum[i]=Sum[i-1]+D[i];
	}//����D[i],���ҵõ�Sum
	
	int j;
	int flag=0;	
	 
	for(int i=1;i<=n;i++){
		j = upper_bound(Sum+i,Sum+n+1,Sum[i-1]+m) - Sum;
		if(Sum[j-1] == Sum[i-1]+m){		//���������ȵĻ����������������С�Ĵ��� Sum[i-1]+m ������ 
			flag = 1;
			printf("%d-%d\n",i,j-1);
		}
		else if(Sum[j] > Sum[i-1]+m){			//����S[j]����Sum[i-1]+mʱ������¼��������֣���i,j���� 
			t[tnum][0] = i;
			t[tnum++][1]=Sum[j]-Sum[i-1]; 
		}
		//printf("%d\n",j);
	}
//	for(int i=0;i<tnum;i++)
//		printf("%d %d\n",t[i][0],t[i][1]);
	
	int min=t[0][1];
	if(flag == 0){		//��ƥ���Ӵ� 
		for(int i=0;i<tnum;i++)
			if(t[i][1] < min)
				min = t[i][1];		//�ҳ���С���Ǹ��Ӵ� 
				
		int cur;				//��¼�Ӵ��Ŀ�ͷ�ͽ�β������� 
		for(int i=0;i<tnum;i++){
			if(t[i][1]==min){		//�Ӵ���t[i][0]��ͷ���ҵ����Ľ�βend.��D[begin]��ʼ�ۼӣ��ۼӵĺ͵���minʱ��Ϊ��β 
				cur=t[i][0];
				printf("%d-",cur);
				int total=0;
				while(total != min){
					total+=D[cur++];
				} 
				printf("%d\n",cur-1);
				
			}
		}
	}
	
	return 0; 
} 
#endif
/******************************************************************************/

/*******************************p1*********************************************/
#ifdef p1
int main(){
	int n,m;
	int D[maxn];
	int t[maxn][2];			//��һά��ŵ�һ���±꣬�ڶ�ά��ų���mʱ���ܺ�
	int tnum=0;				//t�ĳ���

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&D[i]);
	
	int i=1,j=1;
	int temp=D[i];	//�ݴ�D[i]-D[j]���ܺ� 
	int flag = 0;
	while(i<=j && j!=n){
		while(i<=j && temp < m){	//temp��Ŀǰ��ŵ�С��m����jָ����󻬶� 
			j++;
			temp+=D[j];
		}
		while(temp > m){		//���temp�ܴ�ŵĴ���m,��iָ�����
			//��Ҫ��¼�´�ʱ���ܼ�ֵ��С���Լ���ʼָ��i����ֹ����û��������������Ҫ�����е���Сֵ�����
			//�����ƶ������temp��С 
			t[tnum][0] = i;
			t[tnum++][1]=temp;
			
			if(i==j){				//i��jָ��ͬһ��ֵ�����ֵ����m 
				i++; j++;
				temp=D[i];
			}
			else{
				i++;
				temp-=D[i-1];
			}
		}
		if(temp == m){
			//printf("i:%d j:%d\n",i,j);
			flag=1;
			printf("%d-%d\n",i,j); 
			i++;
			j++;
			temp = temp+D[j]-D[i-1];
		} 		
	} 

	int min=t[0][1];
	if(flag == 0){		//��ƥ���Ӵ� 
		for(int i=0;i<tnum;i++)
			if(t[i][1] < min)
				min = t[i][1];		//�ҳ���С���Ǹ��Ӵ� 
		int cur;				//��¼�Ӵ��Ŀ�ͷ�ͽ�β������� 
		for(int i=0;i<tnum;i++){
			if(t[i][1]==min){		//�Ӵ���t[i][0]��ͷ���ҵ����Ľ�βend.��D[begin]��ʼ�ۼӣ��ۼӵĺ͵���minʱ��Ϊ��β 
				cur=t[i][0];
				printf("%d-",cur);
				int total=0;
				while(total != min){
					total+=D[cur++];
				} 
				printf("%d\n",cur-1);
				
			}
		}
	}

	return 0;
}
#endif
/******************************************************************************/
