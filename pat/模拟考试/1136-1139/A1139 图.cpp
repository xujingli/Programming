//日期：2018/ 时间：
//困难：1、不知道该怎么存储图。邻接表？邻接矩阵？
//		2、应该是使用深度优先搜索，如果深度为3找到另外节点，并且第一个节点是与A同性，第二个节点是与B同性。计数器加一，并且准备输出 
// 		3、2中所说的计数和 记录，以及排序输出。怎么控制？ 
/*
	我们先遍历A的所有相邻点B，排除性别与A不相同的。
	遍历A的每个相邻且性别相同的点时：
		再去遍历D的每个相邻且性别相同的点C
		然后判断B和C是否相邻，若相邻则符合要求。
注意点：
①存储并遍历相邻点时用邻接表
判断是否相邻用邻接矩阵。
但由于每个点的ID范围为0~9999，开不了那么大的数组
而点的数量最多只有300个
故应该设置序号数组，给每个ID做一个转换，能够转换到0~300间的序号。
②A的相邻点不能是D，D的相邻点不能是A，因为他们必须要经过2个人传递。
③查询时，A和D也是带正负的，也要处理
④会有‘-0000’存在的情况，所以应该先输入字符串，再转成数字ID。
⑤输出为4位digit，故输出时要补0
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
            if(strlen(x)==strlen(y)){///同性
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
            for(int i=0; i<node[s].same.size(); i++){///s认识的同性x
                for(int j=0; j<node[t].same.size(); j++){///t认识的同性y
                    int x=node[s].same[i], y=node[t].same[j];
                    if(x==t || s==y) continue;
                    if(mp[x][y]) ans[cnt].idx=x, ans[cnt++].idy=y;///判断x和y是否认识
                }
            }
            sort(ans, ans+cnt, cmp);
            printf("%d\n", cnt);
            for(int i=0; i<cnt; i++) printf("%04d %04d\n", ans[i].idx, ans[i].idy);
        }
    }
    return 0;
}
