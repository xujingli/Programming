//日期：2018/ 时间：
//启示： 一定要把double数留到最后一步算，否则就会发生精度错误 

#define p2

#ifdef p2
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int n;

struct inf{
	char id[8];
	int score;
	char sch[8];
}stu[maxn];

struct school{
	char sch[8];
	int rank;
	int tws;
	int score[3];
	int ns;
}u[maxn];

bool cmp1(inf a,inf b){				//学校名称排序 
	return strcmp(a.sch,b.sch) < 0;
}

bool cmp2(school a,school b){
	if(a.tws == b.tws){
		if(a.ns == b.ns){
			return strcmp(a.sch,b.sch) < 0;
		} else 
			return a.ns < b.ns;
	} else
		return a.tws > b.tws;
	
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%s %d %s",stu[i].id,&stu[i].score,stu[i].sch);
		int len=strlen(stu[i].sch);
		for(int j=0;j<len;j++){
			if(stu[i].sch[j] >='A' && stu[i].sch[j] <='Z'){
				stu[i].sch[j] = stu[i].sch[j] - 'A' + 'a';
			}
		}
	}
	sort(stu,stu+n,cmp1);
	
	for(int i=0;i<maxn;i++){
		u[i].tws = 0;
		u[i].ns = 0;
		u[i].score[0]=u[i].score[1]=u[i].score[2]=0;
	}
	
	int num = 0;				//学校数量 
	strcpy(u[0].sch,stu[0].sch);
	u[0].ns++; 
	if(stu[0].id[0] == 'A') u[0].score[1] += stu[0].score;
	else if(stu[0].id[0] == 'B') u[0].score[0] += stu[0].score;
	else if(stu[0].id[0] == 'T') u[0].score[2] += stu[0].score;
	
	for(int i=1;i<n;i++){
		if(strcmp(stu[i-1].sch,stu[i].sch) != 0){	//学校不同 
			u[num].tws = (int)(u[num].score[0]*1.0/1.5 + u[num].score[1]*1.0 + u[num].score[2]*1.5);
			num++;
			strcpy(u[num].sch,stu[i].sch);
		}
		
		u[num].ns++;
		if(stu[i].id[0] == 'A') u[num].score[1] += stu[i].score;
		else if(stu[i].id[0] == 'B') u[num].score[0] += stu[i].score;
		else if(stu[i].id[0] == 'T') u[num].score[2] += stu[i].score;
	}
	u[num].tws = (int)(u[num].score[0]*1.0/1.5 + u[num].score[1]*1.0 + u[num].score[2]*1.5);
	num++;
	
	sort(u,u+num,cmp2);
	
	u[0].rank = 1;
	for(int i=1;i<num;i++){
		if(u[i].tws == u[i-1].tws)
			u[i].rank = u[i-1].rank;
		else{
			u[i].rank = i+1; 
		}
	}
	
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%d %s %d %d\n",u[i].rank,u[i].sch,(int)u[i].tws,u[i].ns);
	}

	return 0;
}

/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
*/

#endif


#ifdef p1
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int n;

struct inf{
	char id[8];
	int score;
	char sch[8];
}stu[maxn];

struct school{
	char sch[8];
	int rank;
	int tws;
	int ns;
}u[maxn];

bool cmp1(inf a,inf b){				//学校名称排序 
	return strcmp(a.sch,b.sch) < 0;
}

bool cmp2(school a,school b){
	if(a.tws == b.tws){
		if(a.ns == b.ns){
			return strcmp(a.sch,b.sch) < 0;
		} else 
			return a.ns < b.ns;
	} else
		return a.tws > b.tws;
	
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%s %d %s",stu[i].id,&stu[i].score,stu[i].sch);
		int len=strlen(stu[i].sch);
		for(int j=0;j<len;j++){
			if(stu[i].sch[j] >='A' && stu[i].sch[j] <='Z'){
				stu[i].sch[j] = stu[i].sch[j] - 'A' + 'a';
			}
		}
	}
	sort(stu,stu+n,cmp1);
	
	for(int i=0;i<maxn;i++){
		u[i].tws = 0;
		u[i].ns = 0;
	}
	
	int num = 0;				//学校数量 
	strcpy(u[0].sch,stu[0].sch);
	u[0].ns++; 
	if(stu[0].id[0] == 'A') u[0].tws += (int)stu[0].score;
	else if(stu[0].id[0] == 'B') u[0].tws += (int)(stu[0].score/1.5);
	else if(stu[0].id[0] == 'T') u[0].tws += (int)(stu[0].score*1.5);
	
	for(int i=1;i<n;i++){
		if(strcmp(stu[i-1].sch,stu[i].sch) != 0){	//学校不同 
			num++;
			strcpy(u[num].sch,stu[i].sch);
		}
		
		u[num].ns++;
		if(stu[i].id[0] == 'A') u[num].tws += (int)stu[i].score;
		else if(stu[i].id[0] == 'B') u[num].tws += (int)(stu[i].score/1.5);
		else if(stu[i].id[0] == 'T') u[num].tws += (int)(stu[i].score*1.5);
	}
	num++;
	
	sort(u,u+num,cmp2);
	
	u[0].rank = 1;
	for(int i=1;i<num;i++){
		if(u[i].tws == u[i-1].tws)
			u[i].rank = u[i-1].rank;
		else{
			u[i].rank = i+1; 
		}
	}
	
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%d %s %d %d\n",u[i].rank,u[i].sch,(int)u[i].tws,u[i].ns);
	}

	return 0;
}
#endif
/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
*/
