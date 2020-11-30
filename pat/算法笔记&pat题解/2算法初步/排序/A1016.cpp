//日期：2018/4/25 时间10:05- 11:23	完成了初试数据排序部分
//						11:23-14:14 15/25 报了段溢出和答案错误
//						14:14-14:31 寻找问题未果 
//					4/29 11:00-11:42 AC
//本题很难，前几天做的时候，花了40分钟理清头绪。结果还没有理清就已经丧失了信心
/*
AC心得：还是因为之前考虑不周全，count放在if语句中，如果要不进去，count不就不会加一了吗？
		所以把count放在每次循环的后面。每次后移一位 
*/ 
/*
本题花了4个小时，加上前几天花了40分钟，总共将近5个小时，仍然没有结果
总结原因：1.畏难，看到那么长的题目，那么复杂就畏惧。
			2.不认真，动笔演算的时候就不认真，写的乱七八糟，终于到达乱的没有思路的时候，又有另找一张纸，这就是浪费时间
			3.结构体排序，犯了一点小错误 。两个字符串相比较不能直接用"==",应该用strcmp(string1,string2)
			4. 编程功底薄弱，一个很简单的东西都要考虑好长时间，再加上用代码实现，要花很长时间。。。。急需要练习。
			5.编程一定要注意时间，逼着自己加快速度。不能信马由缰，思维周游列国
			6.你弱爆了！！！！！！！！！！！！！！！！！ 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct record{
	char name[21];
	char mon[3],day[3],hour[3],min[3],word[10];
	char dt[12];	//date and time.0 1 为月份，3 4为日子 6 7 为小时 9 10为分钟 
}records[1005];

bool cmp(record a,record b){
	//if(a.name == b.name){		//草你妈的，你死去吧，到这种程度，还犯这种低级错误！！！！！！！！！！！！！！！！！！让我找了大概40分钟错误，还以为自己哪里逻辑写错了！！！你到底干什么，你想死吗？就你这样还考浙大？？？？？？？要你干什么呢？
 	if(strcmp(a.name,b.name)== 0 ){
		if(strcmp(a.day,b.day)==0){//相同日期
			if(strcmp(a.hour,b.hour)==0){
				return strcmp(a.min,b.min)<0;
			} else
				return strcmp(a.hour,b.hour)<0;	//按照时间顺序，升序排列 
		}else
			return strcmp(a.day,b.day)<0;		//日期顺序升序排列 ，因为题目中已经假设了，每个记录都是同一个月的，所以不用对月份排序 
	}else
		return strcmp(a.name,b.name)<0;		//按照字典序升序排列 
}

int toll[25];		//各个时间段的费用，设成全局变量 ,toll[24]存放前面24个之和 

int t(int d1,int h1,int m1,int d2,int h2,int m2){	//计算在d1:h1:m1 - d2:h2:m2的费用，根据各个时间段的费用 
	int total=0;
	//printf("\n%d:%d  %d:%d\n",h1,m1,h2,m2);
	if(d1==d2){				//相同的一天 
		if(h1==h2){
			total=toll[h1]*(m2-m1);
		}else{
			for(int i=h1;i<=h2;i++){
				if(i==h1)
					total+=toll[i]*(60-m1);
				else if(i==h2)
					total+=toll[i]*m2;
				else
					total+=60*toll[i];
			}
		}
		return total;
	} 
	
	return t(d1,h1,m1,d1,23,60)+t(d2,0,0,d2,h2,m2)+(d2-d1-1)*(60*toll[24]);		//不同天，计算第一天+第n天+隔了几天 
}

int m(int d1,int h1,int m1,int d2,int h2,int m2){	//计算在d1:h1:m1 - d2:h2:m2的总的分钟 
	//printf("%d\n",60-m1+(h2-h1-1)*60+m2); 
	if(d1==d2)
		return 60-m1+(h2-h1-1)*60+m2; 
	else{											//此处用到递归的思想！很好 
		return m(d1,h1,m1,d1,23,60)+m(d2,0,0,d2,h2,m2)+(d2-d1-1)*(60*24);
	}
}

int main(){	
	toll[24]=0;				//toll[24]存放总费用 
	for(int i=0;i<24;i++){	//每个时间段的费用，0:00-1:00的费用为toll[o]。23:00-0:00的费用为toll[23] 
		scanf("%d",&toll[i]);
		toll[24]+=toll[i]; 
	}		
	
	int N;			//N<=1000
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %s %s",records[i].name,records[i].dt,records[i].word);
		records[i].mon[0]=records[i].dt[0];
		records[i].mon[1]=records[i].dt[1];
		
		records[i].day[0]=records[i].dt[3];
		records[i].day[1]=records[i].dt[4];
		
		records[i].hour[0]=records[i].dt[6];
		records[i].hour[1]=records[i].dt[7];
		
		records[i].min[0]=records[i].dt[9];
		records[i].min[1]=records[i].dt[10];
	}
	
	sort(records,records+N,cmp);			//对输入的数据进行排序 
	
	//以下先得到有多少个人，每个人有多少条记录 
	int num=0;		//不同的人数
	int nr[1005];	//每个人的含有多少条记录。0-num-1 记录
	memset(nr,0,sizeof(int)*1005); 
	char temp[21];
	strcpy(temp,records[0].name);
	nr[num]++;		// 不同的人数加一，记录数加一 
	for(int i=1;i<N;i++){
		if(strcmp(temp,records[i].name) ==0 ){
			nr[num]++;			//如果姓名相同，增加记录数 
		}
		else{ 
			nr[++num]++;		//如果姓名不同，增加人数，也增加记录数 
			strcpy(temp,records[i].name);//更新temp 
		} 
	} 
	num++;			//总人数加一，因为上面少加了1 
	
	//以下输出 
	int count=0;	//控制指针一个一个往后移动，遍历所有记录 
	for(int i=0;i<num;i++){
		int flag=1;		//用来寻找配对的电话记录 
		int totaltoll=0;	//每一个人的总费用。 
		
		int k=0;		//用来控制“第一次有配对的电话记录时，输出姓名和月份”，也保证了“不存在有效通话记录的人不会被输出” 
		//printf("nr[i]:%d");
		for(int j=0;j<nr[i];j++){
			//printf("count:%d\n",count);
			if(strcmp(records[count].word,"on-line")==0){ 
				//printf("count:%d\n",count); 
				//count++; 
				flag=0;
			} 
			else if(strcmp(records[count].word,"off-line")==0 && flag==0){				
				if(k==0){
					printf("%s %s\n",records[count].name,records[count].mon);
					k++;
				}
				//count++;
				flag=1;
				
				printf("%s:%s:%s %s:%s:%s ",records[count-1].day,records[count-1].hour,records[count-1].min,records[count].day,records[count].hour,records[count].min);
				int d1,h1,m1,d2,h2,m2;	//d1:h1:m1  d2:h2:m2  转换成int型 
				d1= (records[count-1].day[1]-48)+(records[count-1].day[0]-48)*10;
				h1= (records[count-1].hour[1]-48)+(records[count-1].hour[0]-48)*10;
				m1= (records[count-1].min[1]-48)+(records[count-1].min[0]-48)*10;
				d2= (records[count].day[1]-48)+(records[count].day[0]-48)*10;
				h2= (records[count].hour[1]-48)+(records[count].hour[0]-48)*10;
				m2= (records[count].min[1]-48)+(records[count].min[0]-48)*10;
				//printf("\n%d:%d  %d:%d\n",h1,m1,h2,m2);
				int mins=m(d1,h1,m1,d2,h2,m2);			//计算总的时间 
				int tolls=t(d1,h1,m1,d2,h2,m2);			//计算总费用
				totaltoll+=tolls;
				printf("%d $%.2f\n",mins,tolls/100.0);
			} 
			count++;//指针后移一位 
		} 
		//输出这个人的总费用
		if(totaltoll!=0)
			printf("Total amount: $%.2f\n",totaltoll/100.0); 
	}
	/* 
	printf("\n");
	for(int i=0;i<N;i++){
		printf("%s %s:%s:%s:%s %s\n",records[i].name,records[i].mon,records[i].day,records[i].hour,records[i].min,records[i].word);
	}
	printf("%d\n",num); 
	for(int i=0;i<num;i++)
		printf("%d\n",nr[i]);
	*/
	return 0;
}
