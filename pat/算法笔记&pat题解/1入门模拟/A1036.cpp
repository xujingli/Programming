//����ϸ�£���ϸ����
//10:45-11:08 AC

#include <stdio.h>
#include <stdlib.h>

struct stu{
	char name[15],gender,id[15];
	int grade;		//����߷ֵ�Ů��������hgirl�У���ͷֵ�����������lboy�� 
}hgirl,lboy,temp; 

int main(){
	int n;
	scanf("%d",&n); 
	int flagG=0,flagB=0;	//��flag����������Ƿ�����������Ů�������ݡ� 
	hgirl.grade=-1;		//��Ů����߷�����Ϊ-1
	lboy.grade=101;		//��������ͷ�����Ϊ101 
	
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.id,&temp.grade);
		if(temp.gender=='F'){	//���������Ů������Ϣʱ 
			flagG=1;	//��������ǣ���ʾ�Ѿ���Ů����Ϣ����
			if(temp.grade > hgirl.grade)	//����߷ֵ�Ů����Ϣ�������� 
				hgirl=temp; 
		}
		else if(temp.gender=='M'){
			flagB=1;
			if(temp.grade < lboy.grade)
				lboy=temp;
		}
	}
	
	if(flagG==0 || flagB==0){		//��û��������Ϣ����û��Ů����Ϣʱ 
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
	else{							//����Ů��Ϣ����ʱ 
		printf("%s %s\n",hgirl.name,hgirl.id);
		printf("%s %s\n",lboy.name,lboy.id);
		printf("%d",hgirl.grade-lboy.grade);
	} 

	return 0;
}

