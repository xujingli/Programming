//���ڣ�2018/ ʱ�䣺
//���ѣ�1����֪������ô�洢ͼ���ڽӱ��ڽӾ���
//		2��Ӧ����ʹ���������������������Ϊ3�ҵ�����ڵ㣬���ҵ�һ���ڵ�����Aͬ�ԣ��ڶ����ڵ�����Bͬ�ԡ���������һ������׼����� 
// 		3��2����˵�ļ����� ��¼���Լ������������ô���ƣ� 
/*
	�����ȱ���A���������ڵ�B���ų��Ա���A����ͬ�ġ�
	����A��ÿ���������Ա���ͬ�ĵ�ʱ��
		��ȥ����D��ÿ���������Ա���ͬ�ĵ�C
		Ȼ���ж�B��C�Ƿ����ڣ������������Ҫ��
ע��㣺
�ٴ洢���������ڵ�ʱ���ڽӱ�
�ж��Ƿ��������ڽӾ���
������ÿ�����ID��ΧΪ0~9999����������ô�������
������������ֻ��300��
��Ӧ������������飬��ÿ��ID��һ��ת�����ܹ�ת����0~300�����š�
��A�����ڵ㲻����D��D�����ڵ㲻����A����Ϊ���Ǳ���Ҫ����2���˴��ݡ�
�۲�ѯʱ��A��DҲ�Ǵ������ģ�ҲҪ����
�ܻ��С�-0000�����ڵ����������Ӧ���������ַ�������ת������ID��
�����Ϊ4λdigit�������ʱҪ��0
*/


#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
 
#define long long ll
const int MAXN = 1e4 + 10;
const int INF = 0x7fffffff;
const int dx[]={0, 1, 0, -1};
const int dy[]={1, 0, -1, 0};  
int n, m;
struct NODE{
    vector<int>same;
}node[MAXN];
 
map<int, map<int, bool> >mp;
struct ANS{
    int idx, idy;
}ans[MAXN];
bool cmp(ANS x, ANS y){
    if(x.idx==y.idx) return x.idy<y.idy;
    return x.idx<y.idx;
}
 
int main(){
    while(~scanf("%d%d", &n, &m)){
        mp.clear();
        for(int i=0; i<m; i++){
            char x[12], y[12];
            scanf("%s%s", x, y);
            int s=abs(atoi(x)), t=abs(atoi(y));
            mp[s][t]=mp[t][s]=true;
            if(strlen(x)==strlen(y)){///ͬ��
                node[s].same.push_back(t);
                node[t].same.push_back(s);
            }
        }
        
        int k;
        scanf("%d", &k);
        while(k--){
            int s, t, cnt=0;
            scanf("%d%d", &s, &t);
            s=abs(s), t=abs(t);
            for(int i=0; i<node[s].same.size(); i++){///s��ʶ��ͬ��x
                for(int j=0; j<node[t].same.size(); j++){///t��ʶ��ͬ��y
                    int x=node[s].same[i], y=node[t].same[j];
                    if(x==t || s==y) continue;
                    if(mp[x][y]) ans[cnt].idx=x, ans[cnt++].idy=y;///�ж�x��y�Ƿ���ʶ
                }
            }
            sort(ans, ans+cnt, cmp);
            printf("%d\n", cnt);
            for(int i=0; i<cnt; i++) printf("%04d %04d\n", ans[i].idx, ans[i].idy);
        }
    }
    return 0;
}
