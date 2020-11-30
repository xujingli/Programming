//日期：2018/ 时间：12:25
//四舍五入：round(double a),返回int 
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 30010;

struct student{
	char id[25];
	double gp,gm,gf;
	int g;
}stu[maxn];

bool cmp(student a,student b){
	if(a.g == b.g){
		return strcmp(a.id,b.id) < 0;
	} return a.g > b.g; 
}

int main(){
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	
	for(int i=0;i<maxn;i++)
		stu[i].gm = stu[i].gp = stu[i].gf = stu[i].g = -1;
	
	int num=0;
	for(int i=0;i<p;i++){
		double gp;
		char name[25];
		scanf("%s %lf",name,&gp);
		strcpy(stu[num].id,name);
		stu[num++].gp = gp;
	}
	for(int i=0;i<m;i++){
		double gm;
		char name[25];
		scanf("%s %lf",name,&gm);
		int j;
		for(j=0;j<num;j++){
			if(strcmp(name,stu[j].id)==0){
				stu[j].gm = gm;
				break; 
			}
		}
		if(j == num){
			strcpy(stu[num].id,name);
			stu[num++].gm = gm;
		}
	}
	for(int i=0;i<n;i++){
		double gf;
		char name[25];
		scanf("%s %lf",name,&gf);
		int j;
		for(j=0;j<num;j++){
			if(strcmp(name,stu[j].id)==0){
				stu[j].gf = gf;
				if(stu[j].gm > stu[j].gf)
					stu[j].g = (int)round( (stu[j].gm*0.4 + stu[j].gf*0.6) ); 
				else{
					stu[j].g = (int)stu[j].gf;
				}
				break;
			}
		}
		if(j == num){
			strcpy(stu[num].id,name);
			stu[num++].gf = gf;
		}
	}
	//输入完毕
	
	sort(stu,stu+num,cmp);
	
	for(int i=0;i<num;i++){
		if(stu[i].gp >=200 && stu[i].g >=60){
			printf("%s %d %d %d %d\n",stu[i].id,(int)stu[i].gp,(int)stu[i].gm,(int)stu[i].gf,stu[i].g);
		}
	}


	return 0;
}

