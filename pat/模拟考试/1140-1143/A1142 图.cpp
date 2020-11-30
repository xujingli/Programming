//日期：2018/ 时间：

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
int ne,nv;				//边数，点数 
int query[maxv],k;		//查询数组，个数 
bool in[maxv]={false};	//点是否在查询数组中 

bool isClique(){		//判断查询数组内是否每个元素都和其他元素相邻 
	int flag=0;
	//判断
	for(int a=0;a<k-1;a++){
		for(int b=a+1;b<k;b++){
			if(G[query[a]][query[b]]==0){
				flag = 1;			//非联通 
			}
		}
	} 
	if(k==1 || flag==0) return true;
	else return false;		//根本不全部相邻 
}

bool isMax(){					//如果能增加一个额外的顶点，使得这个点和其他各个点都连接，则非最大。 
	for(int i=1;i<=nv;i++){			 
		if(in[i] == false){			//遍历每一个不在查询数组的其他元素。 
			int count = k;
			for(int j=0;j<k;j++){	//看这个元素和 查询数组 里面的其他元素是否全部联通。一旦全部联通，则返回false 
				if(G[query[j]][i] ==1 ){	//连通 
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
	}//构造图  
	
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){		//对于每一次查询 
		memset(query,0,sizeof(query));
		memset(in,false,sizeof(in));		//初始化数组 
		
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&query[j]);
			in[query[j]] = true;
		}	
		//输入要查询的元素
		
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
