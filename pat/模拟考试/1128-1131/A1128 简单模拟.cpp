//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10005; 
int Q[maxn];		//Q
bool dp[maxn] = {false};//ȷ��ÿ����ֻ����һ�� 
bool pl[maxn]={false},mnn[maxn]={false},mnp[maxn]={false};	//�����������Ľ�� 

int main(){
	int k;
	scanf("%d",&k);
	
	for(int j=0;j<k;j++){
		memset(Q,0,sizeof(Q));
		memset(dp,false,sizeof(dp));
		memset(pl,false,sizeof(pl));
		memset(mnn,false,sizeof(mnn));
		memset(mnp,false,sizeof(mnp));
		
		int n;
		scanf("%d",&n);
		bool flag = false;
		for(int i=0;i<n;i++){
			scanf("%d",&Q[i]);
		}
		
		for(int i=0;i<n;i++){
			if(dp[Q[i]] == false){	//�ж��Ƿ������ͬ��Ԫ�� 
				dp[Q[i]] = true;
			} else{
				flag = true;
				printf("NO\n");
				break;
			}
			
			int p = Q[i]+i;
			if(pl[p] ==false){		//��ͬһ���Խ����� 
				pl[p] = true;
			} else {
				flag = true;
				printf("NO\n");
				break;
			}
			
			int m = Q[i] - i;
			if(m >=0){
				if(mnp[m] ==false){		//��ͬһ���Խ����� 
					mnp[m] = true;
				} else {
					flag = true;
					printf("NO\n");
					break;
				}
			} else{
				m = -1 * m;
				if(mnn[m] ==false){		//��ͬһ���Խ����� 
					mnn[m] = true;
				} else {
					flag = true;
					printf("NO\n");
					break;
				}
			}
		}
		if(flag == false)
				printf("YES\n");
	} 

	return 0;
}

