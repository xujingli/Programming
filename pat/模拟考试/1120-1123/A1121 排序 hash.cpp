//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int cp[maxn];		//��i����ʾi��cp
bool in[maxn] = {false};	//�Ƿ�μ� 
const int INF = 0x7fffffff;

int main(){
	int n;
	scanf("%d",&n);
	
	int n1,n2;
	for(int i=0;i<n;i++){
		scanf("%d %d",&n1,&n2);
		cp[n1] = n2;
		cp[n2] = n1;
	}
	
	int m;
	scanf("%d",&m);
	int query[10005];
	for(int i=0;i<m;i++){
		scanf("%d",&query[i]);
		in[query[i]] = true;
	}
	
	int c = m;
	//printf("m: %d\n",m);
	for(int i=0;i<m;i++){	//query[i]��ʾ����˱�� 
		if(in[cp[query[i]]]){		//�������˵�cp(cp[query[i]])���ˣ������������ɾ�� 
			//ɾ���ķ����ǣ�query[i]��Ϊ�����.count--
			 query[i] = INF;
			 c--;
		}
	}
	
	sort(query,query+m);
	printf("%d\n",c);
	for(int i=0;i<c;i++){
		printf("%05d",query[i]);
		if(i<c-1) printf(" ");
	}

	return 0;
}

