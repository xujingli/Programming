//���ڣ�2018/ ʱ�䣺

#define p2

#ifdef p1
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
 
int vt[210][210];
 
void judge(int *arr, int n, int nv) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (!vt[arr[i]][arr[j]]) {
                printf("Not a Clique\n");
                return;
            }
        }
    }
    //
    for (int i = 1; i <= nv; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (vt[i][arr[j]]) {
                cnt++;
            }
        }
        if (cnt == n) {
            printf("Not Maximal\n");
            return;
        }
    }
    printf("Yes\n");
}
 
int main() {
    int nv = 0, ne = 0, a = 0, b = 0, m = 0, k = 0;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &a, &b);
        vt[a][b] = vt[b][a] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        int *arr = new int[k];
        for (int j = 0; j < k; j++) {
            scanf("%d", &arr[j]);
        }
        judge(arr, k, nv);
    }
    return 0;
}
#endif

#ifdef p2
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxv = 205;
int G[maxv][maxv];
int ne,nv;				//���������� 
int query[maxv],k;		//��ѯ���飬���� 
bool in[maxv]={false};	//���Ƿ��ڲ�ѯ������ 

bool isClique(){		//�жϲ�ѯ�������Ƿ�ÿ��Ԫ�ض�������Ԫ������ 
	int flag=0;
	//�ж�
	for(int a=0;a<k-1;a++){
		for(int b=a+1;b<k;b++){
			if(G[query[a]][query[b]]==0){
				flag = 1;			//����ͨ 
			}
		}
	} 
	if(k==1 || flag==0) return true;
	else return false;		//������ȫ������ 
}

bool isMax(){					//���������һ������Ķ��㣬ʹ�����������������㶼���ӣ������� 
	for(int i=1;i<=nv;i++){			 
		if(in[i] == false){			//����ÿһ�����ڲ�ѯ���������Ԫ�ء� 
			int count = k;
			for(int j=0;j<k;j++){	//�����Ԫ�غ� ��ѯ���� ���������Ԫ���Ƿ�ȫ����ͨ��һ��ȫ����ͨ���򷵻�false 
				if(G[query[j]][i] ==1 ){	//��ͨ 
					count--;
				}
			} 
			//printf("%d\n",count);
			if(count == 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int m;
	memset(G,0,sizeof(G));
	scanf("%d%d",&nv,&ne);
	
	for(int i=0;i<ne;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=G[v2][v1]=1;
	}//����ͼ  
	
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){		//����ÿһ�β�ѯ 
		memset(query,0,sizeof(query));
		memset(in,false,sizeof(in));		//��ʼ������ 
		
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&query[j]);
			in[query[j]] = true;
		}	
		//����Ҫ��ѯ��Ԫ��
		
		if(!isClique()) printf("Not a Clique\n"); 
		else if(isMax()) printf("YES\n");
		else printf("Not Maximal\n");
	}

	return 0;
}
#endif
/*
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
*/
