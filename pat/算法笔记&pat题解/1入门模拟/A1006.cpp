//耐心细致，仔细分析
//9:00-9:45  19/25
//    -10:45 AC
#include <stdio.h>
#include <stdlib.h>

/*
p1程序有错误，错误原因是：
	1.程序中按字节一个一个给每一个字符位置赋值，但是最后输出时是全部输出的
	比如先给id[1]赋值'abcdefg' ,第二次又按字节赋值给他'nnn' ，那么printf时会输出‘nnndefg’
	2.程序起初只给数组分配了15个空间，那么如果某个字符串就是十五个字符，那么他将不会有最后一个'\0'的结束符
	3.程序过于复杂庞大，看看怕p2是多么的清爽！！！结构体是直接可以赋值的！ 
*/
//#define p1
#ifdef p1
bool early(char t1[],char t2[]){	//如果t1比t2早，则返回true。时间格式为 HH:MM:SS共8位
	//从时分秒逐级比较，节约时间 
	int h1,h2;
	h1=(t1[0]-48)*10+(t1[1]-48);	//string->int
	h2=(t2[0]-48)*10+(t2[1]-48);
	if(h1 < h2)
		return true;
	else if(h1 > h2)
		return false;
	else{
		int m1,m2;
		m1=(t1[3]-48)*10+(t1[4]-48);
		m2=(t2[3]-48)*10+(t2[4]-48);
		if(m1 < m2)
			return true;
		else if(m1 > m2)
			return false;
		else{
			int s1,s2;
			s1=(t1[6]-48)*10+(t1[7]-48);
			s2=(t2[6]-48)*10+(t2[7]-48);
			if(s1 < s2)
				return true;
			else
				return false; 
		}
	}
}

int main(){
	int M;
	scanf("%d",&M);
	char s[4][20];		//s[1]是ID s[2]是进入时间 s[3]是出门时间
	char time[3][8];	//time[1]为当前最早进门时间，time[2]为当前最晚出门时间 
	char id[3][20];    //id[1]是最早进入的人的id,id[2]是最晚出去人的id 
	
	scanf("%s",s[1]);
	getchar();
	scanf("%s",s[2]);
	getchar();
	scanf("%s",s[3]);
	
	for(int i=0;i<15;i++)
		id[1][i]=id[2][i]=s[1][i];	//先把第一个输入作为最早进入和最晚离开 
		
	for(int i=0;i<8;i++){
		time[1][i]=s[2][i];
		time[2][i]=s[3][i];
	}
		
	for(int i=1;i<M;i++){
		scanf("%s",s[1]);
		getchar();
		scanf("%s",s[2]);
		getchar();
		scanf("%s",s[3]);
							//再次输入id,时间
		if(early(s[2],time[1])){	//如果输入的时间比当前最早进入时间还要早 
			for(int j=0;j<15;j++)	
				id[1][j]=s[1][j];	//则把更早的jd记录下来 
				
			for(int j=0;j<8;j++)	//则把更早的时间记录下来 
				time[1][j]=s[2][j]; 
		}
		
		if(early(time[2],s[3])){		//如果s[3]>tjme[2] ,即tjme[2]比刚输入的时间早 
			for(int j=0;j<15;j++)	
				id[2][j]=s[1][j];	//则把更晚的jd记录下来 
			for(int j=0;j<8;j++)	//则把更晚的时间记录下来 
				time[2][j]=s[3][j];
		} 	
	}
	
	printf("%s %s",id[1],id[2]); 

	return 0;
}
#endif

#define p2
#ifdef p2
//时间 HH:MM:SS读入可以 printf("%d:%d:%d",&hh,&mm,&ss); 

struct node{
	char id[20];
	int hh,mm,ss;	//ans1存放最早时间，ans2存放最晚时间 
}temp,ans1,ans2;

bool early(node node1,node node2){	//node1时间早于node2时间，返回true
	if(node1.hh != node2.hh)	return node1.hh < node2.hh;
	if(node1.mm != node2.mm)	return node1.mm < node2.mm;
	
	return node1.ss < node2.ss;	
} 

int main(){
	int n;
	scanf("%d",&n);
	ans1.hh=24;ans1.mm=60;ans1.ss=60;	//把初始进入时间设成最大
	ans2.hh=0 ;ans2.mm=0 ;ans2.ss=0 ; 	//把初始离开时间设为最小
	
	for(int i=0;i<n;i++){
		//先读入进入时间 
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		if(early(temp,ans1))
			ans1=temp;
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(early(ans2,temp))
			ans2=temp;		 
	} 
	printf("%s %s",ans1.id,ans2.id);
	return 0;
}

#endif
