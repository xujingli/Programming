//日期：2018/4/30 时间：13:47-
/*
重要警示：
	if(longer(records[j].time,records[j+1].time) >0)
	else if(longer(records[j].time,records[j+1].time) ==0)
	else if(longer(records[j].time,records[j+1].time) <0)
	如果第一个不满足，则进行第二个，第二个不满足，则进行第三个。但是if括号中的函数却运行了三次！！！！！ 
 本题中：the queries are given in ascending order of the times.这句话是重点。处理方法可以参考P125，否则复杂度高的可怕 
 
找错误时，多考虑边缘情况 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct car{
	char id[8];
	int hh,mm,ss;
	char status[4];
}records[100005],valid[100005];

bool cmp(car a,car b){
	if(strcmp(a.id,b.id) != 0)	return strcmp(a.id,b.id)<0;
	else {
		if(a.hh!=b.hh)	return a.hh<b.hh;
		else{
			if(a.mm!=b.mm)	return a.mm<b.mm;
			else{
				if(a.ss!=b.ss)	return a.ss<b.ss;
			}
		}
	}
}

bool cmp1(int a,int b){
	return a>=b;		//从大到小排序 
}

bool cmp2(car a,car b){		//按照时间排序 
	if(a.hh!=b.hh)	return a.hh<b.hh;
	else{
		if(a.mm!=b.mm)	return a.mm<b.mm;
		else{
			if(a.ss!=b.ss)	return a.ss<b.ss;
		}
	}
}

int t(int h1,int m1,int s1,int h2,int m2,int s2){	//t2-t1，相当于60进制数相减 
//	printf("t1:%d:%d:%d\n",h1,m1,s1);
//	printf("t2:%d:%d:%d\n",h2,m2,s2);
	int sec=0;
	if(s2 >= s1) sec+=(s2-s1);
	else{
		sec+=(60-s1+s2);	//向分钟借一位
		m2-=1;
	}
	if(m2>=m1)	sec+=((m2-m1)*60); 
	else{		//向小时借一位 
		sec+=((60-m1+m2)*60);
		h2-=1;
	}
	//小时数相减
	sec+=((h2-h1)*3600); 
	
//	printf("t2 - t1:%d:%d:%d\n",(sec/3600),(sec/60)%60,sec%60);
	return sec;
}

bool later(int h,int m,int s,int bh,int bm,int bs){//时刻t在bt之后或二者相等,返回true 
	if(h>bh) return true;
	else if(h==bh){
		if(m>bm) return true;
		else if(m==bm){
			if(s>=bs)	return true;
		}
	}
	return false;
}

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	//positive integers N (<= 10000), the number of records, and K (<= 80000) the number of queries
	for(int i=0;i<N;i++){
		scanf("%s %d:%d:%d %s",records[i].id,&records[i].hh,&records[i].mm,&records[i].ss,records[i].status);
	}
	
	sort(records,records+N,cmp);	//排序	
	//下面考虑匹配,把所有的匹配记录全部存放到valid中，valid按照时间排序 
	int num=0;		//车数。
	int flag=-1;		//用于匹配
	
	char tid[10005][8];	//存放所有的车牌号 
	int time[10005];	//存放该车对应的全部停放时间，以秒为单位。一共num辆车 
	char tempid[8];	//存放暂时的ID
	strcpy(tempid,records[0].id); 
	num++;
	strcpy(tid[num],tempid);	//存放车牌号。
	time[num]=0;		//初试化时间 
	
	int h,m,s;		//临时变量，用来计算时间 
	int validrec;	//用于暂存合法记录in的下标。 
	int recnum=0;		//合法的记录数 
	
	for(int i=0;i<N;i++){	//考虑匹配 
		if(strcmp(records[i].id,tempid)!=0){	//换了辆车的记录，则要增加车数、增加新的车牌号 
			flag=-1;
			num++;
			strcpy(tempid,records[i].id);	//更换临时变量 
			strcpy(tid[num],tempid);	//存放车牌号。
			time[num]=0;		//初始化总时间 
		} 
		
		if(strcmp(records[i].status,"in")==0){
			flag=0;
			h=records[i].hh; m= records[i].mm; s=records[i].ss;
			validrec=i;		//暂存合法记录的下标，如果和下一条out记录匹配，则要将此in存放到valid中 
		}
		if(strcmp(records[i].status,"out")==0 && flag==0){	//说明匹配成功 
			 flag=1;	//防止和下一条out发生匹配 
			 //存放上一条匹配的in记录到valid中，存放这个out记录到valid中，计算时间。
			 valid[recnum++]=records[validrec];	//上一条 
			 valid[recnum++]=records[i];		//这一条
			 //printf("num:%d\n",num);
			 time[num]+=t(h,m,s,records[i].hh,records[i].mm,records[i].ss); 
		}
	} 	
	
	//对valid数组进行排序，按照时间顺序。并设置此时的车辆数，从起始时刻到所要查询的时刻，in就加一，out就减一。建议写出来看看就明白了
	//题中说，查询的时刻是按照顺序给的，这就大大节约了复杂度。
	sort(valid,valid+recnum,cmp2);
	
/*	printf("\n\n"); 
	for(int i=0;i<recnum;i++)
	printf("%s %d:%d:%d %s\n",valid[i].id,valid[i].hh,valid[i].mm,valid[i].ss,valid[i].status);
	printf("\n"); 
*/	
	int now=0;			//记录当前有多少车。
	int cur=0;			//记录当前游标的位置，即：查询到的位置坐标 
	int bh=valid[cur].hh,bm=valid[cur].mm,bs=valid[cur].ss;	//起始时刻，以下为每一次查询的上一个最近时刻 
	for(int i=0;i<K;i++){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		
		while(later(h,m,s,bh,bm,bs)){	//当要查询的时刻t在bt之后或二者相等。则车辆数根据in或者out更新，并且更新bt 
			if(strcmp(valid[cur].status,"in")==0)
				now++;
			else
				now--;
			if(cur+1<recnum){
				cur++;		//查询游标加一
				bh=valid[cur].hh; bm=valid[cur].mm; bs=valid[cur].ss;
			}
			else
				break;
		} 
		printf("%d\n",now);
	}

	//以上是查询，以下是输出最大时长 
	int longest=0;		//最大时长 
	for(int i=1;i<=num;i++){
		if(time[i]>=longest)
			longest=time[i];
	}
	int c[10005];//存放停放最长时间车的下标。c[0]-c[numc-1]
	int numc=0; 	//停放最长时间的车辆数
	for(int i=1;i<=num;i++){	//统计停放最长时间的车辆数，及其下标 
		if(time[i]==longest){
			c[numc++]=i;
		}
	} 
	for(int i=0;i<numc;i++)
		printf("%s ",tid[c[i]]);
	printf("%02d:%02d:%02d",(longest/3600),(longest/60)%60,longest%60);
		
	return 0;
}
/*
*/ 
