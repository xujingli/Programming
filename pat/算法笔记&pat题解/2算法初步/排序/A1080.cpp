//日期：2018/5/2 时间：23:04- 

/*https://www.cnblogs.com/kl2blog/p/6908048.html
内存对齐的规则很简单：
　　1.起始地址为该变量类型所占内存的整数倍，若不足则不足部分用数据填充至所占内存的整数倍。
　　2.该结构体所占总内存为结构体成员变量中最大数据类型的整数倍

反思：此题建立在仔细分析的基础上，慢慢的就会越来越快，不要急，一切都会好起来的，相信自己，只要每天都努力，一定能提高 
另一个测试数据： 
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn=40010;
 
struct stu{
	int GE,GI,sum;
	int stuID;	//排名，学生编号 
	int cho[6];		//学校选择 
}studs[maxn];

int sch[101][maxn];	//每个学校的录取名单 .其中sch[i][0]记录第i个学校的实际录取人数（成绩相同会多录，所以此处处理是正确的）。 
					//从sch[][1]开始记录第i个学校录取的第1个人的编号 
void init(int M){	//初始化 
	for(int i=0;i<M;i++)
		sch[i][0]=0;
} 

bool cmp(stu a,stu b){
	if(a.sum != b.sum)	return a.sum>b.sum;
	else return a.GE > b.GE;
} 

int main(){
	int N,M,K;	//N个申请者。M个学校。K个申请选项 
	// N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; 
	//and K (<=5), the number of choices an applicant may have.
	scanf("%d%d%d",&N,&M,&K);
	init(M); 
	int num[101];	//M个学校，每个学校的名额 .num[0]表示第0个学校的名额 
	for(int i=0;i<M;i++)
		scanf("%d",&num[i]);
		
	//用一个学校数组记录下申请该学校学生的编号，以及数量  
	for(int i=0;i<N;i++){
		scanf("%d%d",&studs[i].GE,&studs[i].GI);
		studs[i].sum=(studs[i].GE+studs[i].GI)/2;	
		studs[i].stuID=i;
		for(int j=0;j<K;j++){ 
			scanf("%d",&studs[i].cho[j]);	//填报志愿 
		} 
	} 
	
	sort(studs,studs+N,cmp);		//按总分排序 
	//printf("%d\n",studs[2].GE); 
	//num[choice]表示choice学校剩余名额，不断减少。  
	//stu[i].cho[1,2---K-1]依次查看其申请的学校名额是否满了,
	for(int i=0;i<N;i++){	//遍历每一个申请者  
		for(int j=0;j<K;j++){	//遍历他的所有选项 
			int choice = studs[i].cho[j];	//第j个志愿，判断是否可以被录取
			if(num[choice]!=0){//申请的学校还有名额，或者和那个choice学校刚刚录取的最后一名 总分和GE分数相同。				
				//该学校还有名额，就把这个学生编号记录到对应的学校里，
				num[choice]--;
				sch[choice][0]++;
				sch[choice][sch[choice][0]]=studs[i].stuID;		//记录学生编号 
				break; 
			}
			if(num[choice]==0 && sch[choice][0]!=0 && (studs[sch[choice][sch[choice][0]]].sum==studs[i].sum && studs[i].GE==studs[sch[choice][sch[choice][0]]].GE )){
				//录取的第二种情况 
				sch[choice][0]++;
				sch[choice][sch[choice][0]]=studs[i].stuID;		//记录学生编号 
				break; 
			}
		} 
	} 
	
	for(int i=0;i<M;i++){
		sort(sch[i]+1,sch[i]+sch[i][0]+1);	//对每一行进行升序排列 
		//printf("%d: ",i);
		for(int j=1;j<=sch[i][0];j++){
			if(j == sch[i][0])
				printf("%d",sch[i][j]);
			else
				printf("%d ",sch[i][j]);
		} 
		printf("\n");
	}

	return 0;
}

