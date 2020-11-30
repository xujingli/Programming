//日期：2018/4/22 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct person{
	char ID_Number[9]; 
	int Virtue_Grade,Talent_Grade;
}man[4][100010];	//存放四类人 

bool cmp(person a,person b){
	if( (a.Talent_Grade+a.Virtue_Grade) == (b.Talent_Grade+b.Virtue_Grade)){
		if(a.Virtue_Grade == b.Virtue_Grade)
			return strcmp(a.ID_Number,b.ID_Number) <0;
		else
			return a.Virtue_Grade>b.Virtue_Grade;
	}
	else
		return (a.Talent_Grade+a.Virtue_Grade) > (b.Talent_Grade+b.Virtue_Grade);
}

int main(){
	int N,L,H;
	scanf("%d %d %d",&N,&L,&H);
	
	int snum=0,nnum=0,fnum=0,lnum=0;//分别代表sage人数，bnoble人数，foolman 人数，left人数 
	for(int i=0;i<N;i++){
		person temp; 
		scanf("%s %d %d",temp.ID_Number,&temp.Virtue_Grade,&temp.Talent_Grade);
		if(temp.Talent_Grade >= L && temp.Virtue_Grade >= L){
			if(temp.Talent_Grade>=H && temp.Virtue_Grade>=H)	//sage 
				man[0][snum++]=temp;
			else if(temp.Talent_Grade<H && temp.Virtue_Grade>=H)//noble man 
				man[1][nnum++]=temp;
			else if(temp.Talent_Grade<H && temp.Virtue_Grade<H && temp.Virtue_Grade >= temp.Talent_Grade)//fool man 
				man[2][fnum++]=temp;
			else 												//left man 
				man[3][lnum++]=temp; 
		}
		else
			continue;
	}
	
	sort(man[0],man[0]+snum,cmp);
	sort(man[1],man[1]+nnum,cmp);
	sort(man[2],man[2]+fnum,cmp);
	sort(man[3],man[3]+lnum,cmp);
	
	printf("%d\n",snum+nnum+lnum+fnum); 
	
	for(int i=0;i<snum;i++)
		printf("%s %d %d\n",man[0][i].ID_Number,man[0][i].Virtue_Grade,man[0][i].Talent_Grade);
	for(int i=0;i<nnum;i++)
		printf("%s %d %d\n",man[1][i].ID_Number,man[1][i].Virtue_Grade,man[1][i].Talent_Grade);
	for(int i=0;i<fnum;i++)
		printf("%s %d %d\n",man[2][i].ID_Number,man[2][i].Virtue_Grade,man[2][i].Talent_Grade);
	for(int i=0;i<lnum;i++){
		printf("%s %d %d\n",man[3][i].ID_Number,man[3][i].Virtue_Grade,man[3][i].Talent_Grade);
	}

	return 0;
}

