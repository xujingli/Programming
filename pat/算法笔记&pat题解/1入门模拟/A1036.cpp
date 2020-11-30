//耐心细致，仔细分析
//10:45-11:08 AC

#include <stdio.h>
#include <stdlib.h>

struct stu{
	char name[15],gender,id[15];
	int grade;		//把最高分的女生保存在hgirl中，最低分的男生保存在lboy中 
}hgirl,lboy,temp; 

int main(){
	int n;
	scanf("%d",&n); 
	int flagG=0,flagB=0;	//用flag来标记以下是否输入男生或女生的数据。 
	hgirl.grade=-1;		//把女生最高分设置为-1
	lboy.grade=101;		//把男生最低分设置为101 
	
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.id,&temp.grade);
		if(temp.gender=='F'){	//当输入的是女生的信息时 
			flagG=1;	//先做个标记，表示已经有女生信息输入
			if(temp.grade > hgirl.grade)	//把最高分的女生信息保存起来 
				hgirl=temp; 
		}
		else if(temp.gender=='M'){
			flagB=1;
			if(temp.grade < lboy.grade)
				lboy=temp;
		}
	}
	
	if(flagG==0 || flagB==0){		//当没有男生信息或者没有女生信息时 
		if(flagG==0)
			printf("Absent\n");
		else
			printf("%s %s\n",hgirl.name,hgirl.id);
		
		if(flagB==0)
			printf("Absent\n");
		else
			printf("%s %s\n",lboy.name,lboy.id);
			
		printf("NA");
	} 
	else{							//当男女信息都有时 
		printf("%s %s\n",hgirl.name,hgirl.id);
		printf("%s %s\n",lboy.name,lboy.id);
		printf("%d",hgirl.grade-lboy.grade);
	} 

	return 0;
}

